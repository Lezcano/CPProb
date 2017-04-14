// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_INFCOMP_INFCOMP_H_
#define FLATBUFFERS_GENERATED_INFCOMP_INFCOMP_H_

#include "flatbuffers/flatbuffers.h"

namespace infcomp {

struct Message;

struct NDArray;

struct CategoricalProposal;

struct DiscreteProposal;

struct FlipProposal;

struct NormalProposal;

struct UniformDiscreteProposal;

struct Sample;

struct Trace;

struct TracesFromPriorRequest;

struct TracesFromPriorReply;

struct ObservesInitRequest;

struct ObservesInitReply;

struct ProposalRequest;

struct ProposalReply;

enum MessageBody {
  MessageBody_NONE = 0,
  MessageBody_TracesFromPriorRequest = 1,
  MessageBody_ObservesInitRequest = 2,
  MessageBody_ProposalRequest = 3,
  MessageBody_TracesFromPriorReply = 4,
  MessageBody_ObservesInitReply = 5,
  MessageBody_ProposalReply = 6,
  MessageBody_MIN = MessageBody_NONE,
  MessageBody_MAX = MessageBody_ProposalReply
};

inline const char **EnumNamesMessageBody() {
  static const char *names[] = {
    "NONE",
    "TracesFromPriorRequest",
    "ObservesInitRequest",
    "ProposalRequest",
    "TracesFromPriorReply",
    "ObservesInitReply",
    "ProposalReply",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessageBody(MessageBody e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesMessageBody()[index];
}

template<typename T> struct MessageBodyTraits {
  static const MessageBody enum_value = MessageBody_NONE;
};

template<> struct MessageBodyTraits<TracesFromPriorRequest> {
  static const MessageBody enum_value = MessageBody_TracesFromPriorRequest;
};

template<> struct MessageBodyTraits<ObservesInitRequest> {
  static const MessageBody enum_value = MessageBody_ObservesInitRequest;
};

template<> struct MessageBodyTraits<ProposalRequest> {
  static const MessageBody enum_value = MessageBody_ProposalRequest;
};

template<> struct MessageBodyTraits<TracesFromPriorReply> {
  static const MessageBody enum_value = MessageBody_TracesFromPriorReply;
};

template<> struct MessageBodyTraits<ObservesInitReply> {
  static const MessageBody enum_value = MessageBody_ObservesInitReply;
};

template<> struct MessageBodyTraits<ProposalReply> {
  static const MessageBody enum_value = MessageBody_ProposalReply;
};

bool VerifyMessageBody(flatbuffers::Verifier &verifier, const void *obj, MessageBody type);
bool VerifyMessageBodyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

enum ProposalDistribution {
  ProposalDistribution_NONE = 0,
  ProposalDistribution_CategoricalProposal = 1,
  ProposalDistribution_DiscreteProposal = 2,
  ProposalDistribution_FlipProposal = 3,
  ProposalDistribution_NormalProposal = 4,
  ProposalDistribution_UniformDiscreteProposal = 5,
  ProposalDistribution_MIN = ProposalDistribution_NONE,
  ProposalDistribution_MAX = ProposalDistribution_UniformDiscreteProposal
};

inline const char **EnumNamesProposalDistribution() {
  static const char *names[] = {
    "NONE",
    "CategoricalProposal",
    "DiscreteProposal",
    "FlipProposal",
    "NormalProposal",
    "UniformDiscreteProposal",
    nullptr
  };
  return names;
}

inline const char *EnumNameProposalDistribution(ProposalDistribution e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesProposalDistribution()[index];
}

template<typename T> struct ProposalDistributionTraits {
  static const ProposalDistribution enum_value = ProposalDistribution_NONE;
};

template<> struct ProposalDistributionTraits<CategoricalProposal> {
  static const ProposalDistribution enum_value = ProposalDistribution_CategoricalProposal;
};

template<> struct ProposalDistributionTraits<DiscreteProposal> {
  static const ProposalDistribution enum_value = ProposalDistribution_DiscreteProposal;
};

template<> struct ProposalDistributionTraits<FlipProposal> {
  static const ProposalDistribution enum_value = ProposalDistribution_FlipProposal;
};

template<> struct ProposalDistributionTraits<NormalProposal> {
  static const ProposalDistribution enum_value = ProposalDistribution_NormalProposal;
};

template<> struct ProposalDistributionTraits<UniformDiscreteProposal> {
  static const ProposalDistribution enum_value = ProposalDistribution_UniformDiscreteProposal;
};

bool VerifyProposalDistribution(flatbuffers::Verifier &verifier, const void *obj, ProposalDistribution type);
bool VerifyProposalDistributionVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Message FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_BODY_TYPE = 4,
    VT_BODY = 6
  };
  MessageBody body_type() const {
    return static_cast<MessageBody>(GetField<uint8_t>(VT_BODY_TYPE, 0));
  }
  const void *body() const {
    return GetPointer<const void *>(VT_BODY);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_BODY_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_BODY) &&
           VerifyMessageBody(verifier, body(), body_type()) &&
           verifier.EndTable();
  }
};

