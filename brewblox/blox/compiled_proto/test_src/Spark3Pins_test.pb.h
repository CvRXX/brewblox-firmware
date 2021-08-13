// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Spark3Pins_test.proto

#ifndef PROTOBUF_INCLUDED_Spark3Pins_5ftest_2eproto
#define PROTOBUF_INCLUDED_Spark3Pins_5ftest_2eproto

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
#include "IoArray_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_Spark3Pins_5ftest_2eproto 

namespace protobuf_Spark3Pins_5ftest_2eproto {
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
}  // namespace protobuf_Spark3Pins_5ftest_2eproto
namespace blox {
class Spark3IoPin;
class Spark3IoPinDefaultTypeInternal;
extern Spark3IoPinDefaultTypeInternal _Spark3IoPin_default_instance_;
class Spark3Pins;
class Spark3PinsDefaultTypeInternal;
extern Spark3PinsDefaultTypeInternal _Spark3Pins_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::Spark3IoPin* Arena::CreateMaybeMessage<::blox::Spark3IoPin>(Arena*);
template<> ::blox::Spark3Pins* Arena::CreateMaybeMessage<::blox::Spark3Pins>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

// ===================================================================

class Spark3IoPin : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Spark3IoPin) */ {
 public:
  Spark3IoPin();
  virtual ~Spark3IoPin();

  Spark3IoPin(const Spark3IoPin& from);

