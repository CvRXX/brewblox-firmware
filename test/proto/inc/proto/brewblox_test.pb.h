// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: brewblox_test.proto

#ifndef PROTOBUF_INCLUDED_brewblox_5ftest_2eproto
#define PROTOBUF_INCLUDED_brewblox_5ftest_2eproto

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
#include <google/protobuf/descriptor.pb.h>
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_brewblox_5ftest_2eproto 

namespace protobuf_brewblox_5ftest_2eproto {
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
}  // namespace protobuf_brewblox_5ftest_2eproto
namespace brewblox {
class FieldOpts;
class FieldOptsDefaultTypeInternal;
extern FieldOptsDefaultTypeInternal _FieldOpts_default_instance_;
class MessageOpts;
class MessageOptsDefaultTypeInternal;
extern MessageOptsDefaultTypeInternal _MessageOpts_default_instance_;
}  // namespace brewblox
namespace google {
namespace protobuf {
template<> ::brewblox::FieldOpts* Arena::CreateMaybeMessage<::brewblox::FieldOpts>(Arena*);
template<> ::brewblox::MessageOpts* Arena::CreateMaybeMessage<::brewblox::MessageOpts>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace brewblox {

enum UnitType {
  NotSet = 0,
  Celsius = 1,
  InverseCelsius = 2,
  Second = 3,
  Minute = 4,
  Hour = 5,
  DeltaCelsius = 6,
  DeltaCelsiusPerSecond = 7,
  DeltaCelsiusPerMinute = 8,
  DeltaCelsiusPerHour = 9,
  DeltaCelsiusMultSecond = 10,
  DeltaCelsiusMultMinute = 11,
  DeltaCelsiusMultHour = 12,
  UnitType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  UnitType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool UnitType_IsValid(int value);
const UnitType UnitType_MIN = NotSet;
const UnitType UnitType_MAX = DeltaCelsiusMultHour;
const int UnitType_ARRAYSIZE = UnitType_MAX + 1;

const ::google::protobuf::EnumDescriptor* UnitType_descriptor();
inline const ::std::string& UnitType_Name(UnitType value) {
  return ::google::protobuf::internal::NameOfEnum(
    UnitType_descriptor(), value);
}
inline bool UnitType_Parse(
    const ::std::string& name, UnitType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<UnitType>(
    UnitType_descriptor(), name, value);
}
enum BlockType {
  Invalid = 0,
  ProcessValueInterface = 1,
  TempSensorInterface = 2,
  SetpointSensorPairInterface = 4,
  ActuatorAnalogInterface = 5,
  ActuatorDigitalInterface = 6,
  BalancerInterface = 7,
  MutexInterface = 8,
  OneWireDeviceInterface = 9,
  IoArrayInterface = 10,
  DS2408Interface = 11,
  OneWireBusInterface = 12,
  IoModuleInterface = 13,
  OneWireDeviceBlockInterface = 14,
  Any = 255,
  SysInfo = 256,
  Ticks = 257,
  OneWireBus = 258,
  BoardPins = 259,
  TempSensorMock = 301,
  TempSensorOneWire = 302,
  SetpointSensorPair = 303,
  Pid = 304,
  ActuatorAnalogMock = 305,
  ActuatorPin = 306,
  ActuatorPwm = 307,
  ActuatorOffset = 308,
  Balancer = 309,
  Mutex = 310,
  SetpointProfile = 311,
  WiFiSettings = 312,
  TouchSettings = 313,
  DisplaySettings = 314,
  DS2413 = 315,
  ActuatorOneWire = 316,
  DS2408 = 317,
  DigitalActuator = 318,
  Spark3Pins = 319,
  Spark2Pins = 320,
  MotorValve = 321,
  ActuatorLogic = 322,
  MockPins = 323,
  TempSensorCombi = 324,
  OneWireGpioModule = 325,
  Stepper = 326,
  BlockType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  BlockType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool BlockType_IsValid(int value);
const BlockType BlockType_MIN = Invalid;
const BlockType BlockType_MAX = Stepper;
const int BlockType_ARRAYSIZE = BlockType_MAX + 1;

const ::google::protobuf::EnumDescriptor* BlockType_descriptor();
inline const ::std::string& BlockType_Name(BlockType value) {
  return ::google::protobuf::internal::NameOfEnum(
    BlockType_descriptor(), value);
}
inline bool BlockType_Parse(
    const ::std::string& name, BlockType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<BlockType>(
    BlockType_descriptor(), name, value);
}
// ===================================================================

class MessageOpts : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:brewblox.MessageOpts) */ {
 public:
  MessageOpts();
  virtual ~MessageOpts();

  MessageOpts(const MessageOpts& from);

  inline MessageOpts& operator=(const MessageOpts& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MessageOpts(MessageOpts&& from) noexcept
    : MessageOpts() {
    *this = ::std::move(from);
  }

  inline MessageOpts& operator=(MessageOpts&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MessageOpts& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MessageOpts* internal_default_instance() {
    return reinterpret_cast<const MessageOpts*>(
               &_MessageOpts_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(MessageOpts* other);
  friend void swap(MessageOpts& a, MessageOpts& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MessageOpts* New() const final {
    return CreateMaybeMessage<MessageOpts>(NULL);
  }

  MessageOpts* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MessageOpts>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MessageOpts& from);
  void MergeFrom(const MessageOpts& from);
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
  void InternalSwap(MessageOpts* other);
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

  // repeated .brewblox.BlockType impl = 9 [(.nanopb) = {
  int impl_size() const;
  void clear_impl();
  static const int kImplFieldNumber = 9;
  ::brewblox::BlockType impl(int index) const;
  void set_impl(int index, ::brewblox::BlockType value);
  void add_impl(::brewblox::BlockType value);
  const ::google::protobuf::RepeatedField<int>& impl() const;
  ::google::protobuf::RepeatedField<int>* mutable_impl();

  // .brewblox.BlockType objtype = 3;
  void clear_objtype();
  static const int kObjtypeFieldNumber = 3;
  ::brewblox::BlockType objtype() const;
  void set_objtype(::brewblox::BlockType value);

  // uint32 subtype = 11 [(.nanopb) = {
  void clear_subtype();
  static const int kSubtypeFieldNumber = 11;
  ::google::protobuf::uint32 subtype() const;
  void set_subtype(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:brewblox.MessageOpts)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField<int> impl_;
  mutable int _impl_cached_byte_size_;
  int objtype_;
  ::google::protobuf::uint32 subtype_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_brewblox_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class FieldOpts : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:brewblox.FieldOpts) */ {
 public:
  FieldOpts();
  virtual ~FieldOpts();

  FieldOpts(const FieldOpts& from);

  inline FieldOpts& operator=(const FieldOpts& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FieldOpts(FieldOpts&& from) noexcept
    : FieldOpts() {
    *this = ::std::move(from);
  }

  inline FieldOpts& operator=(FieldOpts&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FieldOpts& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FieldOpts* internal_default_instance() {
    return reinterpret_cast<const FieldOpts*>(
               &_FieldOpts_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(FieldOpts* other);
  friend void swap(FieldOpts& a, FieldOpts& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FieldOpts* New() const final {
    return CreateMaybeMessage<FieldOpts>(NULL);
  }

  FieldOpts* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<FieldOpts>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const FieldOpts& from);
  void MergeFrom(const FieldOpts& from);
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
  void InternalSwap(FieldOpts* other);
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

  // .brewblox.UnitType unit = 1;
  void clear_unit();
  static const int kUnitFieldNumber = 1;
  ::brewblox::UnitType unit() const;
  void set_unit(::brewblox::UnitType value);

  // uint32 scale = 2;
  void clear_scale();
  static const int kScaleFieldNumber = 2;
  ::google::protobuf::uint32 scale() const;
  void set_scale(::google::protobuf::uint32 value);

  // .brewblox.BlockType objtype = 3;
  void clear_objtype();
  static const int kObjtypeFieldNumber = 3;
  ::brewblox::BlockType objtype() const;
  void set_objtype(::brewblox::BlockType value);

  // bool hexed = 4;
  void clear_hexed();
  static const int kHexedFieldNumber = 4;
  bool hexed() const;
  void set_hexed(bool value);

  // bool readonly = 5;
  void clear_readonly();
  static const int kReadonlyFieldNumber = 5;
  bool readonly() const;
  void set_readonly(bool value);

  // bool logged = 6;
  void clear_logged();
  static const int kLoggedFieldNumber = 6;
  bool logged() const;
  void set_logged(bool value);

  // bool hexstr = 7;
  void clear_hexstr();
  static const int kHexstrFieldNumber = 7;
  bool hexstr() const;
  void set_hexstr(bool value);

  // bool driven = 8;
  void clear_driven();
  static const int kDrivenFieldNumber = 8;
  bool driven() const;
  void set_driven(bool value);

  // bool ignored = 9;
  void clear_ignored();
  static const int kIgnoredFieldNumber = 9;
  bool ignored() const;
  void set_ignored(bool value);

  // bool bitfield = 10;
  void clear_bitfield();
  static const int kBitfieldFieldNumber = 10;
  bool bitfield() const;
  void set_bitfield(bool value);

  // @@protoc_insertion_point(class_scope:brewblox.FieldOpts)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int unit_;
  ::google::protobuf::uint32 scale_;
  int objtype_;
  bool hexed_;
  bool readonly_;
  bool logged_;
  bool hexstr_;
  bool driven_;
  bool ignored_;
  bool bitfield_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_brewblox_5ftest_2eproto::TableStruct;
};
// ===================================================================

static const int kFieldFieldNumber = 50001;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FieldOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::brewblox::FieldOpts >, 11, false >
  field;
static const int kMsgFieldNumber = 50001;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MessageOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::brewblox::MessageOpts >, 11, false >
  msg;

// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MessageOpts

// .brewblox.BlockType objtype = 3;
inline void MessageOpts::clear_objtype() {
  objtype_ = 0;
}
inline ::brewblox::BlockType MessageOpts::objtype() const {
  // @@protoc_insertion_point(field_get:brewblox.MessageOpts.objtype)
  return static_cast< ::brewblox::BlockType >(objtype_);
}
inline void MessageOpts::set_objtype(::brewblox::BlockType value) {
  
  objtype_ = value;
  // @@protoc_insertion_point(field_set:brewblox.MessageOpts.objtype)
}

// repeated .brewblox.BlockType impl = 9 [(.nanopb) = {
inline int MessageOpts::impl_size() const {
  return impl_.size();
}
inline void MessageOpts::clear_impl() {
  impl_.Clear();
}
inline ::brewblox::BlockType MessageOpts::impl(int index) const {
  // @@protoc_insertion_point(field_get:brewblox.MessageOpts.impl)
  return static_cast< ::brewblox::BlockType >(impl_.Get(index));
}
inline void MessageOpts::set_impl(int index, ::brewblox::BlockType value) {
  impl_.Set(index, value);
  // @@protoc_insertion_point(field_set:brewblox.MessageOpts.impl)
}
inline void MessageOpts::add_impl(::brewblox::BlockType value) {
  impl_.Add(value);
  // @@protoc_insertion_point(field_add:brewblox.MessageOpts.impl)
}
inline const ::google::protobuf::RepeatedField<int>&
MessageOpts::impl() const {
  // @@protoc_insertion_point(field_list:brewblox.MessageOpts.impl)
  return impl_;
}
inline ::google::protobuf::RepeatedField<int>*
MessageOpts::mutable_impl() {
  // @@protoc_insertion_point(field_mutable_list:brewblox.MessageOpts.impl)
  return &impl_;
}

// uint32 subtype = 11 [(.nanopb) = {
inline void MessageOpts::clear_subtype() {
  subtype_ = 0u;
}
inline ::google::protobuf::uint32 MessageOpts::subtype() const {
  // @@protoc_insertion_point(field_get:brewblox.MessageOpts.subtype)
  return subtype_;
}
inline void MessageOpts::set_subtype(::google::protobuf::uint32 value) {
  
  subtype_ = value;
  // @@protoc_insertion_point(field_set:brewblox.MessageOpts.subtype)
}

// -------------------------------------------------------------------

// FieldOpts

// .brewblox.UnitType unit = 1;
inline void FieldOpts::clear_unit() {
  unit_ = 0;
}
inline ::brewblox::UnitType FieldOpts::unit() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.unit)
  return static_cast< ::brewblox::UnitType >(unit_);
}
inline void FieldOpts::set_unit(::brewblox::UnitType value) {
  
  unit_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.unit)
}

// uint32 scale = 2;
inline void FieldOpts::clear_scale() {
  scale_ = 0u;
}
inline ::google::protobuf::uint32 FieldOpts::scale() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.scale)
  return scale_;
}
inline void FieldOpts::set_scale(::google::protobuf::uint32 value) {
  
  scale_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.scale)
}

// .brewblox.BlockType objtype = 3;
inline void FieldOpts::clear_objtype() {
  objtype_ = 0;
}
inline ::brewblox::BlockType FieldOpts::objtype() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.objtype)
  return static_cast< ::brewblox::BlockType >(objtype_);
}
inline void FieldOpts::set_objtype(::brewblox::BlockType value) {
  
  objtype_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.objtype)
}

// bool hexed = 4;
inline void FieldOpts::clear_hexed() {
  hexed_ = false;
}
inline bool FieldOpts::hexed() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.hexed)
  return hexed_;
}
inline void FieldOpts::set_hexed(bool value) {
  
  hexed_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.hexed)
}

