// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: brewblox_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_brewblox_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_brewblox_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/descriptor.pb.h>
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_brewblox_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_brewblox_5ftest_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_brewblox_5ftest_2eproto;
namespace brewblox {
class FieldOpts;
struct FieldOptsDefaultTypeInternal;
extern FieldOptsDefaultTypeInternal _FieldOpts_default_instance_;
class MessageOpts;
struct MessageOptsDefaultTypeInternal;
extern MessageOptsDefaultTypeInternal _MessageOpts_default_instance_;
}  // namespace brewblox
PROTOBUF_NAMESPACE_OPEN
template<> ::brewblox::FieldOpts* Arena::CreateMaybeMessage<::brewblox::FieldOpts>(Arena*);
template<> ::brewblox::MessageOpts* Arena::CreateMaybeMessage<::brewblox::MessageOpts>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace brewblox {

enum UnitType : int {
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
  UnitType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  UnitType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool UnitType_IsValid(int value);
constexpr UnitType UnitType_MIN = NotSet;
constexpr UnitType UnitType_MAX = DeltaCelsiusMultHour;
constexpr int UnitType_ARRAYSIZE = UnitType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* UnitType_descriptor();
template<typename T>
inline const std::string& UnitType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, UnitType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function UnitType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    UnitType_descriptor(), enum_t_value);
}
inline bool UnitType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, UnitType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<UnitType>(
    UnitType_descriptor(), name, value);
}
enum BlockType : int {
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
  EnablerInterface = 15,
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
  Sequence = 326,
  BlockType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  BlockType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool BlockType_IsValid(int value);
constexpr BlockType BlockType_MIN = Invalid;
constexpr BlockType BlockType_MAX = Sequence;
constexpr int BlockType_ARRAYSIZE = BlockType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* BlockType_descriptor();
template<typename T>
inline const std::string& BlockType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, BlockType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function BlockType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    BlockType_descriptor(), enum_t_value);
}
inline bool BlockType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, BlockType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<BlockType>(
    BlockType_descriptor(), name, value);
}
// ===================================================================

