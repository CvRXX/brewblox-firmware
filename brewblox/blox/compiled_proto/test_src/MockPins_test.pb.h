// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MockPins_test.proto

#ifndef PROTOBUF_INCLUDED_MockPins_5ftest_2eproto
#define PROTOBUF_INCLUDED_MockPins_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_MockPins_5ftest_2eproto 

namespace protobuf_MockPins_5ftest_2eproto {
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
}  // namespace protobuf_MockPins_5ftest_2eproto
namespace blox {
class MockPins;
class MockPinsDefaultTypeInternal;
extern MockPinsDefaultTypeInternal _MockPins_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::MockPins* Arena::CreateMaybeMessage<::blox::MockPins>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

// ===================================================================

class MockPins : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.MockPins) */ {
 public:
  MockPins();
  virtual ~MockPins();

  MockPins(const MockPins& from);

  inline MockPins& operator=(const MockPins& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MockPins(MockPins&& from) noexcept
    : MockPins() {
    *this = ::std::move(from);
  }

  inline MockPins& operator=(MockPins&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MockPins& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MockPins* internal_default_instance() {
    return reinterpret_cast<const MockPins*>(
               &_MockPins_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(MockPins* other);
  friend void swap(MockPins& a, MockPins& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MockPins* New() const final {
    return CreateMaybeMessage<MockPins>(NULL);
  }

  MockPins* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MockPins>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MockPins& from);
  void MergeFrom(const MockPins& from);
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
  void InternalSwap(MockPins* other);
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

  // repeated .blox.IoChannel channels = 2 [(.nanopb_test) = {
  int channels_size() const;
  void clear_channels();
  static const int kChannelsFieldNumber = 2;
  ::blox::IoChannel* mutable_channels(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::IoChannel >*
      mutable_channels();
  const ::blox::IoChannel& channels(int index) const;
  ::blox::IoChannel* add_channels();
  const ::google::protobuf::RepeatedPtrField< ::blox::IoChannel >&
      channels() const;

  // @@protoc_insertion_point(class_scope:blox.MockPins)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::IoChannel > channels_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_MockPins_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MockPins

// repeated .blox.IoChannel channels = 2 [(.nanopb_test) = {
inline int MockPins::channels_size() const {
  return channels_.size();
}
inline ::blox::IoChannel* MockPins::mutable_channels(int index) {
  // @@protoc_insertion_point(field_mutable:blox.MockPins.channels)
  return channels_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::IoChannel >*
MockPins::mutable_channels() {
  // @@protoc_insertion_point(field_mutable_list:blox.MockPins.channels)
  return &channels_;
}
inline const ::blox::IoChannel& MockPins::channels(int index) const {
  // @@protoc_insertion_point(field_get:blox.MockPins.channels)
  return channels_.Get(index);
}
inline ::blox::IoChannel* MockPins::add_channels() {
  // @@protoc_insertion_point(field_add:blox.MockPins.channels)
  return channels_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::IoChannel >&
MockPins::channels() const {
  // @@protoc_insertion_point(field_list:blox.MockPins.channels)
  return channels_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_MockPins_5ftest_2eproto
