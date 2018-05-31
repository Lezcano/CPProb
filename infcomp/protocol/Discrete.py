# automatically generated by the FlatBuffers compiler, do not modify

# namespace: protocol

import flatbuffers

class Discrete(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsDiscrete(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Discrete()
        x.Init(buf, n + offset)
        return x

    # Discrete
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Discrete
    def Min(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Discrete
    def Max(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Discrete
    def Probabilities(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.Get(flatbuffers.number_types.Float64Flags, a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 8))
        return 0

    # Discrete
    def ProbabilitiesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Discrete
    def Value(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

def DiscreteStart(builder): builder.StartObject(4)
def DiscreteAddMin(builder, min): builder.PrependInt32Slot(0, min, 0)
def DiscreteAddMax(builder, max): builder.PrependInt32Slot(1, max, 0)
def DiscreteAddProbabilities(builder, probabilities): builder.PrependUOffsetTRelativeSlot(2, flatbuffers.number_types.UOffsetTFlags.py_type(probabilities), 0)
def DiscreteStartProbabilitiesVector(builder, numElems): return builder.StartVector(8, numElems, 8)
def DiscreteAddValue(builder, value): builder.PrependInt32Slot(3, value, 0)
def DiscreteEnd(builder): return builder.EndObject()