struct MessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_body_type(MessageBody body_type) {
    fbb_.AddElement<uint8_t>(Message::VT_BODY_TYPE, static_cast<uint8_t>(body_type), 0);
  }
  void add_body(flatbuffers::Offset<void> body) {
    fbb_.AddOffset(Message::VT_BODY, body);
  }
  MessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MessageBuilder &operator=(const MessageBuilder &);
  flatbuffers::Offset<Message> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Message>(end);
    return o;
  }
};

inline flatbuffers::Offset<Message> CreateMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    MessageBody body_type = MessageBody_NONE,
    flatbuffers::Offset<void> body = 0) {
  MessageBuilder builder_(_fbb);
  builder_.add_body(body);
  builder_.add_body_type(body_type);
  return builder_.Finish();
}

struct NDArray FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_DATA = 4,
    VT_SHAPE = 6
  };
  const flatbuffers::Vector<double> *data() const {
    return GetPointer<const flatbuffers::Vector<double> *>(VT_DATA);
  }
  const flatbuffers::Vector<int32_t> *shape() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_SHAPE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_DATA) &&
           verifier.Verify(data()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHAPE) &&
           verifier.Verify(shape()) &&
           verifier.EndTable();
  }
};

struct NDArrayBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_data(flatbuffers::Offset<flatbuffers::Vector<double>> data) {
    fbb_.AddOffset(NDArray::VT_DATA, data);
  }
  void add_shape(flatbuffers::Offset<flatbuffers::Vector<int32_t>> shape) {
    fbb_.AddOffset(NDArray::VT_SHAPE, shape);
  }
  NDArrayBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NDArrayBuilder &operator=(const NDArrayBuilder &);
  flatbuffers::Offset<NDArray> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<NDArray>(end);
    return o;
  }
};

inline flatbuffers::Offset<NDArray> CreateNDArray(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<double>> data = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> shape = 0) {
  NDArrayBuilder builder_(_fbb);
  builder_.add_shape(shape);
  builder_.add_data(data);
  return builder_.Finish();
}

inline flatbuffers::Offset<NDArray> CreateNDArrayDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<double> *data = nullptr,
    const std::vector<int32_t> *shape = nullptr) {
  return infcomp::CreateNDArray(
      _fbb,
      data ? _fbb.CreateVector<double>(*data) : 0,
      shape ? _fbb.CreateVector<int32_t>(*shape) : 0);
}

struct CategoricalProposal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SIZE = 4,
    VT_PROBABILITIES = 6
  };
  int32_t size() const {
    return GetField<int32_t>(VT_SIZE, 0);
  }
  const NDArray *probabilities() const {
    return GetPointer<const NDArray *>(VT_PROBABILITIES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_SIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROBABILITIES) &&
           verifier.VerifyTable(probabilities()) &&
           verifier.EndTable();
  }
};

