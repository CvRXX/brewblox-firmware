// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TempSensorExternal_test.proto

#ifndef PROTOBUF_INCLUDED_TempSensorExternal_5ftest_2eproto
#define PROTOBUF_INCLUDED_TempSensorExternal_5ftest_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_TempSensorExternal_5ftest_2eproto 

namespace protobuf_TempSensorExternal_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_TempSensorExternal_5ftest_2eproto
namespace blox_test {
namespace TempSensorExternal {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace TempSensorExternal
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::TempSensorExternal::Block* Arena::CreateMaybeMessage<::blox_test::TempSensorExternal::Block>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace TempSensorExternal {

// ===================================================================

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.TempSensorExternal.Block) */ {
 public:
  Block();
  virtual ~Block();

  Block(const Block& from);

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Block(Block&& from) noexcept
    : Block() {
    *this = ::std::move(from);
  }

  inline Block& operator=(Block&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Block& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Block* internal_default_instance() {
    return reinterpret_cast<const Block*>(
               &_Block_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Block* other);
  friend void swap(Block& a, Block& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Block* New() const final {
    return CreateMaybeMessage<Block>(NULL);
  }

  Block* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Block>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Block& from);
  void MergeFrom(const Block& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Block* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool enabled = 1;
  void clear_enabled();
  static const int kEnabledFieldNumber = 1;
  bool enabled() const;
  void set_enabled(bool value);

  // uint32 timeout = 2 [(.nanopb) = {
  void clear_timeout();
  static const int kTimeoutFieldNumber = 2;
  ::google::protobuf::uint32 timeout() const;
  void set_timeout(::google::protobuf::uint32 value);

  // sint32 setting = 3 [(.nanopb) = {
  void clear_setting();
  static const int kSettingFieldNumber = 3;
  ::google::protobuf::int32 setting() const;
  void set_setting(::google::protobuf::int32 value);

  // uint32 lastUpdated = 4 [(.nanopb) = {
  void clear_lastupdated();
  static const int kLastUpdatedFieldNumber = 4;
  ::google::protobuf::uint32 lastupdated() const;
  void set_lastupdated(::google::protobuf::uint32 value);

  // sint32 value = 5 [(.nanopb) = {
  void clear_value();
  static const int kValueFieldNumber = 5;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox_test.TempSensorExternal.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool enabled_;
  ::google::protobuf::uint32 timeout_;
  ::google::protobuf::int32 setting_;
  ::google::protobuf::uint32 lastupdated_;
  ::google::protobuf::int32 value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_TempSensorExternal_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Block

// bool enabled = 1;
inline void Block::clear_enabled() {
  enabled_ = false;
}
inline bool Block::enabled() const {
  // @@protoc_insertion_point(field_get:blox_test.TempSensorExternal.Block.enabled)
  return enabled_;
}
inline void Block::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:blox_test.TempSensorExternal.Block.enabled)
}

// uint32 timeout = 2 [(.nanopb) = {
inline void Block::clear_timeout() {
  timeout_ = 0u;
}
inline ::google::protobuf::uint32 Block::timeout() const {
  // @@protoc_insertion_point(field_get:blox_test.TempSensorExternal.Block.timeout)
  return timeout_;
}
inline void Block::set_timeout(::google::protobuf::uint32 value) {
  
  timeout_ = value;
  // @@protoc_insertion_point(field_set:blox_test.TempSensorExternal.Block.timeout)
}

// sint32 setting = 3 [(.nanopb) = {
inline void Block::clear_setting() {
  setting_ = 0;
}
inline ::google::protobuf::int32 Block::setting() const {
  // @@protoc_insertion_point(field_get:blox_test.TempSensorExternal.Block.setting)
  return setting_;
}
inline void Block::set_setting(::google::protobuf::int32 value) {
  
  setting_ = value;
  // @@protoc_insertion_point(field_set:blox_test.TempSensorExternal.Block.setting)
}

// uint32 lastUpdated = 4 [(.nanopb) = {
inline void Block::clear_lastupdated() {
  lastupdated_ = 0u;
}
inline ::google::protobuf::uint32 Block::lastupdated() const {
  // @@protoc_insertion_point(field_get:blox_test.TempSensorExternal.Block.lastUpdated)
  return lastupdated_;
}
inline void Block::set_lastupdated(::google::protobuf::uint32 value) {
  
  lastupdated_ = value;
  // @@protoc_insertion_point(field_set:blox_test.TempSensorExternal.Block.lastUpdated)
}

// sint32 value = 5 [(.nanopb) = {
inline void Block::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 Block::value() const {
  // @@protoc_insertion_point(field_get:blox_test.TempSensorExternal.Block.value)
  return value_;
}
inline void Block::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:blox_test.TempSensorExternal.Block.value)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace TempSensorExternal
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_TempSensorExternal_5ftest_2eproto
