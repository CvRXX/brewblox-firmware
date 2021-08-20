// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MotorValve_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_MotorValve_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_MotorValve_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
#include "DigitalConstraints_test.pb.h"
#include "IoArray_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_MotorValve_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_MotorValve_5ftest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_MotorValve_5ftest_2eproto;
namespace blox {
class MotorValve;
struct MotorValveDefaultTypeInternal;
extern MotorValveDefaultTypeInternal _MotorValve_default_instance_;
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> ::blox::MotorValve* Arena::CreateMaybeMessage<::blox::MotorValve>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox {

enum MotorValve_ValveState : int {
  MotorValve_ValveState_VALVE_UNKNOWN = 0,
  MotorValve_ValveState_VALVE_OPEN = 1,
  MotorValve_ValveState_VALVE_CLOSED = 2,
  MotorValve_ValveState_VALVE_OPENING = 3,
  MotorValve_ValveState_VALVE_CLOSING = 4,
  MotorValve_ValveState_VALVE_HALF_OPEN_IDLE = 5,
  MotorValve_ValveState_VALVE_INIT_IDLE = 6,
  MotorValve_ValveState_MotorValve_ValveState_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  MotorValve_ValveState_MotorValve_ValveState_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool MotorValve_ValveState_IsValid(int value);
constexpr MotorValve_ValveState MotorValve_ValveState_ValveState_MIN = MotorValve_ValveState_VALVE_UNKNOWN;
constexpr MotorValve_ValveState MotorValve_ValveState_ValveState_MAX = MotorValve_ValveState_VALVE_INIT_IDLE;
constexpr int MotorValve_ValveState_ValveState_ARRAYSIZE = MotorValve_ValveState_ValveState_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MotorValve_ValveState_descriptor();
template<typename T>
inline const std::string& MotorValve_ValveState_Name(T enum_t_value) {
  static_assert(::std::is_same<T, MotorValve_ValveState>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function MotorValve_ValveState_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    MotorValve_ValveState_descriptor(), enum_t_value);
}
inline bool MotorValve_ValveState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, MotorValve_ValveState* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<MotorValve_ValveState>(
    MotorValve_ValveState_descriptor(), name, value);
}
// ===================================================================

class MotorValve final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox.MotorValve) */ {
 public:
  inline MotorValve() : MotorValve(nullptr) {}
  ~MotorValve() override;
  explicit constexpr MotorValve(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MotorValve(const MotorValve& from);
  MotorValve(MotorValve&& from) noexcept
    : MotorValve() {
    *this = ::std::move(from);
  }

  inline MotorValve& operator=(const MotorValve& from) {
    CopyFrom(from);
    return *this;
  }
  inline MotorValve& operator=(MotorValve&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
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
  static const MotorValve& default_instance() {
    return *internal_default_instance();
  }
  static inline const MotorValve* internal_default_instance() {
    return reinterpret_cast<const MotorValve*>(
               &_MotorValve_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MotorValve& a, MotorValve& b) {
    a.Swap(&b);
  }
  inline void Swap(MotorValve* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MotorValve* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline MotorValve* New() const final {
    return new MotorValve();
  }

  MotorValve* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<MotorValve>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MotorValve& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const MotorValve& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MotorValve* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox.MotorValve";
  }
  protected:
  explicit MotorValve(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef MotorValve_ValveState ValveState;
  static constexpr ValveState VALVE_UNKNOWN =
    MotorValve_ValveState_VALVE_UNKNOWN;
  static constexpr ValveState VALVE_OPEN =
    MotorValve_ValveState_VALVE_OPEN;
  static constexpr ValveState VALVE_CLOSED =
    MotorValve_ValveState_VALVE_CLOSED;
  static constexpr ValveState VALVE_OPENING =
    MotorValve_ValveState_VALVE_OPENING;
  static constexpr ValveState VALVE_CLOSING =
    MotorValve_ValveState_VALVE_CLOSING;
  static constexpr ValveState VALVE_HALF_OPEN_IDLE =
    MotorValve_ValveState_VALVE_HALF_OPEN_IDLE;
  static constexpr ValveState VALVE_INIT_IDLE =
    MotorValve_ValveState_VALVE_INIT_IDLE;
  static inline bool ValveState_IsValid(int value) {
    return MotorValve_ValveState_IsValid(value);
  }
  static constexpr ValveState ValveState_MIN =
    MotorValve_ValveState_ValveState_MIN;
  static constexpr ValveState ValveState_MAX =
    MotorValve_ValveState_ValveState_MAX;
  static constexpr int ValveState_ARRAYSIZE =
    MotorValve_ValveState_ValveState_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  ValveState_descriptor() {
    return MotorValve_ValveState_descriptor();
  }
  template<typename T>
  static inline const std::string& ValveState_Name(T enum_t_value) {
    static_assert(::std::is_same<T, ValveState>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function ValveState_Name.");
    return MotorValve_ValveState_Name(enum_t_value);
  }
  static inline bool ValveState_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      ValveState* value) {
    return MotorValve_ValveState_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kStrippedFieldsFieldNumber = 99,
    kConstrainedByFieldNumber = 5,
    kHwDeviceFieldNumber = 1,
    kStartChannelFieldNumber = 2,
    kStateFieldNumber = 3,
    kValveStateFieldNumber = 6,
    kDesiredStateFieldNumber = 7,
  };
  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  int strippedfields_size() const;
  private:
  int _internal_strippedfields_size() const;
  public:
  void clear_strippedfields();
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_strippedfields(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
      _internal_strippedfields() const;
  void _internal_add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
      _internal_mutable_strippedfields();
  public:
  ::PROTOBUF_NAMESPACE_ID::uint32 strippedfields(int index) const;
  void set_strippedfields(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value);
  void add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
      strippedfields() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
      mutable_strippedfields();

  // .blox.DigitalConstraints constrainedBy = 5;
  bool has_constrainedby() const;
  private:
  bool _internal_has_constrainedby() const;
  public:
  void clear_constrainedby();
  const ::blox::DigitalConstraints& constrainedby() const;
  PROTOBUF_MUST_USE_RESULT ::blox::DigitalConstraints* release_constrainedby();
  ::blox::DigitalConstraints* mutable_constrainedby();
  void set_allocated_constrainedby(::blox::DigitalConstraints* constrainedby);
  private:
  const ::blox::DigitalConstraints& _internal_constrainedby() const;
  ::blox::DigitalConstraints* _internal_mutable_constrainedby();
  public:
  void unsafe_arena_set_allocated_constrainedby(
      ::blox::DigitalConstraints* constrainedby);
  ::blox::DigitalConstraints* unsafe_arena_release_constrainedby();

  // uint32 hwDevice = 1 [(.nanopb_test) = {
  void clear_hwdevice();
  ::PROTOBUF_NAMESPACE_ID::uint32 hwdevice() const;
  void set_hwdevice(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_hwdevice() const;
  void _internal_set_hwdevice(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 startChannel = 2 [(.nanopb_test) = {
  void clear_startchannel();
  ::PROTOBUF_NAMESPACE_ID::uint32 startchannel() const;
  void set_startchannel(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_startchannel() const;
  void _internal_set_startchannel(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // .blox.DigitalState state = 3 [(.brewblox_test) = {
  void clear_state();
  ::blox::DigitalState state() const;
  void set_state(::blox::DigitalState value);
  private:
  ::blox::DigitalState _internal_state() const;
  void _internal_set_state(::blox::DigitalState value);
  public:

  // .blox.MotorValve.ValveState valveState = 6 [(.brewblox_test) = {
  void clear_valvestate();
  ::blox::MotorValve_ValveState valvestate() const;
  void set_valvestate(::blox::MotorValve_ValveState value);
  private:
  ::blox::MotorValve_ValveState _internal_valvestate() const;
  void _internal_set_valvestate(::blox::MotorValve_ValveState value);
  public:

  // .blox.DigitalState desiredState = 7 [(.brewblox_test) = {
  void clear_desiredstate();
  ::blox::DigitalState desiredstate() const;
  void set_desiredstate(::blox::DigitalState value);
  private:
  ::blox::DigitalState _internal_desiredstate() const;
  void _internal_set_desiredstate(::blox::DigitalState value);
  public:

  // @@protoc_insertion_point(class_scope:blox.MotorValve)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 > strippedfields_;
  mutable std::atomic<int> _strippedfields_cached_byte_size_;
  ::blox::DigitalConstraints* constrainedby_;
  ::PROTOBUF_NAMESPACE_ID::uint32 hwdevice_;
  ::PROTOBUF_NAMESPACE_ID::uint32 startchannel_;
  int state_;
  int valvestate_;
  int desiredstate_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_MotorValve_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MotorValve

// uint32 hwDevice = 1 [(.nanopb_test) = {
inline void MotorValve::clear_hwdevice() {
  hwdevice_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MotorValve::_internal_hwdevice() const {
  return hwdevice_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MotorValve::hwdevice() const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.hwDevice)
  return _internal_hwdevice();
}
inline void MotorValve::_internal_set_hwdevice(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  hwdevice_ = value;
}
inline void MotorValve::set_hwdevice(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_hwdevice(value);
  // @@protoc_insertion_point(field_set:blox.MotorValve.hwDevice)
}

// uint32 startChannel = 2 [(.nanopb_test) = {
inline void MotorValve::clear_startchannel() {
  startchannel_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MotorValve::_internal_startchannel() const {
  return startchannel_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MotorValve::startchannel() const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.startChannel)
  return _internal_startchannel();
}
inline void MotorValve::_internal_set_startchannel(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  startchannel_ = value;
}
inline void MotorValve::set_startchannel(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_startchannel(value);
  // @@protoc_insertion_point(field_set:blox.MotorValve.startChannel)
}

// .blox.DigitalState state = 3 [(.brewblox_test) = {
inline void MotorValve::clear_state() {
  state_ = 0;
}
inline ::blox::DigitalState MotorValve::_internal_state() const {
  return static_cast< ::blox::DigitalState >(state_);
}
inline ::blox::DigitalState MotorValve::state() const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.state)
  return _internal_state();
}
inline void MotorValve::_internal_set_state(::blox::DigitalState value) {
  
  state_ = value;
}
inline void MotorValve::set_state(::blox::DigitalState value) {
  _internal_set_state(value);
  // @@protoc_insertion_point(field_set:blox.MotorValve.state)
}

// .blox.DigitalConstraints constrainedBy = 5;
inline bool MotorValve::_internal_has_constrainedby() const {
  return this != internal_default_instance() && constrainedby_ != nullptr;
}
inline bool MotorValve::has_constrainedby() const {
  return _internal_has_constrainedby();
}
inline const ::blox::DigitalConstraints& MotorValve::_internal_constrainedby() const {
  const ::blox::DigitalConstraints* p = constrainedby_;
  return p != nullptr ? *p : reinterpret_cast<const ::blox::DigitalConstraints&>(
      ::blox::_DigitalConstraints_default_instance_);
}
inline const ::blox::DigitalConstraints& MotorValve::constrainedby() const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.constrainedBy)
  return _internal_constrainedby();
}
inline void MotorValve::unsafe_arena_set_allocated_constrainedby(
    ::blox::DigitalConstraints* constrainedby) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(constrainedby_);
  }
  constrainedby_ = constrainedby;
  if (constrainedby) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:blox.MotorValve.constrainedBy)
}
inline ::blox::DigitalConstraints* MotorValve::release_constrainedby() {
  
  ::blox::DigitalConstraints* temp = constrainedby_;
  constrainedby_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::blox::DigitalConstraints* MotorValve::unsafe_arena_release_constrainedby() {
  // @@protoc_insertion_point(field_release:blox.MotorValve.constrainedBy)
  
  ::blox::DigitalConstraints* temp = constrainedby_;
  constrainedby_ = nullptr;
  return temp;
}
inline ::blox::DigitalConstraints* MotorValve::_internal_mutable_constrainedby() {
  
  if (constrainedby_ == nullptr) {
    auto* p = CreateMaybeMessage<::blox::DigitalConstraints>(GetArenaForAllocation());
    constrainedby_ = p;
  }
  return constrainedby_;
}
inline ::blox::DigitalConstraints* MotorValve::mutable_constrainedby() {
  ::blox::DigitalConstraints* _msg = _internal_mutable_constrainedby();
  // @@protoc_insertion_point(field_mutable:blox.MotorValve.constrainedBy)
  return _msg;
}
inline void MotorValve::set_allocated_constrainedby(::blox::DigitalConstraints* constrainedby) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(constrainedby_);
  }
  if (constrainedby) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<
            ::PROTOBUF_NAMESPACE_ID::MessageLite>::GetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(constrainedby));
    if (message_arena != submessage_arena) {
      constrainedby = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, constrainedby, submessage_arena);
    }
    
  } else {
    
  }
  constrainedby_ = constrainedby;
  // @@protoc_insertion_point(field_set_allocated:blox.MotorValve.constrainedBy)
}

// .blox.MotorValve.ValveState valveState = 6 [(.brewblox_test) = {
inline void MotorValve::clear_valvestate() {
  valvestate_ = 0;
}
inline ::blox::MotorValve_ValveState MotorValve::_internal_valvestate() const {
  return static_cast< ::blox::MotorValve_ValveState >(valvestate_);
}
inline ::blox::MotorValve_ValveState MotorValve::valvestate() const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.valveState)
  return _internal_valvestate();
}
inline void MotorValve::_internal_set_valvestate(::blox::MotorValve_ValveState value) {
  
  valvestate_ = value;
}
inline void MotorValve::set_valvestate(::blox::MotorValve_ValveState value) {
  _internal_set_valvestate(value);
  // @@protoc_insertion_point(field_set:blox.MotorValve.valveState)
}

