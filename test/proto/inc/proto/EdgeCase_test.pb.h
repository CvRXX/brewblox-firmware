// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: EdgeCase_test.proto

#ifndef PROTOBUF_INCLUDED_EdgeCase_5ftest_2eproto
#define PROTOBUF_INCLUDED_EdgeCase_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_EdgeCase_5ftest_2eproto 

namespace protobuf_EdgeCase_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_EdgeCase_5ftest_2eproto
namespace blox_test {
namespace EdgeCase {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
class NestedLink;
class NestedLinkDefaultTypeInternal;
extern NestedLinkDefaultTypeInternal _NestedLink_default_instance_;
class Settings;
class SettingsDefaultTypeInternal;
extern SettingsDefaultTypeInternal _Settings_default_instance_;
class State;
class StateDefaultTypeInternal;
extern StateDefaultTypeInternal _State_default_instance_;
class SubCase;
class SubCaseDefaultTypeInternal;
extern SubCaseDefaultTypeInternal _SubCase_default_instance_;
}  // namespace EdgeCase
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::EdgeCase::Block* Arena::CreateMaybeMessage<::blox_test::EdgeCase::Block>(Arena*);
template<> ::blox_test::EdgeCase::NestedLink* Arena::CreateMaybeMessage<::blox_test::EdgeCase::NestedLink>(Arena*);
template<> ::blox_test::EdgeCase::Settings* Arena::CreateMaybeMessage<::blox_test::EdgeCase::Settings>(Arena*);
template<> ::blox_test::EdgeCase::State* Arena::CreateMaybeMessage<::blox_test::EdgeCase::State>(Arena*);
template<> ::blox_test::EdgeCase::SubCase* Arena::CreateMaybeMessage<::blox_test::EdgeCase::SubCase>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace EdgeCase {

// ===================================================================

class Settings : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.EdgeCase.Settings) */ {
 public:
  Settings();
  virtual ~Settings();

  Settings(const Settings& from);

