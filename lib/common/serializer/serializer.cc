//===------------------------------------------===
// Saturn 2023
//
// Identification: lib/common/serializer/serializer.cc
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#include "common/serializer/serializer.hh"

namespace ffvi {

/// a vtable anchor
void Serializer::WriteValue(const string &value) { WriteValue(value.c_str()); }

} // namespace ffvi
