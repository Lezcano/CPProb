import zmq

# TODO Improve error handling, if any.
# This class should be used either in a `with Socket(addr)...` clause or
#  the user should remember to connect and close the socket herself
class Socket(object):
    def __init__(self, addr, mode):
        self._context = zmq.Context()
        self._socket = self._context.socket(mode)
        self._mode = mode
        self._addr = addr

    def __enter__(self):
        self.connect()
        return self

    def __exit__(self, exception_type, exception_value, traceback):
        self.close()

    def connect(self):
        # Server
        if self._mode == zmq.REQ:
            self._socket.connect(self._addr)
        # Client
        elif self._mode == zmq.REP:
            self._socket.bind(self._addr)
        else:
            raise RuntimeError("Wrong socket mode {}. ".format(mode))

    def close(self):
        self._socket.close()
        self._context.term()

    def send(self, request):
        self._socket.send(request)

    def receive(self):
        return self._socket.recv()

