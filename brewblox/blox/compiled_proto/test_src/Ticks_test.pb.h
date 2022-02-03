// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Ticks_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Ticks_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Ticks_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Ticks_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Ticks_5ftest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Ticks_5ftest_2eproto;
namespace blox_test {
namespace Ticks {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace Ticks
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> ::blox_test::Ticks::Block* Arena::CreateMaybeMessage<::blox_test::Ticks::Block>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox_test {
namespace Ticks {

// ===================================================================

class Block PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox_test.Ticks.Block) */ {
 public:
  inline Block() : Block(nullptr) {};
  virtual ~Block();

  Block(const Block& from);
  Block(Block&& from) noexcept
    : Block() {
    *this = ::std::move(from);
  }

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }
  inline Block& operator=(Block&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Block& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Block* internal_default_instance() {
    return reinterpret_cast<const Block*>(
               &_Block_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Block& a, Block& b) {
    a.Swap(&b);
  }
  inline void Swap(Block* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Block* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Block* New() const final {
    return CreateMaybeMessage<Block>(nullptr);
  }

  Block* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Block>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Block& from);
  void MergeFrom(const Block& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Block* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox_test.Ticks.Block";
  }
  protected:
  explicit Block(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Ticks_5ftest_2eproto);
    return ::descriptor_table_Ticks_5ftest_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMillisSinceBootFieldNumber = 1,
    kSecondsSinceEpochFieldNumber = 2,
    kAvgCommunicationTaskFieldNumber = 3,
    kAvgBlocksUpdateTaskFieldNumber = 4,
    kAvgDisplayTaskFieldNumber = 5,
    kAvgSystemTaskFieldNumber = 6,
  };
  // uint32 millisSinceBoot = 1 [(.nanopb) = {
  void clear_millissinceboot();
  ::PROTOBUF_NAMESPACE_ID::uint32 millissinceboot() const;
  void set_millissinceboot(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_millissinceboot() const;
  void _internal_set_millissinceboot(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 secondsSinceEpoch = 2 [(.nanopb) = {
  void clear_secondssinceepoch();
  ::PROTOBUF_NAMESPACE_ID::uint32 secondssinceepoch() const;
  void set_secondssinceepoch(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_secondssinceepoch() const;
  void _internal_set_secondssinceepoch(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 avgCommunicationTask = 3 [(.nanopb) = {
  void clear_avgcommunicationtask();
  ::PROTOBUF_NAMESPACE_ID::uint32 avgcommunicationtask() const;
  void set_avgcommunicationtask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_avgcommunicationtask() const;
  void _internal_set_avgcommunicationtask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 avgBlocksUpdateTask = 4 [(.nanopb) = {
  void clear_avgblocksupdatetask();
  ::PROTOBUF_NAMESPACE_ID::uint32 avgblocksupdatetask() const;
  void set_avgblocksupdatetask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_avgblocksupdatetask() const;
  void _internal_set_avgblocksupdatetask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 avgDisplayTask = 5 [(.nanopb) = {
  void clear_avgdisplaytask();
  ::PROTOBUF_NAMESPACE_ID::uint32 avgdisplaytask() const;
  void set_avgdisplaytask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_avgdisplaytask() const;
  void _internal_set_avgdisplaytask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 avgSystemTask = 6 [(.nanopb) = {
  void clear_avgsystemtask();
  ::PROTOBUF_NAMESPACE_ID::uint32 avgsystemtask() const;
  void set_avgsystemtask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_avgsystemtask() const;
  void _internal_set_avgsystemtask(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:blox_test.Ticks.Block)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint32 millissinceboot_;
  ::PROTOBUF_NAMESPACE_ID::uint32 secondssinceepoch_;
  ::PROTOBUF_NAMESPACE_ID::uint32 avgcommunicationtask_;
  ::PROTOBUF_NAMESPACE_ID::uint32 avgblocksupdatetask_;
  ::PROTOBUF_NAMESPACE_ID::uint32 avgdisplaytask_;
  ::PROTOBUF_NAMESPACE_ID::uint32 avgsystemtask_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Ticks_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Block

// uint32 millisSinceBoot = 1 [(.nanopb) = {
inline void Block::clear_millissinceboot() {
  millissinceboot_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::_internal_millissinceboot() const {
  return millissinceboot_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::millissinceboot() const {
  // @@protoc_insertion_point(field_get:blox_test.Ticks.Block.millisSinceBoot)
  return _internal_millissinceboot();
}
inline void Block::_internal_set_millissinceboot(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  millissinceboot_ = value;
}
inline void Block::set_millissinceboot(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_millissinceboot(value);
  // @@protoc_insertion_point(field_set:blox_test.Ticks.Block.millisSinceBoot)
}

// uint32 secondsSinceEpoch = 2 [(.nanopb) = {
inline void Block::clear_secondssinceepoch() {
  secondssinceepoch_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::_internal_secondssinceepoch() const {
  return secondssinceepoch_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::secondssinceepoch() const {
  // @@protoc_insertion_point(field_get:blox_test.Ticks.Block.secondsSinceEpoch)
  return _internal_secondssinceepoch();
}
inline void Block::_internal_set_secondssinceepoch(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  secondssinceepoch_ = value;
}
inline void Block::set_secondssinceepoch(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_secondssinceepoch(value);
  // @@protoc_insertion_point(field_set:blox_test.Ticks.Block.secondsSinceEpoch)
}

// uint32 avgCommunicationTask = 3 [(.nanopb) = {
inline void Block::clear_avgcommunicationtask() {
  avgcommunicationtask_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::_internal_avgcommunicationtask() const {
  return avgcommunicationtask_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::avgcommunicationtask() const {
  // @@protoc_insertion_point(field_get:blox_test.Ticks.Block.avgCommunicationTask)
  return _internal_avgcommunicationtask();
}
inline void Block::_internal_set_avgcommunicationtask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  avgcommunicationtask_ = value;
}
inline void Block::set_avgcommunicationtask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_avgcommunicationtask(value);
  // @@protoc_insertion_point(field_set:blox_test.Ticks.Block.avgCommunicationTask)
}

// uint32 avgBlocksUpdateTask = 4 [(.nanopb) = {
inline void Block::clear_avgblocksupdatetask() {
  avgblocksupdatetask_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::_internal_avgblocksupdatetask() const {
  return avgblocksupdatetask_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::avgblocksupdatetask() const {
  // @@protoc_insertion_point(field_get:blox_test.Ticks.Block.avgBlocksUpdateTask)
  return _internal_avgblocksupdatetask();
}
inline void Block::_internal_set_avgblocksupdatetask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  avgblocksupdatetask_ = value;
}
inline void Block::set_avgblocksupdatetask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_avgblocksupdatetask(value);
  // @@protoc_insertion_point(field_set:blox_test.Ticks.Block.avgBlocksUpdateTask)
}

// uint32 avgDisplayTask = 5 [(.nanopb) = {
inline void Block::clear_avgdisplaytask() {
  avgdisplaytask_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::_internal_avgdisplaytask() const {
  return avgdisplaytask_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::avgdisplaytask() const {
  // @@protoc_insertion_point(field_get:blox_test.Ticks.Block.avgDisplayTask)
  return _internal_avgdisplaytask();
}
inline void Block::_internal_set_avgdisplaytask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  avgdisplaytask_ = value;
}
inline void Block::set_avgdisplaytask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_avgdisplaytask(value);
  // @@protoc_insertion_point(field_set:blox_test.Ticks.Block.avgDisplayTask)
}

// uint32 avgSystemTask = 6 [(.nanopb) = {
inline void Block::clear_avgsystemtask() {
  avgsystemtask_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::_internal_avgsystemtask() const {
  return avgsystemtask_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Block::avgsystemtask() const {
  // @@protoc_insertion_point(field_get:blox_test.Ticks.Block.avgSystemTask)
  return _internal_avgsystemtask();
}
inline void Block::_internal_set_avgsystemtask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  avgsystemtask_ = value;
}
inline void Block::set_avgsystemtask(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_avgsystemtask(value);
  // @@protoc_insertion_point(field_set:blox_test.Ticks.Block.avgSystemTask)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Ticks
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Ticks_5ftest_2eproto
