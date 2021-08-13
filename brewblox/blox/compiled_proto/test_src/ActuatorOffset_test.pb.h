// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ActuatorOffset_test.proto

#ifndef PROTOBUF_INCLUDED_ActuatorOffset_5ftest_2eproto
#define PROTOBUF_INCLUDED_ActuatorOffset_5ftest_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
#include "AnalogConstraints_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_ActuatorOffset_5ftest_2eproto 

namespace protobuf_ActuatorOffset_5ftest_2eproto {
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
}  // namespace protobuf_ActuatorOffset_5ftest_2eproto
namespace blox {
class ActuatorOffset;
class ActuatorOffsetDefaultTypeInternal;
extern ActuatorOffsetDefaultTypeInternal _ActuatorOffset_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::ActuatorOffset* Arena::CreateMaybeMessage<::blox::ActuatorOffset>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

enum ActuatorOffset_ReferenceKind {
  ActuatorOffset_ReferenceKind_REF_SETTING = 0,
  ActuatorOffset_ReferenceKind_REF_VALUE = 1,
  ActuatorOffset_ReferenceKind_ActuatorOffset_ReferenceKind_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ActuatorOffset_ReferenceKind_ActuatorOffset_ReferenceKind_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ActuatorOffset_ReferenceKind_IsValid(int value);
const ActuatorOffset_ReferenceKind ActuatorOffset_ReferenceKind_ReferenceKind_MIN = ActuatorOffset_ReferenceKind_REF_SETTING;
const ActuatorOffset_ReferenceKind ActuatorOffset_ReferenceKind_ReferenceKind_MAX = ActuatorOffset_ReferenceKind_REF_VALUE;
const int ActuatorOffset_ReferenceKind_ReferenceKind_ARRAYSIZE = ActuatorOffset_ReferenceKind_ReferenceKind_MAX + 1;

const ::google::protobuf::EnumDescriptor* ActuatorOffset_ReferenceKind_descriptor();
inline const ::std::string& ActuatorOffset_ReferenceKind_Name(ActuatorOffset_ReferenceKind value) {
  return ::google::protobuf::internal::NameOfEnum(
    ActuatorOffset_ReferenceKind_descriptor(), value);
}
inline bool ActuatorOffset_ReferenceKind_Parse(
    const ::std::string& name, ActuatorOffset_ReferenceKind* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ActuatorOffset_ReferenceKind>(
    ActuatorOffset_ReferenceKind_descriptor(), name, value);
}
// ===================================================================

class ActuatorOffset : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.ActuatorOffset) */ {
 public:
  ActuatorOffset();
  virtual ~ActuatorOffset();

  ActuatorOffset(const ActuatorOffset& from);

