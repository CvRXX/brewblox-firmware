// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Balancer_test.proto

#ifndef PROTOBUF_INCLUDED_Balancer_5ftest_2eproto
#define PROTOBUF_INCLUDED_Balancer_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_Balancer_5ftest_2eproto 

namespace protobuf_Balancer_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_Balancer_5ftest_2eproto
namespace blox_test {
namespace Balancer {
class BalancedActuator;
class BalancedActuatorDefaultTypeInternal;
extern BalancedActuatorDefaultTypeInternal _BalancedActuator_default_instance_;
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace Balancer
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::Balancer::BalancedActuator* Arena::CreateMaybeMessage<::blox_test::Balancer::BalancedActuator>(Arena*);
template<> ::blox_test::Balancer::Block* Arena::CreateMaybeMessage<::blox_test::Balancer::Block>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace Balancer {

// ===================================================================

class BalancedActuator : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.Balancer.BalancedActuator) */ {
 public:
  BalancedActuator();
  virtual ~BalancedActuator();

  BalancedActuator(const BalancedActuator& from);

  inline BalancedActuator& operator=(const BalancedActuator& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BalancedActuator(BalancedActuator&& from) noexcept
    : BalancedActuator() {
    *this = ::std::move(from);
  }

  inline BalancedActuator& operator=(BalancedActuator&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BalancedActuator& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BalancedActuator* internal_default_instance() {
    return reinterpret_cast<const BalancedActuator*>(
               &_BalancedActuator_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(BalancedActuator* other);
  friend void swap(BalancedActuator& a, BalancedActuator& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BalancedActuator* New() const final {
    return CreateMaybeMessage<BalancedActuator>(NULL);
  }

  BalancedActuator* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BalancedActuator>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const BalancedActuator& from);
  void MergeFrom(const BalancedActuator& from);
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
  void InternalSwap(BalancedActuator* other);
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

  // uint32 id = 1 [(.nanopb) = {
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // sint32 requested = 2 [(.nanopb) = {
  void clear_requested();
  static const int kRequestedFieldNumber = 2;
  ::google::protobuf::int32 requested() const;
  void set_requested(::google::protobuf::int32 value);

  // sint32 granted = 3 [(.nanopb) = {
  void clear_granted();
  static const int kGrantedFieldNumber = 3;
  ::google::protobuf::int32 granted() const;
  void set_granted(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox_test.Balancer.BalancedActuator)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 id_;
  ::google::protobuf::int32 requested_;
  ::google::protobuf::int32 granted_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Balancer_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.Balancer.Block) */ {
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
    1;

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

  // repeated .blox_test.Balancer.BalancedActuator clients = 1 [(.brewblox.field) = {
  int clients_size() const;
  void clear_clients();
  static const int kClientsFieldNumber = 1;
  ::blox_test::Balancer::BalancedActuator* mutable_clients(int index);
  ::google::protobuf::RepeatedPtrField< ::blox_test::Balancer::BalancedActuator >*
      mutable_clients();
  const ::blox_test::Balancer::BalancedActuator& clients(int index) const;
  ::blox_test::Balancer::BalancedActuator* add_clients();
  const ::google::protobuf::RepeatedPtrField< ::blox_test::Balancer::BalancedActuator >&
      clients() const;

  // @@protoc_insertion_point(class_scope:blox_test.Balancer.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox_test::Balancer::BalancedActuator > clients_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Balancer_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BalancedActuator

// uint32 id = 1 [(.nanopb) = {
inline void BalancedActuator::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 BalancedActuator::id() const {
  // @@protoc_insertion_point(field_get:blox_test.Balancer.BalancedActuator.id)
  return id_;
}
inline void BalancedActuator::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox_test.Balancer.BalancedActuator.id)
}

// sint32 requested = 2 [(.nanopb) = {
inline void BalancedActuator::clear_requested() {
  requested_ = 0;
}
inline ::google::protobuf::int32 BalancedActuator::requested() const {
  // @@protoc_insertion_point(field_get:blox_test.Balancer.BalancedActuator.requested)
  return requested_;
}
inline void BalancedActuator::set_requested(::google::protobuf::int32 value) {
  
  requested_ = value;
  // @@protoc_insertion_point(field_set:blox_test.Balancer.BalancedActuator.requested)
}

// sint32 granted = 3 [(.nanopb) = {
inline void BalancedActuator::clear_granted() {
  granted_ = 0;
}
inline ::google::protobuf::int32 BalancedActuator::granted() const {
  // @@protoc_insertion_point(field_get:blox_test.Balancer.BalancedActuator.granted)
  return granted_;
}
inline void BalancedActuator::set_granted(::google::protobuf::int32 value) {
  
  granted_ = value;
  // @@protoc_insertion_point(field_set:blox_test.Balancer.BalancedActuator.granted)
}

// -------------------------------------------------------------------

// Block

// repeated .blox_test.Balancer.BalancedActuator clients = 1 [(.brewblox.field) = {
inline int Block::clients_size() const {
  return clients_.size();
}
inline void Block::clear_clients() {
  clients_.Clear();
}
inline ::blox_test::Balancer::BalancedActuator* Block::mutable_clients(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.Balancer.Block.clients)
  return clients_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox_test::Balancer::BalancedActuator >*
Block::mutable_clients() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.Balancer.Block.clients)
  return &clients_;
}
inline const ::blox_test::Balancer::BalancedActuator& Block::clients(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.Balancer.Block.clients)
  return clients_.Get(index);
}
inline ::blox_test::Balancer::BalancedActuator* Block::add_clients() {
  // @@protoc_insertion_point(field_add:blox_test.Balancer.Block.clients)
  return clients_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox_test::Balancer::BalancedActuator >&
Block::clients() const {
  // @@protoc_insertion_point(field_list:blox_test.Balancer.Block.clients)
  return clients_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Balancer
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_Balancer_5ftest_2eproto
