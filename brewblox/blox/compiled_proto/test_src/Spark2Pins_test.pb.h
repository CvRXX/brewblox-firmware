// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Spark2Pins_test.proto

#ifndef PROTOBUF_INCLUDED_Spark2Pins_5ftest_2eproto
#define PROTOBUF_INCLUDED_Spark2Pins_5ftest_2eproto

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
#include "IoArray_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_Spark2Pins_5ftest_2eproto 

namespace protobuf_Spark2Pins_5ftest_2eproto {
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
}  // namespace protobuf_Spark2Pins_5ftest_2eproto
namespace blox {
class Spark2Pins;
class Spark2PinsDefaultTypeInternal;
extern Spark2PinsDefaultTypeInternal _Spark2Pins_default_instance_;
class Spark2PinsIoPin;
class Spark2PinsIoPinDefaultTypeInternal;
extern Spark2PinsIoPinDefaultTypeInternal _Spark2PinsIoPin_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::Spark2Pins* Arena::CreateMaybeMessage<::blox::Spark2Pins>(Arena*);
template<> ::blox::Spark2PinsIoPin* Arena::CreateMaybeMessage<::blox::Spark2PinsIoPin>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

enum Spark2Pins_Hardware {
  Spark2Pins_Hardware_HW_UNKNOWN = 0,
  Spark2Pins_Hardware_HW_SPARK1 = 1,
  Spark2Pins_Hardware_HW_SPARK2 = 2,
  Spark2Pins_Hardware_Spark2Pins_Hardware_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Spark2Pins_Hardware_Spark2Pins_Hardware_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Spark2Pins_Hardware_IsValid(int value);
const Spark2Pins_Hardware Spark2Pins_Hardware_Hardware_MIN = Spark2Pins_Hardware_HW_UNKNOWN;
const Spark2Pins_Hardware Spark2Pins_Hardware_Hardware_MAX = Spark2Pins_Hardware_HW_SPARK2;
const int Spark2Pins_Hardware_Hardware_ARRAYSIZE = Spark2Pins_Hardware_Hardware_MAX + 1;

const ::google::protobuf::EnumDescriptor* Spark2Pins_Hardware_descriptor();
inline const ::std::string& Spark2Pins_Hardware_Name(Spark2Pins_Hardware value) {
  return ::google::protobuf::internal::NameOfEnum(
    Spark2Pins_Hardware_descriptor(), value);
}
inline bool Spark2Pins_Hardware_Parse(
    const ::std::string& name, Spark2Pins_Hardware* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Spark2Pins_Hardware>(
    Spark2Pins_Hardware_descriptor(), name, value);
}
// ===================================================================

class Spark2PinsIoPin : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Spark2PinsIoPin) */ {
 public:
  Spark2PinsIoPin();
  virtual ~Spark2PinsIoPin();

  Spark2PinsIoPin(const Spark2PinsIoPin& from);