struct CategoricalProposalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_size(int32_t size) {
    fbb_.AddElement<int32_t>(CategoricalProposal::VT_SIZE, size, 0);
  }
  void add_probabilities(flatbuffers::Offset<NDArray> probabilities) {
    fbb_.AddOffset(CategoricalProposal::VT_PROBABILITIES, probabilities);
  }
  CategoricalProposalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CategoricalProposalBuilder &operator=(const CategoricalProposalBuilder &);
  flatbuffers::Offset<CategoricalProposal> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<CategoricalProposal>(end);
    return o;
  }
};

inline flatbuffers::Offset<CategoricalProposal> CreateCategoricalProposal(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t size = 0,
    flatbuffers::Offset<NDArray> probabilities = 0) {
  CategoricalProposalBuilder builder_(_fbb);
  builder_.add_probabilities(probabilities);
  builder_.add_size(size);
  return builder_.Finish();
}

struct DiscreteProposal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SIZE = 4,
    VT_PROBABILITIES = 6
  };
  int32_t size() const {
    return GetField<int32_t>(VT_SIZE, 0);
  }
  const NDArray *probabilities() const {
    return GetPointer<const NDArray *>(VT_PROBABILITIES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_SIZE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROBABILITIES) &&
           verifier.VerifyTable(probabilities()) &&
           verifier.EndTable();
  }
};

struct DiscreteProposalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_size(int32_t size) {
    fbb_.AddElement<int32_t>(DiscreteProposal::VT_SIZE, size, 0);
  }
  void add_probabilities(flatbuffers::Offset<NDArray> probabilities) {
    fbb_.AddOffset(DiscreteProposal::VT_PROBABILITIES, probabilities);
  }
  DiscreteProposalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DiscreteProposalBuilder &operator=(const DiscreteProposalBuilder &);
  flatbuffers::Offset<DiscreteProposal> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<DiscreteProposal>(end);
    return o;
  }
};

inline flatbuffers::Offset<DiscreteProposal> CreateDiscreteProposal(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t size = 0,
    flatbuffers::Offset<NDArray> probabilities = 0) {
  DiscreteProposalBuilder builder_(_fbb);
  builder_.add_probabilities(probabilities);
  builder_.add_size(size);
  return builder_.Finish();
}

struct FlipProposal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PROBABILITY = 4
  };
  double probability() const {
    return GetField<double>(VT_PROBABILITY, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_PROBABILITY) &&
           verifier.EndTable();
  }
};

struct FlipProposalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_probability(double probability) {
    fbb_.AddElement<double>(FlipProposal::VT_PROBABILITY, probability, 0.0);
  }
  FlipProposalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  FlipProposalBuilder &operator=(const FlipProposalBuilder &);
  flatbuffers::Offset<FlipProposal> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<FlipProposal>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlipProposal> CreateFlipProposal(
    flatbuffers::FlatBufferBuilder &_fbb,
    double probability = 0.0) {
  FlipProposalBuilder builder_(_fbb);
  builder_.add_probability(probability);
  return builder_.Finish();
}

struct NormalProposal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MEAN = 4,
    VT_STD = 6
  };
  double mean() const {
    return GetField<double>(VT_MEAN, 0.0);
  }
  double std() const {
    return GetField<double>(VT_STD, 0.0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<double>(verifier, VT_MEAN) &&
           VerifyField<double>(verifier, VT_STD) &&
           verifier.EndTable();
  }
};

struct NormalProposalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_mean(double mean) {
    fbb_.AddElement<double>(NormalProposal::VT_MEAN, mean, 0.0);
  }
  void add_std(double std) {
    fbb_.AddElement<double>(NormalProposal::VT_STD, std, 0.0);
  }
  NormalProposalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NormalProposalBuilder &operator=(const NormalProposalBuilder &);
  flatbuffers::Offset<NormalProposal> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<NormalProposal>(end);
    return o;
  }
};

inline flatbuffers::Offset<NormalProposal> CreateNormalProposal(
    flatbuffers::FlatBufferBuilder &_fbb,
    double mean = 0.0,
    double std = 0.0) {
  NormalProposalBuilder builder_(_fbb);
  builder_.add_std(std);
  builder_.add_mean(mean);
  return builder_.Finish();
}