  inline Settings& operator=(const Settings& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Settings(Settings&& from) noexcept
    : Settings() {
    *this = ::std::move(from);
  }

  inline Settings& operator=(Settings&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Settings& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Settings* internal_default_instance() {
    return reinterpret_cast<const Settings*>(
               &_Settings_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Settings* other);
  friend void swap(Settings& a, Settings& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Settings* New() const final {
    return CreateMaybeMessage<Settings>(NULL);
  }

  Settings* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Settings>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Settings& from);
  void MergeFrom(const Settings& from);
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
  void InternalSwap(Settings* other);
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

  // fixed64 address = 1 [(.brewblox.field) = {
  void clear_address();
  static const int kAddressFieldNumber = 1;
  ::google::protobuf::uint64 address() const;
  void set_address(::google::protobuf::uint64 value);

  // sint32 offset = 2 [(.brewblox.field) = {
  void clear_offset();
  static const int kOffsetFieldNumber = 2;
  ::google::protobuf::int32 offset() const;
  void set_offset(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox_test.EdgeCase.Settings)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 address_;
  ::google::protobuf::int32 offset_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class State : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.EdgeCase.State) */ {
 public:
  State();
  virtual ~State();

  State(const State& from);

  inline State& operator=(const State& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  State(State&& from) noexcept
    : State() {
    *this = ::std::move(from);
  }

  inline State& operator=(State&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const State& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const State* internal_default_instance() {
    return reinterpret_cast<const State*>(
               &_State_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(State* other);
  friend void swap(State& a, State& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline State* New() const final {
    return CreateMaybeMessage<State>(NULL);
  }

  State* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<State>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const State& from);
  void MergeFrom(const State& from);
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
  void InternalSwap(State* other);
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

  // sint32 value = 1 [(.brewblox.field) = {
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // bool connected = 2 [(.brewblox.field) = {
  void clear_connected();
  static const int kConnectedFieldNumber = 2;
  bool connected() const;
  void set_connected(bool value);

  // @@protoc_insertion_point(class_scope:blox_test.EdgeCase.State)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 value_;
  bool connected_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NestedLink : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.EdgeCase.NestedLink) */ {
 public:
  NestedLink();
  virtual ~NestedLink();

  NestedLink(const NestedLink& from);

  inline NestedLink& operator=(const NestedLink& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NestedLink(NestedLink&& from) noexcept
    : NestedLink() {
    *this = ::std::move(from);
  }

  inline NestedLink& operator=(NestedLink&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NestedLink& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NestedLink* internal_default_instance() {
    return reinterpret_cast<const NestedLink*>(
               &_NestedLink_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(NestedLink* other);
  friend void swap(NestedLink& a, NestedLink& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NestedLink* New() const final {
    return CreateMaybeMessage<NestedLink>(NULL);
  }

  NestedLink* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NestedLink>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NestedLink& from);
  void MergeFrom(const NestedLink& from);
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
  void InternalSwap(NestedLink* other);
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

  // uint32 connection = 1 [(.brewblox.field) = {
  void clear_connection();
  static const int kConnectionFieldNumber = 1;
  ::google::protobuf::uint32 connection() const;
  void set_connection(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.EdgeCase.NestedLink)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 connection_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.EdgeCase.Block) */ {
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
    3;

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

  // repeated .blox_test.EdgeCase.NestedLink additionalLinks = 4;
  int additionallinks_size() const;
  void clear_additionallinks();
  static const int kAdditionalLinksFieldNumber = 4;
  ::blox_test::EdgeCase::NestedLink* mutable_additionallinks(int index);
  ::google::protobuf::RepeatedPtrField< ::blox_test::EdgeCase::NestedLink >*
      mutable_additionallinks();
  const ::blox_test::EdgeCase::NestedLink& additionallinks(int index) const;
  ::blox_test::EdgeCase::NestedLink* add_additionallinks();
  const ::google::protobuf::RepeatedPtrField< ::blox_test::EdgeCase::NestedLink >&
      additionallinks() const;

  // repeated float listValues = 5 [(.brewblox.field) = {
  int listvalues_size() const;
  void clear_listvalues();
  static const int kListValuesFieldNumber = 5;
  float listvalues(int index) const;
  void set_listvalues(int index, float value);
  void add_listvalues(float value);
  const ::google::protobuf::RepeatedField< float >&
      listvalues() const;
  ::google::protobuf::RepeatedField< float >*
      mutable_listvalues();

  // .blox_test.EdgeCase.Settings settings = 1;
  bool has_settings() const;
  void clear_settings();
  static const int kSettingsFieldNumber = 1;
  private:
  const ::blox_test::EdgeCase::Settings& _internal_settings() const;
  public:
  const ::blox_test::EdgeCase::Settings& settings() const;
  ::blox_test::EdgeCase::Settings* release_settings();
  ::blox_test::EdgeCase::Settings* mutable_settings();
  void set_allocated_settings(::blox_test::EdgeCase::Settings* settings);

  // .blox_test.EdgeCase.State state = 2;
  bool has_state() const;
  void clear_state();
  static const int kStateFieldNumber = 2;
  private:
  const ::blox_test::EdgeCase::State& _internal_state() const;
  public:
  const ::blox_test::EdgeCase::State& state() const;
  ::blox_test::EdgeCase::State* release_state();
  ::blox_test::EdgeCase::State* mutable_state();
  void set_allocated_state(::blox_test::EdgeCase::State* state);

  // uint32 link = 3 [(.brewblox.field) = {
  void clear_link();
  static const int kLinkFieldNumber = 3;
  ::google::protobuf::uint32 link() const;
  void set_link(::google::protobuf::uint32 value);

  // uint32 deltaV = 6 [(.brewblox.field) = {
  void clear_deltav();
  static const int kDeltaVFieldNumber = 6;
  ::google::protobuf::uint32 deltav() const;
  void set_deltav(::google::protobuf::uint32 value);

  // uint32 logged = 7 [(.brewblox.field) = {
  void clear_logged();
  static const int kLoggedFieldNumber = 7;
  ::google::protobuf::uint32 logged() const;
  void set_logged(::google::protobuf::uint32 value);

  // uint32 unLogged = 8;
  void clear_unlogged();
  static const int kUnLoggedFieldNumber = 8;
  ::google::protobuf::uint32 unlogged() const;
  void set_unlogged(::google::protobuf::uint32 value);

  // uint32 drivenDevice = 9 [(.nanopb) = {
  void clear_drivendevice();
  static const int kDrivenDeviceFieldNumber = 9;
  ::google::protobuf::uint32 drivendevice() const;
  void set_drivendevice(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.EdgeCase.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox_test::EdgeCase::NestedLink > additionallinks_;
  ::google::protobuf::RepeatedField< float > listvalues_;
  mutable int _listvalues_cached_byte_size_;
  ::blox_test::EdgeCase::Settings* settings_;
  ::blox_test::EdgeCase::State* state_;
  ::google::protobuf::uint32 link_;
  ::google::protobuf::uint32 deltav_;
  ::google::protobuf::uint32 logged_;
  ::google::protobuf::uint32 unlogged_;
  ::google::protobuf::uint32 drivendevice_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SubCase : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.EdgeCase.SubCase) */ {
 public:
  SubCase();
  virtual ~SubCase();

  SubCase(const SubCase& from);

  inline SubCase& operator=(const SubCase& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SubCase(SubCase&& from) noexcept
    : SubCase() {
    *this = ::std::move(from);
  }

  inline SubCase& operator=(SubCase&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SubCase& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SubCase* internal_default_instance() {
    return reinterpret_cast<const SubCase*>(
               &_SubCase_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  void Swap(SubCase* other);
  friend void swap(SubCase& a, SubCase& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SubCase* New() const final {
    return CreateMaybeMessage<SubCase>(NULL);
  }

  SubCase* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SubCase>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SubCase& from);
  void MergeFrom(const SubCase& from);
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
  void InternalSwap(SubCase* other);
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

  // uint32 subvalue = 1;
  void clear_subvalue();
  static const int kSubvalueFieldNumber = 1;
  ::google::protobuf::uint32 subvalue() const;
  void set_subvalue(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.EdgeCase.SubCase)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 subvalue_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Settings

// fixed64 address = 1 [(.brewblox.field) = {
inline void Settings::clear_address() {
  address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Settings::address() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Settings.address)
  return address_;
}
inline void Settings::set_address(::google::protobuf::uint64 value) {
  
  address_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Settings.address)
}

// sint32 offset = 2 [(.brewblox.field) = {
inline void Settings::clear_offset() {
  offset_ = 0;
}
inline ::google::protobuf::int32 Settings::offset() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Settings.offset)
  return offset_;
}
inline void Settings::set_offset(::google::protobuf::int32 value) {
  
  offset_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Settings.offset)
}

// -------------------------------------------------------------------

// State

// sint32 value = 1 [(.brewblox.field) = {
inline void State::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 State::value() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.State.value)
  return value_;
}
inline void State::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.State.value)
}

// bool connected = 2 [(.brewblox.field) = {
inline void State::clear_connected() {
  connected_ = false;
}
inline bool State::connected() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.State.connected)
  return connected_;
}
inline void State::set_connected(bool value) {
  
  connected_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.State.connected)
}

// -------------------------------------------------------------------

// NestedLink

// uint32 connection = 1 [(.brewblox.field) = {
inline void NestedLink::clear_connection() {
  connection_ = 0u;
}
inline ::google::protobuf::uint32 NestedLink::connection() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.NestedLink.connection)
  return connection_;
}
inline void NestedLink::set_connection(::google::protobuf::uint32 value) {
  
  connection_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.NestedLink.connection)
}

// -------------------------------------------------------------------

// Block

// .blox_test.EdgeCase.Settings settings = 1;
inline bool Block::has_settings() const {
  return this != internal_default_instance() && settings_ != NULL;
}
inline void Block::clear_settings() {
  if (GetArenaNoVirtual() == NULL && settings_ != NULL) {
    delete settings_;
  }
  settings_ = NULL;
}
inline const ::blox_test::EdgeCase::Settings& Block::_internal_settings() const {
  return *settings_;
}
inline const ::blox_test::EdgeCase::Settings& Block::settings() const {
  const ::blox_test::EdgeCase::Settings* p = settings_;
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.settings)
  return p != NULL ? *p : *reinterpret_cast<const ::blox_test::EdgeCase::Settings*>(
      &::blox_test::EdgeCase::_Settings_default_instance_);
}
inline ::blox_test::EdgeCase::Settings* Block::release_settings() {
  // @@protoc_insertion_point(field_release:blox_test.EdgeCase.Block.settings)
  
  ::blox_test::EdgeCase::Settings* temp = settings_;
  settings_ = NULL;
  return temp;
}
inline ::blox_test::EdgeCase::Settings* Block::mutable_settings() {
  
  if (settings_ == NULL) {
    auto* p = CreateMaybeMessage<::blox_test::EdgeCase::Settings>(GetArenaNoVirtual());
    settings_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox_test.EdgeCase.Block.settings)
  return settings_;
}
inline void Block::set_allocated_settings(::blox_test::EdgeCase::Settings* settings) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete settings_;
  }
  if (settings) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      settings = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, settings, submessage_arena);
    }
    
  } else {
    
  }
  settings_ = settings;
  // @@protoc_insertion_point(field_set_allocated:blox_test.EdgeCase.Block.settings)
}

