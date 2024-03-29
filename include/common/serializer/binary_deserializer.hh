//===------------------------------------------===
// Saturn 2023
//
// Identification: include/common/serializer/binary_deserializer.hh
//
// Author: Ji Wang <jiwangcdi@gmail.com>
//
//===------------------------------------------===

#pragma once

#include "common/serializer/deserializer.hh"

namespace ffvi {

class BinaryDeserializer : public Deserializer {
public:
  template <typename T>
  static auto Deserialize(Datum *ptr, MemoryByte length) -> unique_ptr<T> {
    BinaryDeserializer deserializer(ptr, length);
    auto result = deserializer.Read<T>();
    return make_unique<T>(std::move(result));
  }

private:
  explicit BinaryDeserializer(Datum *ptr, MemoryByte length)
      : ptr_(ptr), endPtr_(ptr + length) {}

  struct State {
    u32 expectedFieldCount;
    MemoryByte expectedSize;
    u32 readFieldCount = 0;
    State(u32 expected_field_count, MemoryByte expected_size)
        : expectedFieldCount(expected_field_count),
          expectedSize(expected_size) {}
  };

  const char *currentTag = nullptr;
  Datum *ptr_;
  Datum *endPtr_;
  vector<State> stack;

  template <typename T> auto ReadPOD() -> T {
    static_assert(std::is_trivially_destructible<T>::value,
                  "T must be trivally destructible-typed variable");
    T value;
    ReadData((Datum *)&value, sizeof(T));
    return value;
  }

  void ReadData(Datum *buffer, MemoryByte read_size) {
    if (ptr_ + read_size > endPtr_) {
      throw ParseException("Failed to deserialize: not enough data in buffer "
                           "to fulfill read request");
    }
    memcpy(buffer, ptr_, read_size);
    ptr_ += read_size;
  }

  void ReadData(vector<Datum> &data, MemoryByte read_size) {
    if (ptr_ + read_size > endPtr_) {
      throw ParseException("Failed to deserialize: not enough data in buffer "
                           "to fulfill read request");
    }
    data.insert(data.end(), ptr_, ptr_ + read_size);
    ptr_ += read_size;
  }

public:
  //===------------------------------------------------------------------------===
  // override functions
  //===------------------------------------------------------------------------===
  void SetTag(const char *tag) override;
  auto OnVectorBegin() -> MemoryByte override;
  auto OnMapBegin() -> MemoryByte override;
  void OnObjectBegin() override;
  void OnObjectEnd() override;

protected:
  auto ReadBool() -> bool override;
  auto ReadSignedInt8() -> i8 override;
  auto ReadUnsignedInt8() -> u8 override;
  auto ReadSignedInt16() -> i16 override;
  auto ReadUnsignedInt16() -> u16 override;
  auto ReadSignedInt32() -> i32 override;
  auto ReadUnsignedInt32() -> u32 override;
  auto ReadSignedInt64() -> i64 override;
  auto ReadUnsignedInt64() -> u64 override;
  auto ReadFloat() -> float override;
  auto ReadDouble() -> double override;
  auto ReadString() -> string override;
};

} // namespace ffvi