struct UniformDiscreteProposal FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MIN = 4,
    VT_MAX = 6,
    VT_PROBABILITIES = 8
  };
  int32_t min() const {
    return GetField<int32_t>(VT_MIN, 0);
  }
  int32_t max() const {
    return GetField<int32_t>(VT_MAX, 0);
  }
  const NDArray *probabilities() const {
    return GetPointer<const NDArray *>(VT_PROBABILITIES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_MIN) &&
           VerifyField<int32_t>(verifier, VT_MAX) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROBABILITIES) &&
           verifier.VerifyTable(probabilities()) &&
           verifier.EndTable();
  }
};

struct UniformDiscreteProposalBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_min(int32_t min) {
    fbb_.AddElement<int32_t>(UniformDiscreteProposal::VT_MIN, min, 0);
  }
  void add_max(int32_t max) {
    fbb_.AddElement<int32_t>(UniformDiscreteProposal::VT_MAX, max, 0);
  }
  void add_probabilities(flatbuffers::Offset<NDArray> probabilities) {
    fbb_.AddOffset(UniformDiscreteProposal::VT_PROBABILITIES, probabilities);
  }
  UniformDiscreteProposalBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  UniformDiscreteProposalBuilder &operator=(const UniformDiscreteProposalBuilder &);
  flatbuffers::Offset<UniformDiscreteProposal> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<UniformDiscreteProposal>(end);
    return o;
  }
};

inline flatbuffers::Offset<UniformDiscreteProposal> CreateUniformDiscreteProposal(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t min = 0,
    int32_t max = 0,
    flatbuffers::Offset<NDArray> probabilities = 0) {
  UniformDiscreteProposalBuilder builder_(_fbb);
  builder_.add_probabilities(probabilities);
  builder_.add_max(max);
  builder_.add_min(min);
  return builder_.Finish();
}

struct Sample FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TIME = 4,
    VT_ADDRESS = 6,
    VT_INSTANCE = 8,
    VT_PROPOSAL_TYPE = 10,
    VT_PROPOSAL = 12,
    VT_VALUE = 14
  };
  int32_t time() const {
    return GetField<int32_t>(VT_TIME, 0);
  }
  const flatbuffers::String *address() const {
    return GetPointer<const flatbuffers::String *>(VT_ADDRESS);
  }
  int32_t instance() const {
    return GetField<int32_t>(VT_INSTANCE, 0);
  }
  ProposalDistribution proposal_type() const {
    return static_cast<ProposalDistribution>(GetField<uint8_t>(VT_PROPOSAL_TYPE, 0));
  }
  const void *proposal() const {
    return GetPointer<const void *>(VT_PROPOSAL);
  }
  const NDArray *value() const {
    return GetPointer<const NDArray *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_TIME) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_ADDRESS) &&
           verifier.Verify(address()) &&
           VerifyField<int32_t>(verifier, VT_INSTANCE) &&
           VerifyField<uint8_t>(verifier, VT_PROPOSAL_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROPOSAL) &&
           VerifyProposalDistribution(verifier, proposal(), proposal_type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUE) &&
           verifier.VerifyTable(value()) &&
           verifier.EndTable();
  }
};

struct SampleBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_time(int32_t time) {
    fbb_.AddElement<int32_t>(Sample::VT_TIME, time, 0);
  }
  void add_address(flatbuffers::Offset<flatbuffers::String> address) {
    fbb_.AddOffset(Sample::VT_ADDRESS, address);
  }
  void add_instance(int32_t instance) {
    fbb_.AddElement<int32_t>(Sample::VT_INSTANCE, instance, 0);
  }
  void add_proposal_type(ProposalDistribution proposal_type) {
    fbb_.AddElement<uint8_t>(Sample::VT_PROPOSAL_TYPE, static_cast<uint8_t>(proposal_type), 0);
  }
  void add_proposal(flatbuffers::Offset<void> proposal) {
    fbb_.AddOffset(Sample::VT_PROPOSAL, proposal);
  }
  void add_value(flatbuffers::Offset<NDArray> value) {
    fbb_.AddOffset(Sample::VT_VALUE, value);
  }
  SampleBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SampleBuilder &operator=(const SampleBuilder &);
  flatbuffers::Offset<Sample> Finish() {
    const auto end = fbb_.EndTable(start_, 6);
    auto o = flatbuffers::Offset<Sample>(end);
    return o;
  }
};