class MessageOpts final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:brewblox.MessageOpts) */ {
 public:
  inline MessageOpts() : MessageOpts(nullptr) {}
  ~MessageOpts() override;
  explicit PROTOBUF_CONSTEXPR MessageOpts(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MessageOpts(const MessageOpts& from);
  MessageOpts(MessageOpts&& from) noexcept
    : MessageOpts() {
    *this = ::std::move(from);
  }

  inline MessageOpts& operator=(const MessageOpts& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageOpts& operator=(MessageOpts&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MessageOpts& default_instance() {
    return *internal_default_instance();
  }
  static inline const MessageOpts* internal_default_instance() {
    return reinterpret_cast<const MessageOpts*>(
               &_MessageOpts_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MessageOpts& a, MessageOpts& b) {
    a.Swap(&b);
  }
  inline void Swap(MessageOpts* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MessageOpts* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MessageOpts* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MessageOpts>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MessageOpts& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const MessageOpts& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MessageOpts* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "brewblox.MessageOpts";
  }
  protected:
  explicit MessageOpts(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kImplFieldNumber = 9,
    kObjtypeFieldNumber = 3,
    kSubtypeFieldNumber = 11,
  };
  // repeated .brewblox.BlockType impl = 9 [(.nanopb) = {
  int impl_size() const;
  private:
  int _internal_impl_size() const;
  public:
  void clear_impl();
  private:
  ::brewblox::BlockType _internal_impl(int index) const;
  void _internal_add_impl(::brewblox::BlockType value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>* _internal_mutable_impl();
  public:
  ::brewblox::BlockType impl(int index) const;
  void set_impl(int index, ::brewblox::BlockType value);
  void add_impl(::brewblox::BlockType value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>& impl() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>* mutable_impl();

  // .brewblox.BlockType objtype = 3;
  void clear_objtype();
  ::brewblox::BlockType objtype() const;
  void set_objtype(::brewblox::BlockType value);
  private:
  ::brewblox::BlockType _internal_objtype() const;
  void _internal_set_objtype(::brewblox::BlockType value);
  public:

  // uint32 subtype = 11 [(.nanopb) = {
  void clear_subtype();
  uint32_t subtype() const;
  void set_subtype(uint32_t value);
  private:
  uint32_t _internal_subtype() const;
  void _internal_set_subtype(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:brewblox.MessageOpts)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<int> impl_;
  mutable std::atomic<int> _impl_cached_byte_size_;
  int objtype_;
  uint32_t subtype_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_brewblox_5ftest_2eproto;
};
// -------------------------------------------------------------------

class FieldOpts final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:brewblox.FieldOpts) */ {
 public:
  inline FieldOpts() : FieldOpts(nullptr) {}
  ~FieldOpts() override;
  explicit PROTOBUF_CONSTEXPR FieldOpts(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FieldOpts(const FieldOpts& from);
  FieldOpts(FieldOpts&& from) noexcept
    : FieldOpts() {
    *this = ::std::move(from);
  }

  inline FieldOpts& operator=(const FieldOpts& from) {
    CopyFrom(from);
    return *this;
  }
  inline FieldOpts& operator=(FieldOpts&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const FieldOpts& default_instance() {
    return *internal_default_instance();
  }
  static inline const FieldOpts* internal_default_instance() {
    return reinterpret_cast<const FieldOpts*>(
               &_FieldOpts_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(FieldOpts& a, FieldOpts& b) {
    a.Swap(&b);
  }
  inline void Swap(FieldOpts* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FieldOpts* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FieldOpts* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<FieldOpts>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const FieldOpts& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const FieldOpts& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FieldOpts* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "brewblox.FieldOpts";
  }
  protected:
  explicit FieldOpts(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUnitFieldNumber = 1,
    kScaleFieldNumber = 2,
    kObjtypeFieldNumber = 3,
    kHexedFieldNumber = 4,
    kReadonlyFieldNumber = 5,
    kLoggedFieldNumber = 6,
    kHexstrFieldNumber = 7,
    kDrivenFieldNumber = 8,
    kIgnoredFieldNumber = 9,
    kBitfieldFieldNumber = 10,
    kDatetimeFieldNumber = 11,
  };
  // .brewblox.UnitType unit = 1;
  void clear_unit();
  ::brewblox::UnitType unit() const;
  void set_unit(::brewblox::UnitType value);
  private:
  ::brewblox::UnitType _internal_unit() const;
  void _internal_set_unit(::brewblox::UnitType value);
  public:

  // uint32 scale = 2;
  void clear_scale();
  uint32_t scale() const;
  void set_scale(uint32_t value);
  private:
  uint32_t _internal_scale() const;
  void _internal_set_scale(uint32_t value);
  public:

  // .brewblox.BlockType objtype = 3;
  void clear_objtype();
  ::brewblox::BlockType objtype() const;
  void set_objtype(::brewblox::BlockType value);
  private:
  ::brewblox::BlockType _internal_objtype() const;
  void _internal_set_objtype(::brewblox::BlockType value);
  public:

  // bool hexed = 4;
  void clear_hexed();
  bool hexed() const;
  void set_hexed(bool value);
  private:
  bool _internal_hexed() const;
  void _internal_set_hexed(bool value);
  public:

  // bool readonly = 5;
  void clear_readonly();
  bool readonly() const;
  void set_readonly(bool value);
  private:
  bool _internal_readonly() const;
  void _internal_set_readonly(bool value);
  public:

  // bool logged = 6;
  void clear_logged();
  bool logged() const;
  void set_logged(bool value);
  private:
  bool _internal_logged() const;
  void _internal_set_logged(bool value);
  public:

  // bool hexstr = 7;
  void clear_hexstr();
  bool hexstr() const;
  void set_hexstr(bool value);
  private:
  bool _internal_hexstr() const;
  void _internal_set_hexstr(bool value);
  public:

  // bool driven = 8;
  void clear_driven();
  bool driven() const;
  void set_driven(bool value);
  private:
  bool _internal_driven() const;
  void _internal_set_driven(bool value);
  public:

  // bool ignored = 9;
  void clear_ignored();
  bool ignored() const;
  void set_ignored(bool value);
  private:
  bool _internal_ignored() const;
  void _internal_set_ignored(bool value);
  public:

  // bool bitfield = 10;
  void clear_bitfield();
  bool bitfield() const;
  void set_bitfield(bool value);
  private:
  bool _internal_bitfield() const;
  void _internal_set_bitfield(bool value);
  public:

  // bool datetime = 11;
  void clear_datetime();
  bool datetime() const;
  void set_datetime(bool value);
  private:
  bool _internal_datetime() const;
  void _internal_set_datetime(bool value);
  public:

  // @@protoc_insertion_point(class_scope:brewblox.FieldOpts)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int unit_;
  uint32_t scale_;
  int objtype_;
  bool hexed_;
  bool readonly_;
  bool logged_;
  bool hexstr_;
  bool driven_;
  bool ignored_;
  bool bitfield_;
  bool datetime_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_brewblox_5ftest_2eproto;
};
// ===================================================================

static const int kFieldFieldNumber = 50001;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::PROTOBUF_NAMESPACE_ID::FieldOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::brewblox::FieldOpts >, 11, false >
  field;
static const int kMsgFieldNumber = 50001;
extern ::PROTOBUF_NAMESPACE_ID::internal::ExtensionIdentifier< ::PROTOBUF_NAMESPACE_ID::MessageOptions,
    ::PROTOBUF_NAMESPACE_ID::internal::MessageTypeTraits< ::brewblox::MessageOpts >, 11, false >
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
inline ::brewblox::BlockType MessageOpts::_internal_objtype() const {
  return static_cast< ::brewblox::BlockType >(objtype_);
}
inline ::brewblox::BlockType MessageOpts::objtype() const {
  // @@protoc_insertion_point(field_get:brewblox.MessageOpts.objtype)
  return _internal_objtype();
}
inline void MessageOpts::_internal_set_objtype(::brewblox::BlockType value) {
  
  objtype_ = value;
}
inline void MessageOpts::set_objtype(::brewblox::BlockType value) {
  _internal_set_objtype(value);
  // @@protoc_insertion_point(field_set:brewblox.MessageOpts.objtype)
}

// repeated .brewblox.BlockType impl = 9 [(.nanopb) = {
inline int MessageOpts::_internal_impl_size() const {
  return impl_.size();
}
inline int MessageOpts::impl_size() const {
  return _internal_impl_size();
}
inline void MessageOpts::clear_impl() {
  impl_.Clear();
}
inline ::brewblox::BlockType MessageOpts::_internal_impl(int index) const {
  return static_cast< ::brewblox::BlockType >(impl_.Get(index));
}
inline ::brewblox::BlockType MessageOpts::impl(int index) const {
  // @@protoc_insertion_point(field_get:brewblox.MessageOpts.impl)
  return _internal_impl(index);
}
inline void MessageOpts::set_impl(int index, ::brewblox::BlockType value) {
  impl_.Set(index, value);
  // @@protoc_insertion_point(field_set:brewblox.MessageOpts.impl)
}
inline void MessageOpts::_internal_add_impl(::brewblox::BlockType value) {
  impl_.Add(value);
}
inline void MessageOpts::add_impl(::brewblox::BlockType value) {
  _internal_add_impl(value);
  // @@protoc_insertion_point(field_add:brewblox.MessageOpts.impl)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>&
MessageOpts::impl() const {
  // @@protoc_insertion_point(field_list:brewblox.MessageOpts.impl)
  return impl_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>*
MessageOpts::_internal_mutable_impl() {
  return &impl_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>*
MessageOpts::mutable_impl() {
  // @@protoc_insertion_point(field_mutable_list:brewblox.MessageOpts.impl)
  return _internal_mutable_impl();
}

// uint32 subtype = 11 [(.nanopb) = {
inline void MessageOpts::clear_subtype() {
  subtype_ = 0u;
}
inline uint32_t MessageOpts::_internal_subtype() const {
  return subtype_;
}
inline uint32_t MessageOpts::subtype() const {
  // @@protoc_insertion_point(field_get:brewblox.MessageOpts.subtype)
  return _internal_subtype();
}
inline void MessageOpts::_internal_set_subtype(uint32_t value) {
  
  subtype_ = value;
}
inline void MessageOpts::set_subtype(uint32_t value) {
  _internal_set_subtype(value);
  // @@protoc_insertion_point(field_set:brewblox.MessageOpts.subtype)
}

// -------------------------------------------------------------------

// FieldOpts

// .brewblox.UnitType unit = 1;
inline void FieldOpts::clear_unit() {
  unit_ = 0;
}
inline ::brewblox::UnitType FieldOpts::_internal_unit() const {
  return static_cast< ::brewblox::UnitType >(unit_);
}
inline ::brewblox::UnitType FieldOpts::unit() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.unit)
  return _internal_unit();
}
inline void FieldOpts::_internal_set_unit(::brewblox::UnitType value) {
  
  unit_ = value;
}
inline void FieldOpts::set_unit(::brewblox::UnitType value) {
  _internal_set_unit(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.unit)
}

// uint32 scale = 2;
inline void FieldOpts::clear_scale() {
  scale_ = 0u;
}
inline uint32_t FieldOpts::_internal_scale() const {
  return scale_;
}
inline uint32_t FieldOpts::scale() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.scale)
  return _internal_scale();
}
inline void FieldOpts::_internal_set_scale(uint32_t value) {
  
  scale_ = value;
}
inline void FieldOpts::set_scale(uint32_t value) {
  _internal_set_scale(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.scale)
}

// .brewblox.BlockType objtype = 3;
inline void FieldOpts::clear_objtype() {
  objtype_ = 0;
}
inline ::brewblox::BlockType FieldOpts::_internal_objtype() const {
  return static_cast< ::brewblox::BlockType >(objtype_);
}
inline ::brewblox::BlockType FieldOpts::objtype() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.objtype)
  return _internal_objtype();
}
inline void FieldOpts::_internal_set_objtype(::brewblox::BlockType value) {
  
  objtype_ = value;
}
inline void FieldOpts::set_objtype(::brewblox::BlockType value) {
  _internal_set_objtype(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.objtype)
}

// bool hexed = 4;
inline void FieldOpts::clear_hexed() {
  hexed_ = false;
}
inline bool FieldOpts::_internal_hexed() const {
  return hexed_;
}
inline bool FieldOpts::hexed() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.hexed)
  return _internal_hexed();
}
inline void FieldOpts::_internal_set_hexed(bool value) {
  
  hexed_ = value;
}
inline void FieldOpts::set_hexed(bool value) {
  _internal_set_hexed(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.hexed)
}

// bool readonly = 5;
inline void FieldOpts::clear_readonly() {
  readonly_ = false;
}
inline bool FieldOpts::_internal_readonly() const {
  return readonly_;
}
inline bool FieldOpts::readonly() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.readonly)
  return _internal_readonly();
}
inline void FieldOpts::_internal_set_readonly(bool value) {
  
  readonly_ = value;
}
inline void FieldOpts::set_readonly(bool value) {
  _internal_set_readonly(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.readonly)
}

// bool logged = 6;
inline void FieldOpts::clear_logged() {
  logged_ = false;
}
inline bool FieldOpts::_internal_logged() const {
  return logged_;
}
inline bool FieldOpts::logged() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.logged)
  return _internal_logged();
}
inline void FieldOpts::_internal_set_logged(bool value) {
  
  logged_ = value;
}
inline void FieldOpts::set_logged(bool value) {
  _internal_set_logged(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.logged)
}