  inline Spark3IoPin& operator=(const Spark3IoPin& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Spark3IoPin(Spark3IoPin&& from) noexcept
    : Spark3IoPin() {
    *this = ::std::move(from);
  }

  inline Spark3IoPin& operator=(Spark3IoPin&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Spark3IoPin& default_instance();

  enum PinCase {
    kTop1 = 1,
    kTop2 = 2,
    kTop3 = 3,
    kBottom1 = 4,
    kBottom2 = 5,
    PIN_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Spark3IoPin* internal_default_instance() {
    return reinterpret_cast<const Spark3IoPin*>(
               &_Spark3IoPin_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Spark3IoPin* other);
  friend void swap(Spark3IoPin& a, Spark3IoPin& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Spark3IoPin* New() const final {
    return CreateMaybeMessage<Spark3IoPin>(NULL);
  }

  Spark3IoPin* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Spark3IoPin>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Spark3IoPin& from);
  void MergeFrom(const Spark3IoPin& from);
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
  void InternalSwap(Spark3IoPin* other);
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

  // .blox.IoChannel top1 = 1;
  bool has_top1() const;
  void clear_top1();
  static const int kTop1FieldNumber = 1;
  private:
  const ::blox::IoChannel& _internal_top1() const;
  public:
  const ::blox::IoChannel& top1() const;
  ::blox::IoChannel* release_top1();
  ::blox::IoChannel* mutable_top1();
  void set_allocated_top1(::blox::IoChannel* top1);

  // .blox.IoChannel top2 = 2;
  bool has_top2() const;
  void clear_top2();
  static const int kTop2FieldNumber = 2;
  private:
  const ::blox::IoChannel& _internal_top2() const;
  public:
  const ::blox::IoChannel& top2() const;
  ::blox::IoChannel* release_top2();
  ::blox::IoChannel* mutable_top2();
  void set_allocated_top2(::blox::IoChannel* top2);

  // .blox.IoChannel top3 = 3;
  bool has_top3() const;
  void clear_top3();
  static const int kTop3FieldNumber = 3;
  private:
  const ::blox::IoChannel& _internal_top3() const;
  public:
  const ::blox::IoChannel& top3() const;
  ::blox::IoChannel* release_top3();
  ::blox::IoChannel* mutable_top3();
  void set_allocated_top3(::blox::IoChannel* top3);

  // .blox.IoChannel bottom1 = 4;
  bool has_bottom1() const;
  void clear_bottom1();
  static const int kBottom1FieldNumber = 4;
  private:
  const ::blox::IoChannel& _internal_bottom1() const;
  public:
  const ::blox::IoChannel& bottom1() const;
  ::blox::IoChannel* release_bottom1();
  ::blox::IoChannel* mutable_bottom1();
  void set_allocated_bottom1(::blox::IoChannel* bottom1);

  // .blox.IoChannel bottom2 = 5;
  bool has_bottom2() const;
  void clear_bottom2();
  static const int kBottom2FieldNumber = 5;
  private:
  const ::blox::IoChannel& _internal_bottom2() const;
  public:
  const ::blox::IoChannel& bottom2() const;
  ::blox::IoChannel* release_bottom2();
  ::blox::IoChannel* mutable_bottom2();
  void set_allocated_bottom2(::blox::IoChannel* bottom2);

  void clear_Pin();
  PinCase Pin_case() const;
  // @@protoc_insertion_point(class_scope:blox.Spark3IoPin)
 private:
  void set_has_top1();
  void set_has_top2();
  void set_has_top3();
  void set_has_bottom1();
  void set_has_bottom2();

  inline bool has_Pin() const;
  inline void clear_has_Pin();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  union PinUnion {
    PinUnion() {}
    ::blox::IoChannel* top1_;
    ::blox::IoChannel* top2_;
    ::blox::IoChannel* top3_;
    ::blox::IoChannel* bottom1_;
    ::blox::IoChannel* bottom2_;
  } Pin_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_Spark3Pins_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Spark3Pins : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Spark3Pins) */ {
 public:
  Spark3Pins();
  virtual ~Spark3Pins();

  Spark3Pins(const Spark3Pins& from);

  inline Spark3Pins& operator=(const Spark3Pins& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Spark3Pins(Spark3Pins&& from) noexcept
    : Spark3Pins() {
    *this = ::std::move(from);
  }

  inline Spark3Pins& operator=(Spark3Pins&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Spark3Pins& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Spark3Pins* internal_default_instance() {
    return reinterpret_cast<const Spark3Pins*>(
               &_Spark3Pins_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Spark3Pins* other);
  friend void swap(Spark3Pins& a, Spark3Pins& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Spark3Pins* New() const final {
    return CreateMaybeMessage<Spark3Pins>(NULL);
  }

  Spark3Pins* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Spark3Pins>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Spark3Pins& from);
  void MergeFrom(const Spark3Pins& from);
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
  void InternalSwap(Spark3Pins* other);
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

  // repeated .blox.Spark3IoPin pins = 1 [(.nanopb_test) = {
  int pins_size() const;
  void clear_pins();
  static const int kPinsFieldNumber = 1;
  ::blox::Spark3IoPin* mutable_pins(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::Spark3IoPin >*
      mutable_pins();
  const ::blox::Spark3IoPin& pins(int index) const;
  ::blox::Spark3IoPin* add_pins();
  const ::google::protobuf::RepeatedPtrField< ::blox::Spark3IoPin >&
      pins() const;

  // bool enableIoSupply5V = 2;
  void clear_enableiosupply5v();
  static const int kEnableIoSupply5VFieldNumber = 2;
  bool enableiosupply5v() const;
  void set_enableiosupply5v(bool value);

  // bool enableIoSupply12V = 3;
  void clear_enableiosupply12v();
  static const int kEnableIoSupply12VFieldNumber = 3;
  bool enableiosupply12v() const;
  void set_enableiosupply12v(bool value);

  // bool soundAlarm = 5;
  void clear_soundalarm();
  static const int kSoundAlarmFieldNumber = 5;
  bool soundalarm() const;
  void set_soundalarm(bool value);

  // uint32 voltage5 = 6 [(.nanopb_test) = {
  void clear_voltage5();
  static const int kVoltage5FieldNumber = 6;
  ::google::protobuf::uint32 voltage5() const;
  void set_voltage5(::google::protobuf::uint32 value);

  // uint32 voltage12 = 7 [(.nanopb_test) = {
  void clear_voltage12();
  static const int kVoltage12FieldNumber = 7;
  ::google::protobuf::uint32 voltage12() const;
  void set_voltage12(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.Spark3Pins)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::Spark3IoPin > pins_;
  bool enableiosupply5v_;
  bool enableiosupply12v_;
  bool soundalarm_;
  ::google::protobuf::uint32 voltage5_;
  ::google::protobuf::uint32 voltage12_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Spark3Pins_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Spark3IoPin

// .blox.IoChannel top1 = 1;
inline bool Spark3IoPin::has_top1() const {
  return Pin_case() == kTop1;
}
inline void Spark3IoPin::set_has_top1() {
  _oneof_case_[0] = kTop1;
}
inline const ::blox::IoChannel& Spark3IoPin::_internal_top1() const {
  return *Pin_.top1_;
}
inline ::blox::IoChannel* Spark3IoPin::release_top1() {
  // @@protoc_insertion_point(field_release:blox.Spark3IoPin.top1)
  if (has_top1()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.top1_;
    Pin_.top1_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark3IoPin::top1() const {
  // @@protoc_insertion_point(field_get:blox.Spark3IoPin.top1)
  return has_top1()
      ? *Pin_.top1_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark3IoPin::mutable_top1() {
  if (!has_top1()) {
    clear_Pin();
    set_has_top1();
    Pin_.top1_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark3IoPin.top1)
  return Pin_.top1_;
}

// .blox.IoChannel top2 = 2;
inline bool Spark3IoPin::has_top2() const {
  return Pin_case() == kTop2;
}
inline void Spark3IoPin::set_has_top2() {
  _oneof_case_[0] = kTop2;
}
inline const ::blox::IoChannel& Spark3IoPin::_internal_top2() const {
  return *Pin_.top2_;
}
inline ::blox::IoChannel* Spark3IoPin::release_top2() {
  // @@protoc_insertion_point(field_release:blox.Spark3IoPin.top2)
  if (has_top2()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.top2_;
    Pin_.top2_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark3IoPin::top2() const {
  // @@protoc_insertion_point(field_get:blox.Spark3IoPin.top2)
  return has_top2()
      ? *Pin_.top2_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark3IoPin::mutable_top2() {
  if (!has_top2()) {
    clear_Pin();
    set_has_top2();
    Pin_.top2_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark3IoPin.top2)
  return Pin_.top2_;
}

// .blox.IoChannel top3 = 3;
inline bool Spark3IoPin::has_top3() const {
  return Pin_case() == kTop3;
}
inline void Spark3IoPin::set_has_top3() {
  _oneof_case_[0] = kTop3;
}
inline const ::blox::IoChannel& Spark3IoPin::_internal_top3() const {
  return *Pin_.top3_;
}
inline ::blox::IoChannel* Spark3IoPin::release_top3() {
  // @@protoc_insertion_point(field_release:blox.Spark3IoPin.top3)
  if (has_top3()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.top3_;
    Pin_.top3_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark3IoPin::top3() const {
  // @@protoc_insertion_point(field_get:blox.Spark3IoPin.top3)
  return has_top3()
      ? *Pin_.top3_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark3IoPin::mutable_top3() {
  if (!has_top3()) {
    clear_Pin();
    set_has_top3();
    Pin_.top3_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark3IoPin.top3)
  return Pin_.top3_;
}

// .blox.IoChannel bottom1 = 4;
inline bool Spark3IoPin::has_bottom1() const {
  return Pin_case() == kBottom1;
}
inline void Spark3IoPin::set_has_bottom1() {
  _oneof_case_[0] = kBottom1;
}
inline const ::blox::IoChannel& Spark3IoPin::_internal_bottom1() const {
  return *Pin_.bottom1_;
}
inline ::blox::IoChannel* Spark3IoPin::release_bottom1() {
  // @@protoc_insertion_point(field_release:blox.Spark3IoPin.bottom1)
  if (has_bottom1()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.bottom1_;
    Pin_.bottom1_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark3IoPin::bottom1() const {
  // @@protoc_insertion_point(field_get:blox.Spark3IoPin.bottom1)
  return has_bottom1()
      ? *Pin_.bottom1_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark3IoPin::mutable_bottom1() {
  if (!has_bottom1()) {
    clear_Pin();
    set_has_bottom1();
    Pin_.bottom1_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark3IoPin.bottom1)
  return Pin_.bottom1_;
}

// .blox.IoChannel bottom2 = 5;
inline bool Spark3IoPin::has_bottom2() const {
  return Pin_case() == kBottom2;
}
inline void Spark3IoPin::set_has_bottom2() {
  _oneof_case_[0] = kBottom2;
}
inline const ::blox::IoChannel& Spark3IoPin::_internal_bottom2() const {
  return *Pin_.bottom2_;
}
inline ::blox::IoChannel* Spark3IoPin::release_bottom2() {
  // @@protoc_insertion_point(field_release:blox.Spark3IoPin.bottom2)
  if (has_bottom2()) {
    clear_has_Pin();
      ::blox::IoChannel* temp = Pin_.bottom2_;
    Pin_.bottom2_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::IoChannel& Spark3IoPin::bottom2() const {
  // @@protoc_insertion_point(field_get:blox.Spark3IoPin.bottom2)
  return has_bottom2()
      ? *Pin_.bottom2_
      : *reinterpret_cast< ::blox::IoChannel*>(&::blox::_IoChannel_default_instance_);
}
inline ::blox::IoChannel* Spark3IoPin::mutable_bottom2() {
  if (!has_bottom2()) {
    clear_Pin();
    set_has_bottom2();
    Pin_.bottom2_ = CreateMaybeMessage< ::blox::IoChannel >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.Spark3IoPin.bottom2)
  return Pin_.bottom2_;
}

inline bool Spark3IoPin::has_Pin() const {
  return Pin_case() != PIN_NOT_SET;
}
inline void Spark3IoPin::clear_has_Pin() {
  _oneof_case_[0] = PIN_NOT_SET;
}
inline Spark3IoPin::PinCase Spark3IoPin::Pin_case() const {
  return Spark3IoPin::PinCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// Spark3Pins

// repeated .blox.Spark3IoPin pins = 1 [(.nanopb_test) = {
inline int Spark3Pins::pins_size() const {
  return pins_.size();
}
inline void Spark3Pins::clear_pins() {
  pins_.Clear();
}
inline ::blox::Spark3IoPin* Spark3Pins::mutable_pins(int index) {
  // @@protoc_insertion_point(field_mutable:blox.Spark3Pins.pins)
  return pins_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::Spark3IoPin >*
Spark3Pins::mutable_pins() {
  // @@protoc_insertion_point(field_mutable_list:blox.Spark3Pins.pins)
  return &pins_;
}
inline const ::blox::Spark3IoPin& Spark3Pins::pins(int index) const {
  // @@protoc_insertion_point(field_get:blox.Spark3Pins.pins)
  return pins_.Get(index);
}
inline ::blox::Spark3IoPin* Spark3Pins::add_pins() {
  // @@protoc_insertion_point(field_add:blox.Spark3Pins.pins)
  return pins_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::Spark3IoPin >&
Spark3Pins::pins() const {
  // @@protoc_insertion_point(field_list:blox.Spark3Pins.pins)
  return pins_;
}

// bool enableIoSupply5V = 2;
inline void Spark3Pins::clear_enableiosupply5v() {
  enableiosupply5v_ = false;
}
inline bool Spark3Pins::enableiosupply5v() const {
  // @@protoc_insertion_point(field_get:blox.Spark3Pins.enableIoSupply5V)
  return enableiosupply5v_;
}
inline void Spark3Pins::set_enableiosupply5v(bool value) {
  
  enableiosupply5v_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark3Pins.enableIoSupply5V)
}

// bool enableIoSupply12V = 3;
inline void Spark3Pins::clear_enableiosupply12v() {
  enableiosupply12v_ = false;
}
inline bool Spark3Pins::enableiosupply12v() const {
  // @@protoc_insertion_point(field_get:blox.Spark3Pins.enableIoSupply12V)
  return enableiosupply12v_;
}
inline void Spark3Pins::set_enableiosupply12v(bool value) {
  
  enableiosupply12v_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark3Pins.enableIoSupply12V)
}

// bool soundAlarm = 5;
inline void Spark3Pins::clear_soundalarm() {
  soundalarm_ = false;
}
inline bool Spark3Pins::soundalarm() const {
  // @@protoc_insertion_point(field_get:blox.Spark3Pins.soundAlarm)
  return soundalarm_;
}
inline void Spark3Pins::set_soundalarm(bool value) {
  
  soundalarm_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark3Pins.soundAlarm)
}

// uint32 voltage5 = 6 [(.nanopb_test) = {
inline void Spark3Pins::clear_voltage5() {
  voltage5_ = 0u;
}
inline ::google::protobuf::uint32 Spark3Pins::voltage5() const {
  // @@protoc_insertion_point(field_get:blox.Spark3Pins.voltage5)
  return voltage5_;
}
inline void Spark3Pins::set_voltage5(::google::protobuf::uint32 value) {
  
  voltage5_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark3Pins.voltage5)
}

// uint32 voltage12 = 7 [(.nanopb_test) = {
inline void Spark3Pins::clear_voltage12() {
  voltage12_ = 0u;
}
inline ::google::protobuf::uint32 Spark3Pins::voltage12() const {
  // @@protoc_insertion_point(field_get:blox.Spark3Pins.voltage12)
  return voltage12_;
}
inline void Spark3Pins::set_voltage12(::google::protobuf::uint32 value) {
  
  voltage12_ = value;
  // @@protoc_insertion_point(field_set:blox.Spark3Pins.voltage12)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_Spark3Pins_5ftest_2eproto
