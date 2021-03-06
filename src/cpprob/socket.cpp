#include "cpprob/socket.hpp"

#include <algorithm>                          // for transform
#include <cstdint>                            // for int32_t
#include <exception>                          // for terminate
#include <fstream>                            // for operator<<, ofstream
#include <iostream>                           // for cerr, ios_base::failure
#include <iterator>                           // for back_insert_iterator
#include <limits>                             // for numeric_limits, numeric...
#include <string>                             // for string, operator+, allo...
#include <type_traits>                        // for __decay_and_strip<>::__...

#include <boost/detail/basic_pointerbuf.hpp>  // for basic_pointerbuf<>::pos...
#include <boost/lexical_cast.hpp>             // for lexical_cast
#include <boost/uuid/random_generator.hpp>    // for basic_random_generator
#include <boost/uuid/uuid.hpp>                // for uuid
#include <boost/uuid/uuid_io.hpp>             // for operator<<
#include <zmq.h>                              // for ZMQ_REP, ZMQ_REQ

#include "cpprob/trace.hpp"                   // for TraceCompile
#include "cpprob/serialization.hpp"           // for operator<<
#include "flatbuffers/infcomp_generated.h"    // for CreateMessage, GetMessage

namespace cpprob {


////////////////////////////////////////////////////////////////////////////////
/////////////////////////        Compilation            ////////////////////////
////////////////////////////////////////////////////////////////////////////////
static zmq::context_t context (1);

// Static data
zmq::socket_t SocketCompile::server_ (context, ZMQ_REP);
std::string SocketCompile::dump_folder_;

void SocketCompile::connect_server(const std::string & tcp_addr)
{
    server_.bind(tcp_addr.c_str());
    dump_folder_.clear();
}

void SocketCompile::config_file(const std::string & dump_folder)
{
    dump_folder_ = dump_folder;
}

int SocketCompile::get_batch_size()
{
    zmq::message_t request;
    server_.recv(&request);

    auto message = protocol::GetMessage(request.data());

    auto request_traces = message->body_as_RequestTraces();
    if (request_traces == nullptr) {
        auto request_finish = message->body_as_RequestFinishCompilation();
        if (request_finish == nullptr) {
            throw std::runtime_error("Message received is not a a RequestTraces or a RequestFinishCompilation");
        }
        return -1;
    }

    return request_traces->num_traces();
}

void SocketCompile::send_finish_compilation()
{

    flatbuffers::FlatBufferBuilder buff;
    auto msg = protocol::CreateMessage(
            buff,
            protocol::MessageBody::ReplyFinishCompilation);
    buff.Finish(msg);
    zmq::message_t request (buff.GetSize());
    memcpy(request.data(), buff.GetBufferPointer(), buff.GetSize());
    server_.send(request);
}

void SocketCompile::send_batch(const flatbuffers::FlatBufferBuilder & buff)
{
    if (!dump_folder_.empty()) {
        static auto rand_gen {boost::uuids::random_generator()};

        // We already know that dump_folder exists
        auto file_name = dump_folder_ + "/" + boost::lexical_cast<std::string>(rand_gen());
        auto file = std::ofstream(file_name, std::ofstream::binary);
        if (!file.is_open()) {
            std::cerr << "File \"" << file_name << "\" could not be open.\n";
            std::terminate();
        }
        file.write(reinterpret_cast<char *>(buff.GetBufferPointer()), buff.GetSize());
    }
    else {
        zmq::message_t reply(buff.GetSize());
        memcpy(reply.data(), buff.GetBufferPointer(), buff.GetSize());
        server_.send(reply);
    }
}
////////////////////////////////////////////////////////////////////////////////
/////////////////////////          Inference            ////////////////////////
////////////////////////////////////////////////////////////////////////////////

zmq::socket_t SocketInfer::client_ (context, ZMQ_REQ);

void SocketInfer::connect_client(const std::string& tcp_addr)
{
    client_.connect(tcp_addr.c_str());
}

void SocketInfer::send_start_inference(const flatbuffers::FlatBufferBuilder & buff) {
    zmq::message_t request (buff.GetSize());
    memcpy(request.data(), buff.GetBufferPointer(), buff.GetSize());
    client_.send(request);

    zmq::message_t reply;
    client_.recv (&reply);
    auto message = protocol::GetMessage(reply.data());
    if (message->body_as_ReplyStartInference() == nullptr) {
        throw std::runtime_error("Message received is not a a ReplyStartInference");
    }
}

void SocketInfer::send_finish_inference() {
    flatbuffers::FlatBufferBuilder buff;
    auto msg = protocol::CreateMessage(
            buff,
            protocol::MessageBody::RequestFinishInference);
    buff.Finish(msg);
    zmq::message_t request (buff.GetSize());
    memcpy(request.data(), buff.GetBufferPointer(), buff.GetSize());
    client_.send(request);

    zmq::message_t reply;
    client_.recv (&reply);
    auto message = protocol::GetMessage(reply.data());
    if (message->body_as_ReplyFinishInference() == nullptr) {
        throw std::runtime_error("Message received is not a a ReplyFinishInference");
    }
}


}  // namespace cpprob