  inline ActuatorOffset& operator=(const ActuatorOffset& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ActuatorOffset(ActuatorOffset&& from) noexcept
    : ActuatorOffset() {
    *this = ::std::move(from);
  }

  inline ActuatorOffset& operator=(ActuatorOffset&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ActuatorOffset& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ActuatorOffset* internal_default_instance() {
    return reinterpret_cast<const ActuatorOffset*>(
               &_ActuatorOffset_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ActuatorOffset* other);
  friend void swap(ActuatorOffset& a, ActuatorOffset& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ActuatorOffset* New() const final {
    return CreateMaybeMessage<ActuatorOffset>(NULL);
  }

  ActuatorOffset* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ActuatorOffset>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ActuatorOffset& from);
  void MergeFrom(const ActuatorOffset& from);
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
  void InternalSwap(ActuatorOffset* other);
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

  typedef ActuatorOffset_ReferenceKind ReferenceKind;
  static const ReferenceKind REF_SETTING =
    ActuatorOffset_ReferenceKind_REF_SETTING;
  static const ReferenceKind REF_VALUE =
    ActuatorOffset_ReferenceKind_REF_VALUE;
  static inline bool ReferenceKind_IsValid(int value) {
    return ActuatorOffset_ReferenceKind_IsValid(value);
  }
  static const ReferenceKind ReferenceKind_MIN =
    ActuatorOffset_ReferenceKind_ReferenceKind_MIN;
  static const ReferenceKind ReferenceKind_MAX =
    ActuatorOffset_ReferenceKind_ReferenceKind_MAX;
  static const int ReferenceKind_ARRAYSIZE =
    ActuatorOffset_ReferenceKind_ReferenceKind_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  ReferenceKind_descriptor() {
    return ActuatorOffset_ReferenceKind_descriptor();
  }
  static inline const ::std::string& ReferenceKind_Name(ReferenceKind value) {
    return ActuatorOffset_ReferenceKind_Name(value);
  }
  static inline bool ReferenceKind_Parse(const ::std::string& name,
      ReferenceKind* value) {
    return ActuatorOffset_ReferenceKind_Parse(name, value);
  }

  // accessors -------------------------------------------------------

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

  // .blox.AnalogConstraints constrainedBy = 8;
  bool has_constrainedby() const;
  void clear_constrainedby();
  static const int kConstrainedByFieldNumber = 8;
  private:
  const ::blox::AnalogConstraints& _internal_constrainedby() const;
  public:
  const ::blox::AnalogConstraints& constrainedby() const;
  ::blox::AnalogConstraints* release_constrainedby();
  ::blox::AnalogConstraints* mutable_constrainedby();
  void set_allocated_constrainedby(::blox::AnalogConstraints* constrainedby);

  // uint32 targetId = 1 [(.nanopb_test) = {
  void clear_targetid();
  static const int kTargetIdFieldNumber = 1;
  ::google::protobuf::uint32 targetid() const;
  void set_targetid(::google::protobuf::uint32 value);

  // uint32 referenceId = 3 [(.nanopb_test) = {
  void clear_referenceid();
  static const int kReferenceIdFieldNumber = 3;
  ::google::protobuf::uint32 referenceid() const;
  void set_referenceid(::google::protobuf::uint32 value);

  // .blox.ActuatorOffset.ReferenceKind referenceSettingOrValue = 4;
  void clear_referencesettingorvalue();
  static const int kReferenceSettingOrValueFieldNumber = 4;
  ::blox::ActuatorOffset_ReferenceKind referencesettingorvalue() const;
  void set_referencesettingorvalue(::blox::ActuatorOffset_ReferenceKind value);

  // sint32 setting = 6 [(.nanopb_test) = {
  void clear_setting();
  static const int kSettingFieldNumber = 6;
  ::google::protobuf::int32 setting() const;
  void set_setting(::google::protobuf::int32 value);

  // sint32 value = 7 [(.nanopb_test) = {
  void clear_value();
  static const int kValueFieldNumber = 7;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // uint32 drivenTargetId = 9 [(.nanopb_test) = {
  void clear_driventargetid();
  static const int kDrivenTargetIdFieldNumber = 9;
  ::google::protobuf::uint32 driventargetid() const;
  void set_driventargetid(::google::protobuf::uint32 value);

  // bool enabled = 10;
  void clear_enabled();
  static const int kEnabledFieldNumber = 10;
  bool enabled() const;
  void set_enabled(bool value);

  // sint32 desiredSetting = 11 [(.nanopb_test) = {
  void clear_desiredsetting();
  static const int kDesiredSettingFieldNumber = 11;
  ::google::protobuf::int32 desiredsetting() const;
  void set_desiredsetting(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox.ActuatorOffset)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > strippedfields_;
  mutable int _strippedfields_cached_byte_size_;
  ::blox::AnalogConstraints* constrainedby_;
  ::google::protobuf::uint32 targetid_;
  ::google::protobuf::uint32 referenceid_;
  int referencesettingorvalue_;
  ::google::protobuf::int32 setting_;
  ::google::protobuf::int32 value_;
  ::google::protobuf::uint32 driventargetid_;
  bool enabled_;
  ::google::protobuf::int32 desiredsetting_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_ActuatorOffset_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ActuatorOffset

// uint32 targetId = 1 [(.nanopb_test) = {
inline void ActuatorOffset::clear_targetid() {
  targetid_ = 0u;
}
inline ::google::protobuf::uint32 ActuatorOffset::targetid() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.targetId)
  return targetid_;
}
inline void ActuatorOffset::set_targetid(::google::protobuf::uint32 value) {
  
  targetid_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.targetId)
}

// uint32 referenceId = 3 [(.nanopb_test) = {
inline void ActuatorOffset::clear_referenceid() {
  referenceid_ = 0u;
}
inline ::google::protobuf::uint32 ActuatorOffset::referenceid() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.referenceId)
  return referenceid_;
}
inline void ActuatorOffset::set_referenceid(::google::protobuf::uint32 value) {
  
  referenceid_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.referenceId)
}

// .blox.ActuatorOffset.ReferenceKind referenceSettingOrValue = 4;
inline void ActuatorOffset::clear_referencesettingorvalue() {
  referencesettingorvalue_ = 0;
}
inline ::blox::ActuatorOffset_ReferenceKind ActuatorOffset::referencesettingorvalue() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.referenceSettingOrValue)
  return static_cast< ::blox::ActuatorOffset_ReferenceKind >(referencesettingorvalue_);
}
inline void ActuatorOffset::set_referencesettingorvalue(::blox::ActuatorOffset_ReferenceKind value) {
  
  referencesettingorvalue_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.referenceSettingOrValue)
}