// bool hexstr = 7;
inline void FieldOpts::clear_hexstr() {
  hexstr_ = false;
}
inline bool FieldOpts::_internal_hexstr() const {
  return hexstr_;
}
inline bool FieldOpts::hexstr() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.hexstr)
  return _internal_hexstr();
}
inline void FieldOpts::_internal_set_hexstr(bool value) {
  
  hexstr_ = value;
}
inline void FieldOpts::set_hexstr(bool value) {
  _internal_set_hexstr(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.hexstr)
}

// bool driven = 8;
inline void FieldOpts::clear_driven() {
  driven_ = false;
}
inline bool FieldOpts::_internal_driven() const {
  return driven_;
}
inline bool FieldOpts::driven() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.driven)
  return _internal_driven();
}
inline void FieldOpts::_internal_set_driven(bool value) {
  
  driven_ = value;
}
inline void FieldOpts::set_driven(bool value) {
  _internal_set_driven(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.driven)
}

// bool ignored = 9;
inline void FieldOpts::clear_ignored() {
  ignored_ = false;
}
inline bool FieldOpts::_internal_ignored() const {
  return ignored_;
}
inline bool FieldOpts::ignored() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.ignored)
  return _internal_ignored();
}
inline void FieldOpts::_internal_set_ignored(bool value) {
  
  ignored_ = value;
}
inline void FieldOpts::set_ignored(bool value) {
  _internal_set_ignored(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.ignored)
}

// bool bitfield = 10;
inline void FieldOpts::clear_bitfield() {
  bitfield_ = false;
}
inline bool FieldOpts::_internal_bitfield() const {
  return bitfield_;
}
inline bool FieldOpts::bitfield() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.bitfield)
  return _internal_bitfield();
}
inline void FieldOpts::_internal_set_bitfield(bool value) {
  
  bitfield_ = value;
}
inline void FieldOpts::set_bitfield(bool value) {
  _internal_set_bitfield(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.bitfield)
}

// bool datetime = 11;
inline void FieldOpts::clear_datetime() {
  datetime_ = false;
}
inline bool FieldOpts::_internal_datetime() const {
  return datetime_;
}
inline bool FieldOpts::datetime() const {
  // @@protoc_insertion_point(field_get:brewblox.FieldOpts.datetime)
  return _internal_datetime();
}
inline void FieldOpts::_internal_set_datetime(bool value) {
  
  datetime_ = value;
}
inline void FieldOpts::set_datetime(bool value) {
  _internal_set_datetime(value);
  // @@protoc_insertion_point(field_set:brewblox.FieldOpts.datetime)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace brewblox

PROTOBUF_NAMESPACE_OPEN

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

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_brewblox_5ftest_2eproto
