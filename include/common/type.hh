//===------------------------------------------===
// Saturn 2023
//
// Identification: include/common/type.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

//===------------------------------------------------===
// Scalar types for Saturn
//===------------------------------------------------===

#pragma once

#include <cstdint>

namespace ffvi {

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;

// only value types are allowed to be used in strong typedefs
// pointers are strong anyway

// datum
using Datum = u8;
using DatumPtr = Datum *;
using MemoryByte = u64;

} // namespace ffvi