// .blox.DigitalState desiredState = 7 [(.brewblox_test) = {
inline void MotorValve::clear_desiredstate() {
  desiredstate_ = 0;
}
inline ::blox::DigitalState MotorValve::_internal_desiredstate() const {
  return static_cast< ::blox::DigitalState >(desiredstate_);
}
inline ::blox::DigitalState MotorValve::desiredstate() const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.desiredState)
  return _internal_desiredstate();
}
inline void MotorValve::_internal_set_desiredstate(::blox::DigitalState value) {
  
  desiredstate_ = value;
}
inline void MotorValve::set_desiredstate(::blox::DigitalState value) {
  _internal_set_desiredstate(value);
  // @@protoc_insertion_point(field_set:blox.MotorValve.desiredState)
}

// repeated uint32 strippedFields = 99 [(.nanopb_test) = {
inline int MotorValve::_internal_strippedfields_size() const {
  return strippedfields_.size();
}
inline int MotorValve::strippedfields_size() const {
  return _internal_strippedfields_size();
}
inline void MotorValve::clear_strippedfields() {
  strippedfields_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MotorValve::_internal_strippedfields(int index) const {
  return strippedfields_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 MotorValve::strippedfields(int index) const {
  // @@protoc_insertion_point(field_get:blox.MotorValve.strippedFields)
  return _internal_strippedfields(index);
}
inline void MotorValve::set_strippedfields(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value) {
  strippedfields_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.MotorValve.strippedFields)
}
inline void MotorValve::_internal_add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  strippedfields_.Add(value);
}
inline void MotorValve::add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_add_strippedfields(value);
  // @@protoc_insertion_point(field_add:blox.MotorValve.strippedFields)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
MotorValve::_internal_strippedfields() const {
  return strippedfields_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
MotorValve::strippedfields() const {
  // @@protoc_insertion_point(field_list:blox.MotorValve.strippedFields)
  return _internal_strippedfields();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
MotorValve::_internal_mutable_strippedfields() {
  return &strippedfields_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
MotorValve::mutable_strippedfields() {
  // @@protoc_insertion_point(field_mutable_list:blox.MotorValve.strippedFields)
  return _internal_mutable_strippedfields();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::blox::MotorValve_ValveState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::MotorValve_ValveState>() {
  return ::blox::MotorValve_ValveState_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_MotorValve_5ftest_2eproto