// .blox_test.EdgeCase.State state = 2;
inline bool Block::has_state() const {
  return this != internal_default_instance() && state_ != NULL;
}
inline void Block::clear_state() {
  if (GetArenaNoVirtual() == NULL && state_ != NULL) {
    delete state_;
  }
  state_ = NULL;
}
inline const ::blox_test::EdgeCase::State& Block::_internal_state() const {
  return *state_;
}
inline const ::blox_test::EdgeCase::State& Block::state() const {
  const ::blox_test::EdgeCase::State* p = state_;
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.state)
  return p != NULL ? *p : *reinterpret_cast<const ::blox_test::EdgeCase::State*>(
      &::blox_test::EdgeCase::_State_default_instance_);
}
inline ::blox_test::EdgeCase::State* Block::release_state() {
  // @@protoc_insertion_point(field_release:blox_test.EdgeCase.Block.state)
  
  ::blox_test::EdgeCase::State* temp = state_;
  state_ = NULL;
  return temp;
}
inline ::blox_test::EdgeCase::State* Block::mutable_state() {
  
  if (state_ == NULL) {
    auto* p = CreateMaybeMessage<::blox_test::EdgeCase::State>(GetArenaNoVirtual());
    state_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox_test.EdgeCase.Block.state)
  return state_;
}
inline void Block::set_allocated_state(::blox_test::EdgeCase::State* state) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete state_;
  }
  if (state) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      state = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, state, submessage_arena);
    }
    
  } else {
    
  }
  state_ = state;
  // @@protoc_insertion_point(field_set_allocated:blox_test.EdgeCase.Block.state)
}