// bool readonly = 5;
inline void FieldOpts::clear_readonly() {
  readonly_ = false;
}
inline bool FieldOpts::readonly() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.readonly)
  return readonly_;
}
inline void FieldOpts::set_readonly(bool value) {
  
  readonly_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.readonly)
}

// bool logged = 6;
inline void FieldOpts::clear_logged() {
  logged_ = false;
}
inline bool FieldOpts::logged() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.logged)
  return logged_;
}
inline void FieldOpts::set_logged(bool value) {
  
  logged_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.logged)
}

// bool hexstr = 7;
inline void FieldOpts::clear_hexstr() {
  hexstr_ = false;
}
inline bool FieldOpts::hexstr() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.hexstr)
  return hexstr_;
}
inline void FieldOpts::set_hexstr(bool value) {
  
  hexstr_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.hexstr)
}

// bool driven = 8;
inline void FieldOpts::clear_driven() {
  driven_ = false;
}
inline bool FieldOpts::driven() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.driven)
  return driven_;
}
inline void FieldOpts::set_driven(bool value) {
  
  driven_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.driven)
}

// bool ignored = 9;
inline void FieldOpts::clear_ignored() {
  ignored_ = false;
}
inline bool FieldOpts::ignored() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.ignored)
  return ignored_;
}
inline void FieldOpts::set_ignored(bool value) {
  
  ignored_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.ignored)
}

// bool bitfield = 10;
inline void FieldOpts::clear_bitfield() {
  bitfield_ = false;
}
inline bool FieldOpts::bitfield() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.bitfield)
  return bitfield_;
}
inline void FieldOpts::set_bitfield(bool value) {
  
  bitfield_ = value;
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.bitfield)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace brewblox

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::brewblox::UnitType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::brewblox::UnitType>() {
  return ::brewblox::UnitType_descriptor();
}
template <> struct is_proto_enum< ::brewblox::BlockType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::brewblox::BlockType>() {
  return ::brewblox::BlockType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_brewblox_5ftest_2eproto
