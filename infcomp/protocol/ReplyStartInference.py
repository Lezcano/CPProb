# automatically generated by the FlatBuffers compiler, do not modify

# namespace: protocol

import flatbuffers

class ReplyStartInference(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsReplyStartInference(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = ReplyStartInference()
        x.Init(buf, n + offset)
        return x

    # ReplyStartInference
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

def ReplyStartInferenceStart(builder): builder.StartObject(0)
def ReplyStartInferenceEnd(builder): return builder.EndObject()