// uint32 link = 3 [(.brewblox.field) = {
inline void Block::clear_link() {
  link_ = 0u;
}
inline ::google::protobuf::uint32 Block::link() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.link)
  return link_;
}
inline void Block::set_link(::google::protobuf::uint32 value) {
  
  link_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Block.link)
}

// repeated .blox_test.EdgeCase.NestedLink additionalLinks = 4;
inline int Block::additionallinks_size() const {
  return additionallinks_.size();
}
inline void Block::clear_additionallinks() {
  additionallinks_.Clear();
}
inline ::blox_test::EdgeCase::NestedLink* Block::mutable_additionallinks(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.EdgeCase.Block.additionalLinks)
  return additionallinks_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox_test::EdgeCase::NestedLink >*
Block::mutable_additionallinks() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.EdgeCase.Block.additionalLinks)
  return &additionallinks_;
}
inline const ::blox_test::EdgeCase::NestedLink& Block::additionallinks(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.additionalLinks)
  return additionallinks_.Get(index);
}
inline ::blox_test::EdgeCase::NestedLink* Block::add_additionallinks() {
  // @@protoc_insertion_point(field_add:blox_test.EdgeCase.Block.additionalLinks)
  return additionallinks_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox_test::EdgeCase::NestedLink >&
Block::additionallinks() const {
  // @@protoc_insertion_point(field_list:blox_test.EdgeCase.Block.additionalLinks)
  return additionallinks_;
}

// repeated float listValues = 5 [(.brewblox.field) = {
inline int Block::listvalues_size() const {
  return listvalues_.size();
}
inline void Block::clear_listvalues() {
  listvalues_.Clear();
}
inline float Block::listvalues(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.listValues)
  return listvalues_.Get(index);
}
inline void Block::set_listvalues(int index, float value) {
  listvalues_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Block.listValues)
}
inline void Block::add_listvalues(float value) {
  listvalues_.Add(value);
  // @@protoc_insertion_point(field_add:blox_test.EdgeCase.Block.listValues)
}
inline const ::google::protobuf::RepeatedField< float >&
Block::listvalues() const {
  // @@protoc_insertion_point(field_list:blox_test.EdgeCase.Block.listValues)
  return listvalues_;
}
inline ::google::protobuf::RepeatedField< float >*
Block::mutable_listvalues() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.EdgeCase.Block.listValues)
  return &listvalues_;
}