inline flatbuffers::Offset<Sample> CreateSample(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t time = 0,
    flatbuffers::Offset<flatbuffers::String> address = 0,
    int32_t instance = 0,
    ProposalDistribution proposal_type = ProposalDistribution_NONE,
    flatbuffers::Offset<void> proposal = 0,
    flatbuffers::Offset<NDArray> value = 0) {
  SampleBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_proposal(proposal);
  builder_.add_instance(instance);
  builder_.add_address(address);
  builder_.add_time(time);
  builder_.add_proposal_type(proposal_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Sample> CreateSampleDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t time = 0,
    const char *address = nullptr,
    int32_t instance = 0,
    ProposalDistribution proposal_type = ProposalDistribution_NONE,
    flatbuffers::Offset<void> proposal = 0,
    flatbuffers::Offset<NDArray> value = 0) {
  return infcomp::CreateSample(
      _fbb,
      time,
      address ? _fbb.CreateString(address) : 0,
      instance,
      proposal_type,
      proposal,
      value);
}

struct Trace FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OBSERVES = 4,
    VT_SAMPLES = 6
  };
  const NDArray *observes() const {
    return GetPointer<const NDArray *>(VT_OBSERVES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Sample>> *samples() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Sample>> *>(VT_SAMPLES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBSERVES) &&
           verifier.VerifyTable(observes()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SAMPLES) &&
           verifier.Verify(samples()) &&
           verifier.VerifyVectorOfTables(samples()) &&
           verifier.EndTable();
  }
};

struct TraceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_observes(flatbuffers::Offset<NDArray> observes) {
    fbb_.AddOffset(Trace::VT_OBSERVES, observes);
  }
  void add_samples(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Sample>>> samples) {
    fbb_.AddOffset(Trace::VT_SAMPLES, samples);
  }
  TraceBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TraceBuilder &operator=(const TraceBuilder &);
  flatbuffers::Offset<Trace> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Trace>(end);
    return o;
  }
};

inline flatbuffers::Offset<Trace> CreateTrace(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> observes = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Sample>>> samples = 0) {
  TraceBuilder builder_(_fbb);
  builder_.add_samples(samples);
  builder_.add_observes(observes);
  return builder_.Finish();
}

inline flatbuffers::Offset<Trace> CreateTraceDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> observes = 0,
    const std::vector<flatbuffers::Offset<Sample>> *samples = nullptr) {
  return infcomp::CreateTrace(
      _fbb,
      observes,
      samples ? _fbb.CreateVector<flatbuffers::Offset<Sample>>(*samples) : 0);
}

struct TracesFromPriorRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NUM_TRACES = 4
  };
  int32_t num_traces() const {
    return GetField<int32_t>(VT_NUM_TRACES, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_NUM_TRACES) &&
           verifier.EndTable();
  }
};

struct TracesFromPriorRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_num_traces(int32_t num_traces) {
    fbb_.AddElement<int32_t>(TracesFromPriorRequest::VT_NUM_TRACES, num_traces, 0);
  }
  TracesFromPriorRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TracesFromPriorRequestBuilder &operator=(const TracesFromPriorRequestBuilder &);
  flatbuffers::Offset<TracesFromPriorRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<TracesFromPriorRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<TracesFromPriorRequest> CreateTracesFromPriorRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t num_traces = 0) {
  TracesFromPriorRequestBuilder builder_(_fbb);
  builder_.add_num_traces(num_traces);
  return builder_.Finish();
}

struct TracesFromPriorReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TRACES = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<Trace>> *traces() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Trace>> *>(VT_TRACES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TRACES) &&
           verifier.Verify(traces()) &&
           verifier.VerifyVectorOfTables(traces()) &&
           verifier.EndTable();
  }
};

