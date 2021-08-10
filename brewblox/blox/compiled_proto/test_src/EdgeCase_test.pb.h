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
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_EdgeCase_5ftest_2eproto
namespace blox {
class EdgeCase;
class EdgeCaseDefaultTypeInternal;
extern EdgeCaseDefaultTypeInternal _EdgeCase_default_instance_;
class NestedLink;
class NestedLinkDefaultTypeInternal;
extern NestedLinkDefaultTypeInternal _NestedLink_default_instance_;
class Settings;
class SettingsDefaultTypeInternal;
extern SettingsDefaultTypeInternal _Settings_default_instance_;
class State;
class StateDefaultTypeInternal;
extern StateDefaultTypeInternal _State_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::EdgeCase* Arena::CreateMaybeMessage<::blox::EdgeCase>(Arena*);
template<> ::blox::NestedLink* Arena::CreateMaybeMessage<::blox::NestedLink>(Arena*);
template<> ::blox::Settings* Arena::CreateMaybeMessage<::blox::Settings>(Arena*);
template<> ::blox::State* Arena::CreateMaybeMessage<::blox::State>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

// ===================================================================

class Settings : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Settings) */ {
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

  // fixed64 address = 1 [(.brewblox_test) = {
  void clear_address();
  static const int kAddressFieldNumber = 1;
  ::google::protobuf::uint64 address() const;
  void set_address(::google::protobuf::uint64 value);