  inline Spark2PinsIoPin& operator=(const Spark2PinsIoPin& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Spark2PinsIoPin(Spark2PinsIoPin&& from) noexcept
    : Spark2PinsIoPin() {
    *this = ::std::move(from);
  }

  inline Spark2PinsIoPin& operator=(Spark2PinsIoPin&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Spark2PinsIoPin& default_instance();

  enum PinCase {
    kBottom1 = 1,
    kBottom2 = 2,
    kBottom3 = 3,
    kBottom0 = 4,
    PIN_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Spark2PinsIoPin* internal_default_instance() {
    return reinterpret_cast<const Spark2PinsIoPin*>(
               &_Spark2PinsIoPin_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Spark2PinsIoPin* other);
  friend void swap(Spark2PinsIoPin& a, Spark2PinsIoPin& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Spark2PinsIoPin* New() const final {
    return CreateMaybeMessage<Spark2PinsIoPin>(NULL);
  }

  Spark2PinsIoPin* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Spark2PinsIoPin>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Spark2PinsIoPin& from);
  void MergeFrom(const Spark2PinsIoPin& from);
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
  void InternalSwap(Spark2PinsIoPin* other);
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

  // .blox.IoChannel bottom1 = 1;
  bool has_bottom1() const;
  void clear_bottom1();
  static const int kBottom1FieldNumber = 1;
  private:
  const ::blox::IoChannel& _internal_bottom1() const;
  public:
  const ::blox::IoChannel& bottom1() const;
  ::blox::IoChannel* release_bottom1();
  ::blox::IoChannel* mutable_bottom1();
  void set_allocated_bottom1(::blox::IoChannel* bottom1);

  // .blox.IoChannel bottom2 = 2;
  bool has_bottom2() const;
  void clear_bottom2();
  static const int kBottom2FieldNumber = 2;
  private:
  const ::blox::IoChannel& _internal_bottom2() const;
  public:
  const ::blox::IoChannel& bottom2() const;
  ::blox::IoChannel* release_bottom2();
  ::blox::IoChannel* mutable_bottom2();
  void set_allocated_bottom2(::blox::IoChannel* bottom2);

  // .blox.IoChannel bottom3 = 3;
  bool has_bottom3() const;
  void clear_bottom3();
  static const int kBottom3FieldNumber = 3;
  private:
  const ::blox::IoChannel& _internal_bottom3() const;
  public:
  const ::blox::IoChannel& bottom3() const;
  ::blox::IoChannel* release_bottom3();
  ::blox::IoChannel* mutable_bottom3();
  void set_allocated_bottom3(::blox::IoChannel* bottom3);

  // .blox.IoChannel bottom0 = 4;
  bool has_bottom0() const;
  void clear_bottom0();
  static const int kBottom0FieldNumber = 4;
  private:
  const ::blox::IoChannel& _internal_bottom0() const;
  public:
  const ::blox::IoChannel& bottom0() const;
  ::blox::IoChannel* release_bottom0();
  ::blox::IoChannel* mutable_bottom0();
  void set_allocated_bottom0(::blox::IoChannel* bottom0);

  void clear_Pin();
  PinCase Pin_case() const;
  // @@protoc_insertion_point(class_scope:blox.Spark2PinsIoPin)
 private:
  void set_has_bottom1();
  void set_has_bottom2();
  void set_has_bottom3();
  void set_has_bottom0();

  inline bool has_Pin() const;
  inline void clear_has_Pin();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  union PinUnion {
    PinUnion() {}
    ::blox::IoChannel* bottom1_;
    ::blox::IoChannel* bottom2_;
    ::blox::IoChannel* bottom3_;
    ::blox::IoChannel* bottom0_;
  } Pin_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_Spark2Pins_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Spark2Pins : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Spark2Pins) */ {
 public:
  Spark2Pins();
  virtual ~Spark2Pins();

  Spark2Pins(const Spark2Pins& from);

  inline Spark2Pins& operator=(const Spark2Pins& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Spark2Pins(Spark2Pins&& from) noexcept
    : Spark2Pins() {
    *this = ::std::move(from);
  }

  inline Spark2Pins& operator=(Spark2Pins&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Spark2Pins& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Spark2Pins* internal_default_instance() {
    return reinterpret_cast<const Spark2Pins*>(
               &_Spark2Pins_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Spark2Pins* other);
  friend void swap(Spark2Pins& a, Spark2Pins& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Spark2Pins* New() const final {
    return CreateMaybeMessage<Spark2Pins>(NULL);
  }

  Spark2Pins* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Spark2Pins>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Spark2Pins& from);
  void MergeFrom(const Spark2Pins& from);
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
  void InternalSwap(Spark2Pins* other);
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

  typedef Spark2Pins_Hardware Hardware;
  static const Hardware HW_UNKNOWN =
    Spark2Pins_Hardware_HW_UNKNOWN;
  static const Hardware HW_SPARK1 =
    Spark2Pins_Hardware_HW_SPARK1;
  static const Hardware HW_SPARK2 =
    Spark2Pins_Hardware_HW_SPARK2;
  static inline bool Hardware_IsValid(int value) {
    return Spark2Pins_Hardware_IsValid(value);
  }
  static const Hardware Hardware_MIN =
    Spark2Pins_Hardware_Hardware_MIN;
  static const Hardware Hardware_MAX =
    Spark2Pins_Hardware_Hardware_MAX;
  static const int Hardware_ARRAYSIZE =
    Spark2Pins_Hardware_Hardware_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Hardware_descriptor() {
    return Spark2Pins_Hardware_descriptor();
  }
  static inline const ::std::string& Hardware_Name(Hardware value) {
    return Spark2Pins_Hardware_Name(value);
  }
  static inline bool Hardware_Parse(const ::std::string& name,
      Hardware* value) {
    return Spark2Pins_Hardware_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // repeated .blox.Spark2PinsIoPin pins = 1 [(.nanopb_test) = {
  int pins_size() const;
  void clear_pins();
  static const int kPinsFieldNumber = 1;
  ::blox::Spark2PinsIoPin* mutable_pins(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::Spark2PinsIoPin >*
      mutable_pins();
  const ::blox::Spark2PinsIoPin& pins(int index) const;
  ::blox::Spark2PinsIoPin* add_pins();
  const ::google::protobuf::RepeatedPtrField< ::blox::Spark2PinsIoPin >&
      pins() const;

  // bool soundAlarm = 5;
  void clear_soundalarm();
  static const int kSoundAlarmFieldNumber = 5;
  bool soundalarm() const;
  void set_soundalarm(bool value);

  // .blox.Spark2Pins.Hardware hardware = 8 [(.brewblox_test) = {
  void clear_hardware();
  static const int kHardwareFieldNumber = 8;
  ::blox::Spark2Pins_Hardware hardware() const;
  void set_hardware(::blox::Spark2Pins_Hardware value);

  // @@protoc_insertion_point(class_scope:blox.Spark2Pins)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::Spark2PinsIoPin > pins_;
  bool soundalarm_;
  int hardware_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Spark2Pins_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Spark2PinsIoPin

// .blox.IoChannel bottom1 = 1;
inline bool Spark2PinsIoPin::has_bottom1() const {
  return Pin_case() == kBottom1;
}
inline void Spark2PinsIoPin::set_has_bottom1() {
  _oneof_case_[0] = kBottom1;
}
inline const ::blox::IoChannel& Spark2PinsIoPin::_internal_bottom1() const {
  return *Pin_.bottom1_;
}
inline ::blox::IoChannel* Spark2PinsIoPin::release_bottom1() {
  // @@protoc_insertion_point(field_release:blox.Spark2PinsIoPin.bottom1)
  if (has_bottom1()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.bottom1_;
    Pin_.bottom1_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark2PinsIoPin::bottom1() const {
  // @@protoc_insertion_point(field_get:blox.Spark2PinsIoPin.bottom1)
  return has_bottom1()
      ? *Pin_.bottom1_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark2PinsIoPin::mutable_bottom1() {
  if (!has_bottom1()) {
    clear_Pin();
    set_has_bottom1();
    Pin_.bottom1_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark2PinsIoPin.bottom1)
  return Pin_.bottom1_;
}

// .blox.IoChannel bottom2 = 2;
inline bool Spark2PinsIoPin::has_bottom2() const {
  return Pin_case() == kBottom2;
}
inline void Spark2PinsIoPin::set_has_bottom2() {
  _oneof_case_[0] = kBottom2;
}
inline const ::blox::IoChannel& Spark2PinsIoPin::_internal_bottom2() const {
  return *Pin_.bottom2_;
}
inline ::blox::IoChannel* Spark2PinsIoPin::release_bottom2() {
  // @@protoc_insertion_point(field_release:blox.Spark2PinsIoPin.bottom2)
  if (has_bottom2()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.bottom2_;
    Pin_.bottom2_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark2PinsIoPin::bottom2() const {
  // @@protoc_insertion_point(field_get:blox.Spark2PinsIoPin.bottom2)
  return has_bottom2()
      ? *Pin_.bottom2_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark2PinsIoPin::mutable_bottom2() {
  if (!has_bottom2()) {
    clear_Pin();
    set_has_bottom2();
    Pin_.bottom2_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark2PinsIoPin.bottom2)
  return Pin_.bottom2_;
}

// .blox.IoChannel bottom3 = 3;
inline bool Spark2PinsIoPin::has_bottom3() const {
  return Pin_case() == kBottom3;
}
inline void Spark2PinsIoPin::set_has_bottom3() {
  _oneof_case_[0] = kBottom3;
}
inline const ::blox::IoChannel& Spark2PinsIoPin::_internal_bottom3() const {
  return *Pin_.bottom3_;
}
inline ::blox::IoChannel* Spark2PinsIoPin::release_bottom3() {
  // @@protoc_insertion_point(field_release:blox.Spark2PinsIoPin.bottom3)
  if (has_bottom3()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.bottom3_;
    Pin_.bottom3_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark2PinsIoPin::bottom3() const {
  // @@protoc_insertion_point(field_get:blox.Spark2PinsIoPin.bottom3)
  return has_bottom3()
      ? *Pin_.bottom3_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark2PinsIoPin::mutable_bottom3() {
  if (!has_bottom3()) {
    clear_Pin();
    set_has_bottom3();
    Pin_.bottom3_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark2PinsIoPin.bottom3)
  return Pin_.bottom3_;
}

// .blox.IoChannel bottom0 = 4;
inline bool Spark2PinsIoPin::has_bottom0() const {
  return Pin_case() == kBottom0;
}
inline void Spark2PinsIoPin::set_has_bottom0() {
  _oneof_case_[0] = kBottom0;
}
inline const ::blox::IoChannel& Spark2PinsIoPin::_internal_bottom0() const {
  return *Pin_.bottom0_;
}
inline ::blox::IoChannel* Spark2PinsIoPin::release_bottom0() {
  // @@protoc_insertion_point(field_release:blox.Spark2PinsIoPin.bottom0)
  if (has_bottom0()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.bottom0_;
    Pin_.bottom0_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark2PinsIoPin::bottom0() const {
  // @@protoc_insertion_point(field_get:blox.Spark2PinsIoPin.bottom0)
  return has_bottom0()
      ? *Pin_.bottom0_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark2PinsIoPin::mutable_bottom0() {
  if (!has_bottom0()) {
    clear_Pin();
    set_has_bottom0();
    Pin_.bottom0_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark2PinsIoPin.bottom0)
  return Pin_.bottom0_;
}

inline bool Spark2PinsIoPin::has_Pin() const {
  return Pin_case() != PIN_NOT_SET;
}
inline void Spark2PinsIoPin::clear_has_Pin() {
  _oneof_case_[0] = PIN_NOT_SET;
}
inline Spark2PinsIoPin::PinCase Spark2PinsIoPin::Pin_case() const {
  return Spark2PinsIoPin::PinCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// Spark2Pins

// repeated .blox.Spark2PinsIoPin pins = 1 [(.nanopb_test) = {
inline int Spark2Pins::pins_size() const {
  return pins_.size();
}
inline void Spark2Pins::clear_pins() {
  pins_.Clear();
}
inline ::blox::Spark2PinsIoPin* Spark2Pins::mutable_pins(int index) {
  // @@protoc_insertion_point(field_mutable:blox.Spark2Pins.pins)
  return pins_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::Spark2PinsIoPin >*
Spark2Pins::mutable_pins() {
  // @@protoc_insertion_point(field_mutable_list:blox.Spark2Pins.pins)
  return &pins_;
}
inline const ::blox::Spark2PinsIoPin& Spark2Pins::pins(int index) const {
  // @@protoc_insertion_point(field_get:blox.Spark2Pins.pins)
  return pins_.Get(index);
}
inline ::blox::Spark2PinsIoPin* Spark2Pins::add_pins() {
  // @@protoc_insertion_point(field_add:blox.Spark2Pins.pins)
  return pins_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::Spark2PinsIoPin >&
Spark2Pins::pins() const {
  // @@protoc_insertion_point(field_list:blox.Spark2Pins.pins)
  return pins_;
}

// bool soundAlarm = 5;
inline void Spark2Pins::clear_soundalarm() {
  soundalarm_ = false;
}
inline bool Spark2Pins::soundalarm() const {
  // @@protoc_insertion_point(field_get:blox.Spark2Pins.soundAlarm)
  return soundalarm_;
}
inline void Spark2Pins::set_soundalarm(bool value) {
  
  soundalarm_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark2Pins.soundAlarm)
}

// .blox.Spark2Pins.Hardware hardware = 8 [(.brewblox_test) = {
inline void Spark2Pins::clear_hardware() {
  hardware_ = 0;
}
inline ::blox::Spark2Pins_Hardware Spark2Pins::hardware() const {
  // @@protoc_insertion_point(field_get:blox.Spark2Pins.hardware)
  return static_cast< ::blox::Spark2Pins_Hardware >(hardware_);
}
inline void Spark2Pins::set_hardware(::blox::Spark2Pins_Hardware value) {
  
  hardware_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark2Pins.hardware)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox::Spark2Pins_Hardware> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::Spark2Pins_Hardware>() {
  return ::blox::Spark2Pins_Hardware_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_Spark2Pins_5ftest_2eproto
