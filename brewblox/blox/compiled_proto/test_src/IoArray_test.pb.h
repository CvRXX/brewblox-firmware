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
#include "nanopb_test.pb.h"
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
namespace blox_test {
namespace IoArray {
class IoChannel;
class IoChannelDefaultTypeInternal;
extern IoChannelDefaultTypeInternal _IoChannel_default_instance_;
}  // namespace IoArray
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::IoArray::IoChannel* Arena::CreateMaybeMessage<::blox_test::IoArray::IoChannel>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace IoArray {

enum DigitalState {
  STATE_INACTIVE = 0,
  STATE_ACTIVE = 1,
  STATE_UNKNOWN = 2,
  STATE_REVERSE = 3,
  Inactive = 0,
  Active = 1,
  Unknown = 2,
  DigitalState_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DigitalState_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DigitalState_IsValid(int value);
const DigitalState DigitalState_MIN = STATE_INACTIVE;
const DigitalState DigitalState_MAX = STATE_REVERSE;
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
// ===================================================================

class IoChannel : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.IoArray.IoChannel) */ {
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

  // uint32 id = 1 [(.nanopb) = {
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.IoArray.IoChannel)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 id_;
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

// uint32 id = 1 [(.nanopb) = {
inline void IoChannel::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 IoChannel::id() const {
  // @@protoc_insertion_point(field_get:blox_test.IoArray.IoChannel.id)
  return id_;
}
inline void IoChannel::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox_test.IoArray.IoChannel.id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace IoArray
}  // namespace blox_test

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox_test::IoArray::DigitalState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::IoArray::DigitalState>() {
  return ::blox_test::IoArray::DigitalState_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_IoArray_5ftest_2eproto