struct TracesFromPriorReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_traces(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Trace>>> traces) {
    fbb_.AddOffset(TracesFromPriorReply::VT_TRACES, traces);
  }
  TracesFromPriorReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TracesFromPriorReplyBuilder &operator=(const TracesFromPriorReplyBuilder &);
  flatbuffers::Offset<TracesFromPriorReply> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<TracesFromPriorReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<TracesFromPriorReply> CreateTracesFromPriorReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Trace>>> traces = 0) {
  TracesFromPriorReplyBuilder builder_(_fbb);
  builder_.add_traces(traces);
  return builder_.Finish();
}

inline flatbuffers::Offset<TracesFromPriorReply> CreateTracesFromPriorReplyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Trace>> *traces = nullptr) {
  return infcomp::CreateTracesFromPriorReply(
      _fbb,
      traces ? _fbb.CreateVector<flatbuffers::Offset<Trace>>(*traces) : 0);
}

struct ObservesInitRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OBSERVES = 4
  };
  const NDArray *observes() const {
    return GetPointer<const NDArray *>(VT_OBSERVES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBSERVES) &&
           verifier.VerifyTable(observes()) &&
           verifier.EndTable();
  }
};

struct ObservesInitRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_observes(flatbuffers::Offset<NDArray> observes) {
    fbb_.AddOffset(ObservesInitRequest::VT_OBSERVES, observes);
  }
  ObservesInitRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ObservesInitRequestBuilder &operator=(const ObservesInitRequestBuilder &);
  flatbuffers::Offset<ObservesInitRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ObservesInitRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<ObservesInitRequest> CreateObservesInitRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<NDArray> observes = 0) {
  ObservesInitRequestBuilder builder_(_fbb);
  builder_.add_observes(observes);
  return builder_.Finish();
}

struct ObservesInitReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SUCCESS = 4
  };
  bool success() const {
    return GetField<uint8_t>(VT_SUCCESS, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_SUCCESS) &&
           verifier.EndTable();
  }
};

struct ObservesInitReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_success(bool success) {
    fbb_.AddElement<uint8_t>(ObservesInitReply::VT_SUCCESS, static_cast<uint8_t>(success), 0);
  }
  ObservesInitReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ObservesInitReplyBuilder &operator=(const ObservesInitReplyBuilder &);
  flatbuffers::Offset<ObservesInitReply> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ObservesInitReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<ObservesInitReply> CreateObservesInitReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool success = false) {
  ObservesInitReplyBuilder builder_(_fbb);
  builder_.add_success(success);
  return builder_.Finish();
}

struct ProposalRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CURRENT_SAMPLE = 4,
    VT_PREVIOUS_SAMPLE = 6
  };
  const Sample *current_sample() const {
    return GetPointer<const Sample *>(VT_CURRENT_SAMPLE);
  }
  const Sample *previous_sample() const {
    return GetPointer<const Sample *>(VT_PREVIOUS_SAMPLE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_CURRENT_SAMPLE) &&
           verifier.VerifyTable(current_sample()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PREVIOUS_SAMPLE) &&
           verifier.VerifyTable(previous_sample()) &&
           verifier.EndTable();
  }
};

struct ProposalRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_current_sample(flatbuffers::Offset<Sample> current_sample) {
    fbb_.AddOffset(ProposalRequest::VT_CURRENT_SAMPLE, current_sample);
  }
  void add_previous_sample(flatbuffers::Offset<Sample> previous_sample) {
    fbb_.AddOffset(ProposalRequest::VT_PREVIOUS_SAMPLE, previous_sample);
  }
  ProposalRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ProposalRequestBuilder &operator=(const ProposalRequestBuilder &);
  flatbuffers::Offset<ProposalRequest> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<ProposalRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<ProposalRequest> CreateProposalRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Sample> current_sample = 0,
    flatbuffers::Offset<Sample> previous_sample = 0) {
  ProposalRequestBuilder builder_(_fbb);
  builder_.add_previous_sample(previous_sample);
  builder_.add_current_sample(current_sample);
  return builder_.Finish();
}

