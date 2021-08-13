// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IoArray_test.proto

#ifndef PROTOBUF_INCLUDED_IoArray_5ftest_2eproto
#define PROTOBUF_INCLUDED_IoArray_5ftest_2eproto

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
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_IoArray_5ftest_2eproto 

namespace protobuf_IoArray_5ftest_2eproto {
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
}  // namespace protobuf_IoArray_5ftest_2eproto
namespace blox {
class IoChannel;
class IoChannelDefaultTypeInternal;
extern IoChannelDefaultTypeInternal _IoChannel_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::IoChannel* Arena::CreateMaybeMessage<::blox::IoChannel>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

enum DigitalState {
  STATE_INACTIVE = 0,
  STATE_ACTIVE = 1,
  STATE_UNKNOWN = 2,
  Inactive = 0,
  Active = 1,
  Unknown = 2,
  DigitalState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DigitalState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DigitalState_IsValid(int value);
const DigitalState DigitalState_MIN = STATE_INACTIVE;
const DigitalState DigitalState_MAX = STATE_UNKNOWN;
const int DigitalState_ARRAYSIZE = DigitalState_MAX + 1;

const ::google::protobuf::EnumDescriptor* DigitalState_descriptor();
inline const ::std::string& DigitalState_Name(DigitalState value) {
  return ::google::protobuf::internal::NameOfEnum(
    DigitalState_descriptor(), value);
}
inline bool DigitalState_Parse(
    const ::std::string& name, DigitalState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<DigitalState>(
    DigitalState_descriptor(), name, value);
}
enum ChannelConfig {
  CHANNEL_UNUSED = 0,
  CHANNEL_DRIVING_OFF = 1,
  CHANNEL_DRIVING_ON = 2,
  CHANNEL_DRIVING_REVERSE = 3,
  CHANNEL_DRIVING_BRAKE_LOW_SIDE = 4,
  CHANNEL_DRIVING_BRAKE_HIGH_SIDE = 5,
  CHANNEL_DRIVING_PWM = 6,
  CHANNEL_DRIVING_PWM_REVERSE = 7,
  CHANNEL_INPUT = 10,
  CHANNEL_UNKNOWN = 255,
  CHANNEL_ACTIVE_LOW = 1,
  CHANNEL_ACTIVE_HIGH = 2,
  ChannelConfig_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ChannelConfig_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ChannelConfig_IsValid(int value);
const ChannelConfig ChannelConfig_MIN = CHANNEL_UNUSED;
const ChannelConfig ChannelConfig_MAX = CHANNEL_UNKNOWN;
const int ChannelConfig_ARRAYSIZE = ChannelConfig_MAX + 1;

const ::google::protobuf::EnumDescriptor* ChannelConfig_descriptor();
inline const ::std::string& ChannelConfig_Name(ChannelConfig value) {
  return ::google::protobuf::internal::NameOfEnum(
    ChannelConfig_descriptor(), value);
}
inline bool ChannelConfig_Parse(
    const ::std::string& name, ChannelConfig* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ChannelConfig>(
    ChannelConfig_descriptor(), name, value);
}
// ===================================================================

class IoChannel : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.IoChannel) */ {
 public:
  IoChannel();
  virtual ~IoChannel();

  IoChannel(const IoChannel& from);

  inline IoChannel& operator=(const IoChannel& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  IoChannel(IoChannel&& from) noexcept
    : IoChannel() {
    *this = ::std::move(from);
  }

  inline IoChannel& operator=(IoChannel&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const IoChannel& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const IoChannel* internal_default_instance() {
    return reinterpret_cast<const IoChannel*>(
               &_IoChannel_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(IoChannel* other);
  friend void swap(IoChannel& a, IoChannel& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline IoChannel* New() const final {
    return CreateMaybeMessage<IoChannel>(NULL);
  }

  IoChannel* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<IoChannel>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const IoChannel& from);
  void MergeFrom(const IoChannel& from);
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
  void InternalSwap(IoChannel* other);
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

  // .blox.ChannelConfig config = 1;
  void clear_config();
  static const int kConfigFieldNumber = 1;
  ::blox::ChannelConfig config() const;
  void set_config(::blox::ChannelConfig value);

  // .blox.DigitalState state = 2;
  void clear_state();
  static const int kStateFieldNumber = 2;
  ::blox::DigitalState state() const;
  void set_state(::blox::DigitalState value);

  // @@protoc_insertion_point(class_scope:blox.IoChannel)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int config_;
  int state_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_IoArray_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// IoChannel

// .blox.ChannelConfig config = 1;
inline void IoChannel::clear_config() {
  config_ = 0;
}
inline ::blox::ChannelConfig IoChannel::config() const {
  // @@protoc_insertion_point(field_get:blox.IoChannel.config)
  return static_cast< ::blox::ChannelConfig >(config_);
}
inline void IoChannel::set_config(::blox::ChannelConfig value) {
  
  config_ = value;
  // @@protoc_insertion_point(field_set:blox.IoChannel.config)
}

// .blox.DigitalState state = 2;
inline void IoChannel::clear_state() {
  state_ = 0;
}
inline ::blox::DigitalState IoChannel::state() const {
  // @@protoc_insertion_point(field_get:blox.IoChannel.state)
  return static_cast< ::blox::DigitalState >(state_);
}
inline void IoChannel::set_state(::blox::DigitalState value) {
  
  state_ = value;
  // @@protoc_insertion_point(field_set:blox.IoChannel.state)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox::DigitalState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::DigitalState>() {
  return ::blox::DigitalState_descriptor();
}
template <> struct is_proto_enum< ::blox::ChannelConfig> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::ChannelConfig>() {
  return ::blox::ChannelConfig_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_IoArray_5ftest_2eproto