// sint32 setting = 6 [(.nanopb_test) = {
inline void ActuatorOffset::clear_setting() {
  setting_ = 0;
}
inline ::google::protobuf::int32 ActuatorOffset::setting() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.setting)
  return setting_;
}
inline void ActuatorOffset::set_setting(::google::protobuf::int32 value) {
  
  setting_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.setting)
}

// sint32 value = 7 [(.nanopb_test) = {
inline void ActuatorOffset::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 ActuatorOffset::value() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.value)
  return value_;
}
inline void ActuatorOffset::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.value)
}

// .blox.AnalogConstraints constrainedBy = 8;
inline bool ActuatorOffset::has_constrainedby() const {
  return this != internal_default_instance() && constrainedby_ != NULL;
}
inline const ::blox::AnalogConstraints& ActuatorOffset::_internal_constrainedby() const {
  return *constrainedby_;
}
inline const ::blox::AnalogConstraints& ActuatorOffset::constrainedby() const {
  const ::blox::AnalogConstraints* p = constrainedby_;
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.constrainedBy)
  return p != NULL ? *p : *reinterpret_cast<const ::blox::AnalogConstraints*>(
      &::blox::_AnalogConstraints_default_instance_);
}
inline ::blox::AnalogConstraints* ActuatorOffset::release_constrainedby() {
  // @@protoc_insertion_point(field_release:blox.ActuatorOffset.constrainedBy)
  
  ::blox::AnalogConstraints* temp = constrainedby_;
  constrainedby_ = NULL;
  return temp;
}
inline ::blox::AnalogConstraints* ActuatorOffset::mutable_constrainedby() {
  
  if (constrainedby_ == NULL) {
    auto* p = CreateMaybeMessage<::blox::AnalogConstraints>(GetArenaNoVirtual());
    constrainedby_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox.ActuatorOffset.constrainedBy)
  return constrainedby_;
}
inline void ActuatorOffset::set_allocated_constrainedby(::blox::AnalogConstraints* constrainedby) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(constrainedby_);
  }
  if (constrainedby) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      constrainedby = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, constrainedby, submessage_arena);
    }
    
  } else {
    
  }
  constrainedby_ = constrainedby;
  // @@protoc_insertion_point(field_set_allocated:blox.ActuatorOffset.constrainedBy)
}

// uint32 drivenTargetId = 9 [(.nanopb_test) = {
inline void ActuatorOffset::clear_driventargetid() {
  driventargetid_ = 0u;
}
inline ::google::protobuf::uint32 ActuatorOffset::driventargetid() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.drivenTargetId)
  return driventargetid_;
}
inline void ActuatorOffset::set_driventargetid(::google::protobuf::uint32 value) {
  
  driventargetid_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.drivenTargetId)
}

// bool enabled = 10;
inline void ActuatorOffset::clear_enabled() {
  enabled_ = false;
}
inline bool ActuatorOffset::enabled() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.enabled)
  return enabled_;
}
inline void ActuatorOffset::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.enabled)
}

// sint32 desiredSetting = 11 [(.nanopb_test) = {
inline void ActuatorOffset::clear_desiredsetting() {
  desiredsetting_ = 0;
}
inline ::google::protobuf::int32 ActuatorOffset::desiredsetting() const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.desiredSetting)
  return desiredsetting_;
}
inline void ActuatorOffset::set_desiredsetting(::google::protobuf::int32 value) {
  
  desiredsetting_ = value;
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.desiredSetting)
}

// repeated uint32 strippedFields = 99 [(.nanopb_test) = {
inline int ActuatorOffset::strippedfields_size() const {
  return strippedfields_.size();
}
inline void ActuatorOffset::clear_strippedfields() {
  strippedfields_.Clear();
}
inline ::google::protobuf::uint32 ActuatorOffset::strippedfields(int index) const {
  // @@protoc_insertion_point(field_get:blox.ActuatorOffset.strippedFields)
  return strippedfields_.Get(index);
}
inline void ActuatorOffset::set_strippedfields(int index, ::google::protobuf::uint32 value) {
  strippedfields_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.ActuatorOffset.strippedFields)
}
inline void ActuatorOffset::add_strippedfields(::google::protobuf::uint32 value) {
  strippedfields_.Add(value);
  // @@protoc_insertion_point(field_add:blox.ActuatorOffset.strippedFields)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
ActuatorOffset::strippedfields() const {
  // @@protoc_insertion_point(field_list:blox.ActuatorOffset.strippedFields)
  return strippedfields_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
ActuatorOffset::mutable_strippedfields() {
  // @@protoc_insertion_point(field_mutable_list:blox.ActuatorOffset.strippedFields)
  return &strippedfields_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox::ActuatorOffset_ReferenceKind> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::ActuatorOffset_ReferenceKind>() {
  return ::blox::ActuatorOffset_ReferenceKind_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_ActuatorOffset_5ftest_2eproto