struct ProposalReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SUCCESS = 4,
    VT_PROPOSAL_TYPE = 6,
    VT_PROPOSAL = 8
  };
  bool success() const {
    return GetField<uint8_t>(VT_SUCCESS, 0) != 0;
  }
  ProposalDistribution proposal_type() const {
    return static_cast<ProposalDistribution>(GetField<uint8_t>(VT_PROPOSAL_TYPE, 0));
  }
  const void *proposal() const {
    return GetPointer<const void *>(VT_PROPOSAL);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_SUCCESS) &&
           VerifyField<uint8_t>(verifier, VT_PROPOSAL_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PROPOSAL) &&
           VerifyProposalDistribution(verifier, proposal(), proposal_type()) &&
           verifier.EndTable();
  }
};

struct ProposalReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_success(bool success) {
    fbb_.AddElement<uint8_t>(ProposalReply::VT_SUCCESS, static_cast<uint8_t>(success), 0);
  }
  void add_proposal_type(ProposalDistribution proposal_type) {
    fbb_.AddElement<uint8_t>(ProposalReply::VT_PROPOSAL_TYPE, static_cast<uint8_t>(proposal_type), 0);
  }
  void add_proposal(flatbuffers::Offset<void> proposal) {
    fbb_.AddOffset(ProposalReply::VT_PROPOSAL, proposal);
  }
  ProposalReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ProposalReplyBuilder &operator=(const ProposalReplyBuilder &);
  flatbuffers::Offset<ProposalReply> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<ProposalReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<ProposalReply> CreateProposalReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool success = false,
    ProposalDistribution proposal_type = ProposalDistribution_NONE,
    flatbuffers::Offset<void> proposal = 0) {
  ProposalReplyBuilder builder_(_fbb);
  builder_.add_proposal(proposal);
  builder_.add_proposal_type(proposal_type);
  builder_.add_success(success);
  return builder_.Finish();
}

inline bool VerifyMessageBody(flatbuffers::Verifier &verifier, const void *obj, MessageBody type) {
  switch (type) {
    case MessageBody_NONE: {
      return true;
    }
    case MessageBody_TracesFromPriorRequest: {
      auto ptr = reinterpret_cast<const TracesFromPriorRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody_ObservesInitRequest: {
      auto ptr = reinterpret_cast<const ObservesInitRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody_ProposalRequest: {
      auto ptr = reinterpret_cast<const ProposalRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody_TracesFromPriorReply: {
      auto ptr = reinterpret_cast<const TracesFromPriorReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody_ObservesInitReply: {
      auto ptr = reinterpret_cast<const ObservesInitReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case MessageBody_ProposalReply: {
      auto ptr = reinterpret_cast<const ProposalReply *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageBodyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessageBody(
        verifier,  values->Get(i), types->GetEnum<MessageBody>(i))) {
      return false;
    }
  }
  return true;
}

inline bool VerifyProposalDistribution(flatbuffers::Verifier &verifier, const void *obj, ProposalDistribution type) {
  switch (type) {
    case ProposalDistribution_NONE: {
      return true;
    }
    case ProposalDistribution_CategoricalProposal: {
      auto ptr = reinterpret_cast<const CategoricalProposal *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProposalDistribution_DiscreteProposal: {
      auto ptr = reinterpret_cast<const DiscreteProposal *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProposalDistribution_FlipProposal: {
      auto ptr = reinterpret_cast<const FlipProposal *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProposalDistribution_NormalProposal: {
      auto ptr = reinterpret_cast<const NormalProposal *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case ProposalDistribution_UniformDiscreteProposal: {
      auto ptr = reinterpret_cast<const UniformDiscreteProposal *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyProposalDistributionVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyProposalDistribution(
        verifier,  values->Get(i), types->GetEnum<ProposalDistribution>(i))) {
      return false;
    }
  }
  return true;
}

inline const infcomp::Message *GetMessage(const void *buf) {
  return flatbuffers::GetRoot<infcomp::Message>(buf);
}

inline bool VerifyMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<infcomp::Message>(nullptr);
}

inline void FinishMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<infcomp::Message> root) {
  fbb.Finish(root);
}

}  // namespace infcomp

#endif  // FLATBUFFERS_GENERATED_INFCOMP_INFCOMP_H_