  // sint32 offset = 2 [(.brewblox_test) = {
  void clear_offset();
  static const int kOffsetFieldNumber = 2;
  ::google::protobuf::int32 offset() const;
  void set_offset(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox.Settings)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 address_;
  ::google::protobuf::int32 offset_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class State : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.State) */ {
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

  // sint32 value = 1 [(.brewblox_test) = {
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // bool connected = 2 [(.brewblox_test) = {
  void clear_connected();
  static const int kConnectedFieldNumber = 2;
  bool connected() const;
  void set_connected(bool value);

  // @@protoc_insertion_point(class_scope:blox.State)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 value_;
  bool connected_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class NestedLink : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.NestedLink) */ {
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

  // uint32 connection = 1 [(.brewblox_test) = {
  void clear_connection();
  static const int kConnectionFieldNumber = 1;
  ::google::protobuf::uint32 connection() const;
  void set_connection(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.NestedLink)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 connection_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_EdgeCase_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class EdgeCase : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.EdgeCase) */ {
 public:
  EdgeCase();
  virtual ~EdgeCase();

  EdgeCase(const EdgeCase& from);

  inline EdgeCase& operator=(const EdgeCase& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  EdgeCase(EdgeCase&& from) noexcept
    : EdgeCase() {
    *this = ::std::move(from);
  }

  inline EdgeCase& operator=(EdgeCase&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const EdgeCase& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EdgeCase* internal_default_instance() {
    return reinterpret_cast<const EdgeCase*>(
               &_EdgeCase_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(EdgeCase* other);
  friend void swap(EdgeCase& a, EdgeCase& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline EdgeCase* New() const final {
    return CreateMaybeMessage<EdgeCase>(NULL);
  }

  EdgeCase* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<EdgeCase>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const EdgeCase& from);
  void MergeFrom(const EdgeCase& from);
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
  void InternalSwap(EdgeCase* other);
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

  // repeated .blox.NestedLink additionalLinks = 4;
  int additionallinks_size() const;
  void clear_additionallinks();
  static const int kAdditionalLinksFieldNumber = 4;
  ::blox::NestedLink* mutable_additionallinks(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::NestedLink >*
      mutable_additionallinks();
  const ::blox::NestedLink& additionallinks(int index) const;
  ::blox::NestedLink* add_additionallinks();
  const ::google::protobuf::RepeatedPtrField< ::blox::NestedLink >&
      additionallinks() const;

  // repeated float listValues = 5 [(.brewblox_test) = {
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

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  int strippedfields_size() const;
  void clear_strippedfields();
  static const int kStrippedFieldsFieldNumber = 99;
  ::google::protobuf::uint32 strippedfields(int index) const;
  void set_strippedfields(int index, ::google::protobuf::uint32 value);
  void add_strippedfields(::google::protobuf::uint32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      strippedfields() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_strippedfields();

  // .blox.Settings settings = 1;
  bool has_settings() const;
  void clear_settings();
  static const int kSettingsFieldNumber = 1;
  private:
  const ::blox::Settings& _internal_settings() const;
  public:
  const ::blox::Settings& settings() const;
  ::blox::Settings* release_settings();
  ::blox::Settings* mutable_settings();
  void set_allocated_settings(::blox::Settings* settings);

  // .blox.State state = 2;
  bool has_state() const;
  void clear_state();
  static const int kStateFieldNumber = 2;
  private:
  const ::blox::State& _internal_state() const;
  public:
  const ::blox::State& state() const;
  ::blox::State* release_state();
  ::blox::State* mutable_state();
  void set_allocated_state(::blox::State* state);

  // uint32 link = 3 [(.brewblox_test) = {
  void clear_link();
  static const int kLinkFieldNumber = 3;
  ::google::protobuf::uint32 link() const;
  void set_link(::google::protobuf::uint32 value);

  // uint32 deltaV = 6 [(.brewblox_test) = {
  void clear_deltav();
  static const int kDeltaVFieldNumber = 6;
  ::google::protobuf::uint32 deltav() const;
  void set_deltav(::google::protobuf::uint32 value);

  // uint32 logged = 7 [(.brewblox_test) = {
  void clear_logged();
  static const int kLoggedFieldNumber = 7;
  ::google::protobuf::uint32 logged() const;
  void set_logged(::google::protobuf::uint32 value);

  // uint32 unLogged = 8;
  void clear_unlogged();
  static const int kUnLoggedFieldNumber = 8;
  ::google::protobuf::uint32 unlogged() const;
  void set_unlogged(::google::protobuf::uint32 value);

  // uint32 drivenDevice = 9 [(.nanopb_test) = {
  void clear_drivendevice();
  static const int kDrivenDeviceFieldNumber = 9;
  ::google::protobuf::uint32 drivendevice() const;
  void set_drivendevice(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.EdgeCase)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::NestedLink > additionallinks_;
  ::google::protobuf::RepeatedField< float > listvalues_;
  mutable int _listvalues_cached_byte_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > strippedfields_;
  mutable int _strippedfields_cached_byte_size_;
  ::blox::Settings* settings_;
  ::blox::State* state_;
  ::google::protobuf::uint32 link_;
  ::google::protobuf::uint32 deltav_;
  ::google::protobuf::uint32 logged_;
  ::google::protobuf::uint32 unlogged_;
  ::google::protobuf::uint32 drivendevice_;
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

// fixed64 address = 1 [(.brewblox_test) = {
inline void Settings::clear_address() {
  address_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 Settings::address() const {
  // @@protoc_insertion_point(field_get:blox.Settings.address)
  return address_;
}
inline void Settings::set_address(::google::protobuf::uint64 value) {
  
  address_ = value;
  // @@protoc_insertion_point(field_set:blox.Settings.address)
}

// sint32 offset = 2 [(.brewblox_test) = {
inline void Settings::clear_offset() {
  offset_ = 0;
}
inline ::google::protobuf::int32 Settings::offset() const {
  // @@protoc_insertion_point(field_get:blox.Settings.offset)
  return offset_;
}
inline void Settings::set_offset(::google::protobuf::int32 value) {
  
  offset_ = value;
  // @@protoc_insertion_point(field_set:blox.Settings.offset)
}

// -------------------------------------------------------------------

// State

// sint32 value = 1 [(.brewblox_test) = {
inline void State::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 State::value() const {
  // @@protoc_insertion_point(field_get:blox.State.value)
  return value_;
}
inline void State::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:blox.State.value)
}

// bool connected = 2 [(.brewblox_test) = {
inline void State::clear_connected() {
  connected_ = false;
}
inline bool State::connected() const {
  // @@protoc_insertion_point(field_get:blox.State.connected)
  return connected_;
}
inline void State::set_connected(bool value) {
  
  connected_ = value;
  // @@protoc_insertion_point(field_set:blox.State.connected)
}

// -------------------------------------------------------------------

// NestedLink

// uint32 connection = 1 [(.brewblox_test) = {
inline void NestedLink::clear_connection() {
  connection_ = 0u;
}
inline ::google::protobuf::uint32 NestedLink::connection() const {
  // @@protoc_insertion_point(field_get:blox.NestedLink.connection)
  return connection_;
}
inline void NestedLink::set_connection(::google::protobuf::uint32 value) {
  
  connection_ = value;
  // @@protoc_insertion_point(field_set:blox.NestedLink.connection)
}

// -------------------------------------------------------------------

// EdgeCase

// .blox.Settings settings = 1;
inline bool EdgeCase::has_settings() const {
  return this != internal_default_instance() && settings_ != NULL;
}
inline void EdgeCase::clear_settings() {
  if (GetArenaNoVirtual() == NULL && settings_ != NULL) {
    delete settings_;
  }
  settings_ = NULL;
}
inline const ::blox::Settings& EdgeCase::_internal_settings() const {
  return *settings_;
}
inline const ::blox::Settings& EdgeCase::settings() const {
  const ::blox::Settings* p = settings_;
  // @@protoc_insertion_point(field_get:blox.EdgeCase.settings)
  return p != NULL ? *p : *reinterpret_cast<const ::blox::Settings*>(
      &::blox::_Settings_default_instance_);
}
inline ::blox::Settings* EdgeCase::release_settings() {
  // @@protoc_insertion_point(field_release:blox.EdgeCase.settings)
  
  ::blox::Settings* temp = settings_;
  settings_ = NULL;
  return temp;
}
inline ::blox::Settings* EdgeCase::mutable_settings() {
  
  if (settings_ == NULL) {
    auto* p = CreateMaybeMessage<::blox::Settings>(GetArenaNoVirtual());
    settings_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox.EdgeCase.settings)
  return settings_;
}
inline void EdgeCase::set_allocated_settings(::blox::Settings* settings) {
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
  // @@protoc_insertion_point(field_set_allocated:blox.EdgeCase.settings)
}

// .blox.State state = 2;
inline bool EdgeCase::has_state() const {
  return this != internal_default_instance() && state_ != NULL;
}
inline void EdgeCase::clear_state() {
  if (GetArenaNoVirtual() == NULL && state_ != NULL) {
    delete state_;
  }
  state_ = NULL;
}
inline const ::blox::State& EdgeCase::_internal_state() const {
  return *state_;
}
inline const ::blox::State& EdgeCase::state() const {
  const ::blox::State* p = state_;
  // @@protoc_insertion_point(field_get:blox.EdgeCase.state)
  return p != NULL ? *p : *reinterpret_cast<const ::blox::State*>(
      &::blox::_State_default_instance_);
}
inline ::blox::State* EdgeCase::release_state() {
  // @@protoc_insertion_point(field_release:blox.EdgeCase.state)
  
  ::blox::State* temp = state_;
  state_ = NULL;
  return temp;
}
inline ::blox::State* EdgeCase::mutable_state() {
  
  if (state_ == NULL) {
    auto* p = CreateMaybeMessage<::blox::State>(GetArenaNoVirtual());
    state_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox.EdgeCase.state)
  return state_;
}
inline void EdgeCase::set_allocated_state(::blox::State* state) {
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
  // @@protoc_insertion_point(field_set_allocated:blox.EdgeCase.state)
}

// uint32 link = 3 [(.brewblox_test) = {
inline void EdgeCase::clear_link() {
  link_ = 0u;
}
inline ::google::protobuf::uint32 EdgeCase::link() const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.link)
  return link_;
}
inline void EdgeCase::set_link(::google::protobuf::uint32 value) {
  
  link_ = value;
  // @@protoc_insertion_point(field_set:blox.EdgeCase.link)
}

// repeated .blox.NestedLink additionalLinks = 4;
inline int EdgeCase::additionallinks_size() const {
  return additionallinks_.size();
}
inline void EdgeCase::clear_additionallinks() {
  additionallinks_.Clear();
}
inline ::blox::NestedLink* EdgeCase::mutable_additionallinks(int index) {
  // @@protoc_insertion_point(field_mutable:blox.EdgeCase.additionalLinks)
  return additionallinks_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::NestedLink >*
EdgeCase::mutable_additionallinks() {
  // @@protoc_insertion_point(field_mutable_list:blox.EdgeCase.additionalLinks)
  return &additionallinks_;
}
inline const ::blox::NestedLink& EdgeCase::additionallinks(int index) const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.additionalLinks)
  return additionallinks_.Get(index);
}
inline ::blox::NestedLink* EdgeCase::add_additionallinks() {
  // @@protoc_insertion_point(field_add:blox.EdgeCase.additionalLinks)
  return additionallinks_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::NestedLink >&
EdgeCase::additionallinks() const {
  // @@protoc_insertion_point(field_list:blox.EdgeCase.additionalLinks)
  return additionallinks_;
}

// repeated float listValues = 5 [(.brewblox_test) = {
inline int EdgeCase::listvalues_size() const {
  return listvalues_.size();
}
inline void EdgeCase::clear_listvalues() {
  listvalues_.Clear();
}
inline float EdgeCase::listvalues(int index) const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.listValues)
  return listvalues_.Get(index);
}
inline void EdgeCase::set_listvalues(int index, float value) {
  listvalues_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.EdgeCase.listValues)
}
inline void EdgeCase::add_listvalues(float value) {
  listvalues_.Add(value);
  // @@protoc_insertion_point(field_add:blox.EdgeCase.listValues)
}
inline const ::google::protobuf::RepeatedField< float >&
EdgeCase::listvalues() const {
  // @@protoc_insertion_point(field_list:blox.EdgeCase.listValues)
  return listvalues_;
}
inline ::google::protobuf::RepeatedField< float >*
EdgeCase::mutable_listvalues() {
  // @@protoc_insertion_point(field_mutable_list:blox.EdgeCase.listValues)
  return &listvalues_;
}

// uint32 deltaV = 6 [(.brewblox_test) = {
inline void EdgeCase::clear_deltav() {
  deltav_ = 0u;
}
inline ::google::protobuf::uint32 EdgeCase::deltav() const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.deltaV)
  return deltav_;
}
inline void EdgeCase::set_deltav(::google::protobuf::uint32 value) {
  
  deltav_ = value;
  // @@protoc_insertion_point(field_set:blox.EdgeCase.deltaV)
}

