// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OneWireBus_test.proto

#ifndef PROTOBUF_INCLUDED_OneWireBus_5ftest_2eproto
#define PROTOBUF_INCLUDED_OneWireBus_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_OneWireBus_5ftest_2eproto 

namespace protobuf_OneWireBus_5ftest_2eproto {
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
}  // namespace protobuf_OneWireBus_5ftest_2eproto
namespace blox {
namespace OneWireBus {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
class Command;
class CommandDefaultTypeInternal;
extern CommandDefaultTypeInternal _Command_default_instance_;
}  // namespace OneWireBus
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::OneWireBus::Block* Arena::CreateMaybeMessage<::blox::OneWireBus::Block>(Arena*);
template<> ::blox::OneWireBus::Command* Arena::CreateMaybeMessage<::blox::OneWireBus::Command>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {
namespace OneWireBus {

// ===================================================================

class Command : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.OneWireBus.Command) */ {
 public:
  Command();
  virtual ~Command();

  Command(const Command& from);

  inline Command& operator=(const Command& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Command(Command&& from) noexcept
    : Command() {
    *this = ::std::move(from);
  }

  inline Command& operator=(Command&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Command& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Command* internal_default_instance() {
    return reinterpret_cast<const Command*>(
               &_Command_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Command* other);
  friend void swap(Command& a, Command& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Command* New() const final {
    return CreateMaybeMessage<Command>(NULL);
  }

  Command* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Command>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Command& from);
  void MergeFrom(const Command& from);
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
  void InternalSwap(Command* other);
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

  // uint32 opcode = 1 [(.nanopb_test) = {
  void clear_opcode();
  static const int kOpcodeFieldNumber = 1;
  ::google::protobuf::uint32 opcode() const;
  void set_opcode(::google::protobuf::uint32 value);

  // uint32 data = 2 [(.nanopb_test) = {
  void clear_data();
  static const int kDataFieldNumber = 2;
  ::google::protobuf::uint32 data() const;
  void set_data(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.OneWireBus.Command)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 opcode_;
  ::google::protobuf::uint32 data_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_OneWireBus_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.OneWireBus.Block) */ {
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

  // repeated fixed64 address = 2 [(.brewblox_test) = {
  int address_size() const;
  void clear_address();
  static const int kAddressFieldNumber = 2;
  ::google::protobuf::uint64 address(int index) const;
  void set_address(int index, ::google::protobuf::uint64 value);
  void add_address(::google::protobuf::uint64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
      address() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
      mutable_address();

  // .blox.OneWireBus.Command command = 1;
  bool has_command() const;
  void clear_command();
  static const int kCommandFieldNumber = 1;
  private:
  const ::blox::OneWireBus::Command& _internal_command() const;
  public:
  const ::blox::OneWireBus::Command& command() const;
  ::blox::OneWireBus::Command* release_command();
  ::blox::OneWireBus::Command* mutable_command();
  void set_allocated_command(::blox::OneWireBus::Command* command);

  // @@protoc_insertion_point(class_scope:blox.OneWireBus.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint64 > address_;
  mutable int _address_cached_byte_size_;
  ::blox::OneWireBus::Command* command_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_OneWireBus_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Command

// uint32 opcode = 1 [(.nanopb_test) = {
inline void Command::clear_opcode() {
  opcode_ = 0u;
}
inline ::google::protobuf::uint32 Command::opcode() const {
  // @@protoc_insertion_point(field_get:blox.OneWireBus.Command.opcode)
  return opcode_;
}
inline void Command::set_opcode(::google::protobuf::uint32 value) {
  
  opcode_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireBus.Command.opcode)
}

// uint32 data = 2 [(.nanopb_test) = {
inline void Command::clear_data() {
  data_ = 0u;
}
inline ::google::protobuf::uint32 Command::data() const {
  // @@protoc_insertion_point(field_get:blox.OneWireBus.Command.data)
  return data_;
}
inline void Command::set_data(::google::protobuf::uint32 value) {
  
  data_ = value;
  // @@protoc_insertion_point(field_set:blox.OneWireBus.Command.data)
}

// -------------------------------------------------------------------

// Block

// .blox.OneWireBus.Command command = 1;
inline bool Block::has_command() const {
  return this != internal_default_instance() && command_ != NULL;
}
inline void Block::clear_command() {
  if (GetArenaNoVirtual() == NULL && command_ != NULL) {
    delete command_;
  }
  command_ = NULL;
}
inline const ::blox::OneWireBus::Command& Block::_internal_command() const {
  return *command_;
}
inline const ::blox::OneWireBus::Command& Block::command() const {
  const ::blox::OneWireBus::Command* p = command_;
  // @@protoc_insertion_point(field_get:blox.OneWireBus.Block.command)
  return p != NULL ? *p : *reinterpret_cast<const ::blox::OneWireBus::Command*>(
      &::blox::OneWireBus::_Command_default_instance_);
}
inline ::blox::OneWireBus::Command* Block::release_command() {
  // @@protoc_insertion_point(field_release:blox.OneWireBus.Block.command)
  
  ::blox::OneWireBus::Command* temp = command_;
  command_ = NULL;
  return temp;
}
inline ::blox::OneWireBus::Command* Block::mutable_command() {
  
  if (command_ == NULL) {
    auto* p = CreateMaybeMessage<::blox::OneWireBus::Command>(GetArenaNoVirtual());
    command_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox.OneWireBus.Block.command)
  return command_;
}
inline void Block::set_allocated_command(::blox::OneWireBus::Command* command) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete command_;
  }
  if (command) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      command = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, command, submessage_arena);
    }
    
  } else {
    
  }
  command_ = command;
  // @@protoc_insertion_point(field_set_allocated:blox.OneWireBus.Block.command)
}

// repeated fixed64 address = 2 [(.brewblox_test) = {
inline int Block::address_size() const {
  return address_.size();
}
inline void Block::clear_address() {
  address_.Clear();
}
inline ::google::protobuf::uint64 Block::address(int index) const {
  // @@protoc_insertion_point(field_get:blox.OneWireBus.Block.address)
  return address_.Get(index);
}
inline void Block::set_address(int index, ::google::protobuf::uint64 value) {
  address_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.OneWireBus.Block.address)
}
inline void Block::add_address(::google::protobuf::uint64 value) {
  address_.Add(value);
  // @@protoc_insertion_point(field_add:blox.OneWireBus.Block.address)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
Block::address() const {
  // @@protoc_insertion_point(field_list:blox.OneWireBus.Block.address)
  return address_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
Block::mutable_address() {
  // @@protoc_insertion_point(field_mutable_list:blox.OneWireBus.Block.address)
  return &address_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace OneWireBus
}  // namespace blox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_OneWireBus_5ftest_2eproto
