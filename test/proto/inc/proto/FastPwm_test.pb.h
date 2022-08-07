// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FastPwm_test.proto

#ifndef PROTOBUF_INCLUDED_FastPwm_5ftest_2eproto
#define PROTOBUF_INCLUDED_FastPwm_5ftest_2eproto

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
#include "Constraints_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_FastPwm_5ftest_2eproto 

namespace protobuf_FastPwm_5ftest_2eproto {
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
}  // namespace protobuf_FastPwm_5ftest_2eproto
namespace blox_test {
namespace FastPwm {
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace FastPwm
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::FastPwm::Block* Arena::CreateMaybeMessage<::blox_test::FastPwm::Block>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace FastPwm {

enum PwmFrequency {
  PWM_FREQ_OFF = 0,
  PWM_FREQ_100HZ = 1,
  PWM_FREQ_200HZ = 2,
  PWM_FREQ_2000HZ = 3,
  PwmFrequency_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  PwmFrequency_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool PwmFrequency_IsValid(int value);
const PwmFrequency PwmFrequency_MIN = PWM_FREQ_OFF;
const PwmFrequency PwmFrequency_MAX = PWM_FREQ_2000HZ;
const int PwmFrequency_ARRAYSIZE = PwmFrequency_MAX + 1;

const ::google::protobuf::EnumDescriptor* PwmFrequency_descriptor();
inline const ::std::string& PwmFrequency_Name(PwmFrequency value) {
  return ::google::protobuf::internal::NameOfEnum(
    PwmFrequency_descriptor(), value);
}
inline bool PwmFrequency_Parse(
    const ::std::string& name, PwmFrequency* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PwmFrequency>(
    PwmFrequency_descriptor(), name, value);
}
// ===================================================================

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.FastPwm.Block) */ {
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
    0;

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

  // .blox_test.Constraints.AnalogConstraints constrainedBy = 7;
  bool has_constrainedby() const;
  void clear_constrainedby();
  static const int kConstrainedByFieldNumber = 7;
  private:
  const ::blox_test::Constraints::AnalogConstraints& _internal_constrainedby() const;
  public:
  const ::blox_test::Constraints::AnalogConstraints& constrainedby() const;
  ::blox_test::Constraints::AnalogConstraints* release_constrainedby();
  ::blox_test::Constraints::AnalogConstraints* mutable_constrainedby();
  void set_allocated_constrainedby(::blox_test::Constraints::AnalogConstraints* constrainedby);

  // uint32 hwDevice = 1 [(.nanopb) = {
  void clear_hwdevice();
  static const int kHwDeviceFieldNumber = 1;
  ::google::protobuf::uint32 hwdevice() const;
  void set_hwdevice(::google::protobuf::uint32 value);

  // uint32 channel = 2 [(.nanopb) = {
  void clear_channel();
  static const int kChannelFieldNumber = 2;
  ::google::protobuf::uint32 channel() const;
  void set_channel(::google::protobuf::uint32 value);

  // .blox_test.FastPwm.PwmFrequency frequency = 3;
  void clear_frequency();
  static const int kFrequencyFieldNumber = 3;
  ::blox_test::FastPwm::PwmFrequency frequency() const;
  void set_frequency(::blox_test::FastPwm::PwmFrequency value);

  // sint32 setting = 4 [(.nanopb) = {
  void clear_setting();
  static const int kSettingFieldNumber = 4;
  ::google::protobuf::int32 setting() const;
  void set_setting(::google::protobuf::int32 value);

  // sint32 desiredSetting = 5 [(.nanopb) = {
  void clear_desiredsetting();
  static const int kDesiredSettingFieldNumber = 5;
  ::google::protobuf::int32 desiredsetting() const;
  void set_desiredsetting(::google::protobuf::int32 value);

  // sint32 value = 6 [(.nanopb) = {
  void clear_value();
  static const int kValueFieldNumber = 6;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // bool enabled = 8;
  void clear_enabled();
  static const int kEnabledFieldNumber = 8;
  bool enabled() const;
  void set_enabled(bool value);

  // @@protoc_insertion_point(class_scope:blox_test.FastPwm.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::blox_test::Constraints::AnalogConstraints* constrainedby_;
  ::google::protobuf::uint32 hwdevice_;
  ::google::protobuf::uint32 channel_;
  int frequency_;
  ::google::protobuf::int32 setting_;
  ::google::protobuf::int32 desiredsetting_;
  ::google::protobuf::int32 value_;
  bool enabled_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_FastPwm_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Block

// uint32 hwDevice = 1 [(.nanopb) = {
inline void Block::clear_hwdevice() {
  hwdevice_ = 0u;
}
inline ::google::protobuf::uint32 Block::hwdevice() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.hwDevice)
  return hwdevice_;
}
inline void Block::set_hwdevice(::google::protobuf::uint32 value) {
  
  hwdevice_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.hwDevice)
}

// uint32 channel = 2 [(.nanopb) = {
inline void Block::clear_channel() {
  channel_ = 0u;
}
inline ::google::protobuf::uint32 Block::channel() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.channel)
  return channel_;
}
inline void Block::set_channel(::google::protobuf::uint32 value) {
  
  channel_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.channel)
}

