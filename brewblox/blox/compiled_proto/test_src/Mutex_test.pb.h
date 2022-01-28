// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Mutex_test.proto

#ifndef PROTOBUF_INCLUDED_Mutex_5ftest_2eproto
#define PROTOBUF_INCLUDED_Mutex_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_Mutex_5ftest_2eproto 

namespace protobuf_Mutex_5ftest_2eproto {
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
}  // namespace protobuf_Mutex_5ftest_2eproto
namespace blox_test {
namespace Mutex {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace Mutex
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::Mutex::Block* Arena::CreateMaybeMessage<::blox_test::Mutex::Block>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace Mutex {

// ===================================================================

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.Mutex.Block) */ {
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

  // uint32 differentActuatorWait = 1 [(.brewblox.field) = {
  void clear_differentactuatorwait();
  static const int kDifferentActuatorWaitFieldNumber = 1;
  ::google::protobuf::uint32 differentactuatorwait() const;
  void set_differentactuatorwait(::google::protobuf::uint32 value);

  // uint32 waitRemaining = 2 [(.nanopb) = {
  void clear_waitremaining();
  static const int kWaitRemainingFieldNumber = 2;
  ::google::protobuf::uint32 waitremaining() const;
  void set_waitremaining(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.Mutex.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 differentactuatorwait_;
  ::google::protobuf::uint32 waitremaining_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Mutex_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Block

// uint32 differentActuatorWait = 1 [(.brewblox.field) = {
inline void Block::clear_differentactuatorwait() {
  differentactuatorwait_ = 0u;
}
inline ::google::protobuf::uint32 Block::differentactuatorwait() const {
  // @@protoc_insertion_point(field_get:blox_test.Mutex.Block.differentActuatorWait)
  return differentactuatorwait_;
}
inline void Block::set_differentactuatorwait(::google::protobuf::uint32 value) {
  
  differentactuatorwait_ = value;
  // @@protoc_insertion_point(field_set:blox_test.Mutex.Block.differentActuatorWait)
}

// uint32 waitRemaining = 2 [(.nanopb) = {
inline void Block::clear_waitremaining() {
  waitremaining_ = 0u;
}
inline ::google::protobuf::uint32 Block::waitremaining() const {
  // @@protoc_insertion_point(field_get:blox_test.Mutex.Block.waitRemaining)
  return waitremaining_;
}
inline void Block::set_waitremaining(::google::protobuf::uint32 value) {
  
  waitremaining_ = value;
  // @@protoc_insertion_point(field_set:blox_test.Mutex.Block.waitRemaining)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Mutex
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_Mutex_5ftest_2eproto