// uint32 deltaV = 6 [(.brewblox.field) = {
inline void Block::clear_deltav() {
  deltav_ = 0u;
}
inline ::google::protobuf::uint32 Block::deltav() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.deltaV)
  return deltav_;
}
inline void Block::set_deltav(::google::protobuf::uint32 value) {
  
  deltav_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Block.deltaV)
}

// uint32 logged = 7 [(.brewblox.field) = {
inline void Block::clear_logged() {
  logged_ = 0u;
}
inline ::google::protobuf::uint32 Block::logged() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.logged)
  return logged_;
}
inline void Block::set_logged(::google::protobuf::uint32 value) {
  
  logged_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Block.logged)
}

// uint32 unLogged = 8;
inline void Block::clear_unlogged() {
  unlogged_ = 0u;
}
inline ::google::protobuf::uint32 Block::unlogged() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.unLogged)
  return unlogged_;
}
inline void Block::set_unlogged(::google::protobuf::uint32 value) {
  
  unlogged_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Block.unLogged)
}

// uint32 drivenDevice = 9 [(.nanopb) = {
inline void Block::clear_drivendevice() {
  drivendevice_ = 0u;
}
inline ::google::protobuf::uint32 Block::drivendevice() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.Block.drivenDevice)
  return drivendevice_;
}
inline void Block::set_drivendevice(::google::protobuf::uint32 value) {
  
  drivendevice_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.Block.drivenDevice)
}

// -------------------------------------------------------------------

// SubCase

// uint32 subvalue = 1;
inline void SubCase::clear_subvalue() {
  subvalue_ = 0u;
}
inline ::google::protobuf::uint32 SubCase::subvalue() const {
  // @@protoc_insertion_point(field_get:blox_test.EdgeCase.SubCase.subvalue)
  return subvalue_;
}
inline void SubCase::set_subvalue(::google::protobuf::uint32 value) {
  
  subvalue_ = value;
  // @@protoc_insertion_point(field_set:blox_test.EdgeCase.SubCase.subvalue)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace EdgeCase
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_EdgeCase_5ftest_2eproto