// uint32 logged = 7 [(.brewblox_test) = {
inline void EdgeCase::clear_logged() {
  logged_ = 0u;
}
inline ::google::protobuf::uint32 EdgeCase::logged() const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.logged)
  return logged_;
}
inline void EdgeCase::set_logged(::google::protobuf::uint32 value) {
  
  logged_ = value;
  // @@protoc_insertion_point(field_set:blox.EdgeCase.logged)
}

// uint32 unLogged = 8;
inline void EdgeCase::clear_unlogged() {
  unlogged_ = 0u;
}
inline ::google::protobuf::uint32 EdgeCase::unlogged() const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.unLogged)
  return unlogged_;
}
inline void EdgeCase::set_unlogged(::google::protobuf::uint32 value) {
  
  unlogged_ = value;
  // @@protoc_insertion_point(field_set:blox.EdgeCase.unLogged)
}

// uint32 drivenDevice = 9 [(.nanopb_test) = {
inline void EdgeCase::clear_drivendevice() {
  drivendevice_ = 0u;
}
inline ::google::protobuf::uint32 EdgeCase::drivendevice() const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.drivenDevice)
  return drivendevice_;
}
inline void EdgeCase::set_drivendevice(::google::protobuf::uint32 value) {
  
  drivendevice_ = value;
  // @@protoc_insertion_point(field_set:blox.EdgeCase.drivenDevice)
}

// repeated uint32 strippedFields = 99 [(.nanopb_test) = {
inline int EdgeCase::strippedfields_size() const {
  return strippedfields_.size();
}
inline void EdgeCase::clear_strippedfields() {
  strippedfields_.Clear();
}
inline ::google::protobuf::uint32 EdgeCase::strippedfields(int index) const {
  // @@protoc_insertion_point(field_get:blox.EdgeCase.strippedFields)
  return strippedfields_.Get(index);
}
inline void EdgeCase::set_strippedfields(int index, ::google::protobuf::uint32 value) {
  strippedfields_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.EdgeCase.strippedFields)
}
inline void EdgeCase::add_strippedfields(::google::protobuf::uint32 value) {
  strippedfields_.Add(value);
  // @@protoc_insertion_point(field_add:blox.EdgeCase.strippedFields)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
EdgeCase::strippedfields() const {
  // @@protoc_insertion_point(field_list:blox.EdgeCase.strippedFields)
  return strippedfields_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
EdgeCase::mutable_strippedfields() {
  // @@protoc_insertion_point(field_mutable_list:blox.EdgeCase.strippedFields)
  return &strippedfields_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_EdgeCase_5ftest_2eproto