// .blox_test.FastPwm.PwmFrequency frequency = 3;
inline void Block::clear_frequency() {
  frequency_ = 0;
}
inline ::blox_test::FastPwm::PwmFrequency Block::frequency() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.frequency)
  return static_cast< ::blox_test::FastPwm::PwmFrequency >(frequency_);
}
inline void Block::set_frequency(::blox_test::FastPwm::PwmFrequency value) {
  
  frequency_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.frequency)
}

// sint32 setting = 4 [(.nanopb) = {
inline void Block::clear_setting() {
  setting_ = 0;
}
inline ::google::protobuf::int32 Block::setting() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.setting)
  return setting_;
}
inline void Block::set_setting(::google::protobuf::int32 value) {
  
  setting_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.setting)
}

// sint32 desiredSetting = 5 [(.nanopb) = {
inline void Block::clear_desiredsetting() {
  desiredsetting_ = 0;
}
inline ::google::protobuf::int32 Block::desiredsetting() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.desiredSetting)
  return desiredsetting_;
}
inline void Block::set_desiredsetting(::google::protobuf::int32 value) {
  
  desiredsetting_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.desiredSetting)
}

// sint32 value = 6 [(.nanopb) = {
inline void Block::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 Block::value() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.value)
  return value_;
}
inline void Block::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.value)
}

// .blox_test.Constraints.AnalogConstraints constrainedBy = 7;
inline bool Block::has_constrainedby() const {
  return this != internal_default_instance() && constrainedby_ != NULL;
}
inline const ::blox_test::Constraints::AnalogConstraints& Block::_internal_constrainedby() const {
  return *constrainedby_;
}
inline const ::blox_test::Constraints::AnalogConstraints& Block::constrainedby() const {
  const ::blox_test::Constraints::AnalogConstraints* p = constrainedby_;
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.constrainedBy)
  return p != NULL ? *p : *reinterpret_cast<const ::blox_test::Constraints::AnalogConstraints*>(
      &::blox_test::Constraints::_AnalogConstraints_default_instance_);
}
inline ::blox_test::Constraints::AnalogConstraints* Block::release_constrainedby() {
  // @@protoc_insertion_point(field_release:blox_test.FastPwm.Block.constrainedBy)
  
  ::blox_test::Constraints::AnalogConstraints* temp = constrainedby_;
  constrainedby_ = NULL;
  return temp;
}
inline ::blox_test::Constraints::AnalogConstraints* Block::mutable_constrainedby() {
  
  if (constrainedby_ == NULL) {
    auto* p = CreateMaybeMessage<::blox_test::Constraints::AnalogConstraints>(GetArenaNoVirtual());
    constrainedby_ = p;
  }
  // @@protoc_insertion_point(field_mutable:blox_test.FastPwm.Block.constrainedBy)
  return constrainedby_;
}
inline void Block::set_allocated_constrainedby(::blox_test::Constraints::AnalogConstraints* constrainedby) {
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
  // @@protoc_insertion_point(field_set_allocated:blox_test.FastPwm.Block.constrainedBy)
}

// bool enabled = 8;
inline void Block::clear_enabled() {
  enabled_ = false;
}
inline bool Block::enabled() const {
  // @@protoc_insertion_point(field_get:blox_test.FastPwm.Block.enabled)
  return enabled_;
}
inline void Block::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:blox_test.FastPwm.Block.enabled)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace FastPwm
}  // namespace blox_test

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox_test::FastPwm::PwmFrequency> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::FastPwm::PwmFrequency>() {
  return ::blox_test::FastPwm::PwmFrequency_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_FastPwm_5ftest_2eproto
