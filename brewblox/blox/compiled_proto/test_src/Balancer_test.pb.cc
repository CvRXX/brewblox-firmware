// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Balancer_test.proto

#include "Balancer_test.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_Balancer_5ftest_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BalancedActuator_Balancer_5ftest_2eproto;
namespace blox_test {
namespace Balancer {
class BalancedActuatorDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<BalancedActuator> _instance;
} _BalancedActuator_default_instance_;
class BlockDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Block> _instance;
} _Block_default_instance_;
}  // namespace Balancer
}  // namespace blox_test
static void InitDefaultsscc_info_BalancedActuator_Balancer_5ftest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::Balancer::_BalancedActuator_default_instance_;
    new (ptr) ::blox_test::Balancer::BalancedActuator();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::Balancer::BalancedActuator::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_BalancedActuator_Balancer_5ftest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_BalancedActuator_Balancer_5ftest_2eproto}, {}};

static void InitDefaultsscc_info_Block_Balancer_5ftest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::Balancer::_Block_default_instance_;
    new (ptr) ::blox_test::Balancer::Block();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::Balancer::Block::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Block_Balancer_5ftest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_Block_Balancer_5ftest_2eproto}, {
      &scc_info_BalancedActuator_Balancer_5ftest_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Balancer_5ftest_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Balancer_5ftest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Balancer_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_Balancer_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::Balancer::BalancedActuator, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox_test::Balancer::BalancedActuator, id_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Balancer::BalancedActuator, requested_),
  PROTOBUF_FIELD_OFFSET(::blox_test::Balancer::BalancedActuator, granted_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox_test::Balancer::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox_test::Balancer::Block, clients_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::Balancer::BalancedActuator)},
  { 8, -1, sizeof(::blox_test::Balancer::Block)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox_test::Balancer::_BalancedActuator_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox_test::Balancer::_Block_default_instance_),
};

const char descriptor_table_protodef_Balancer_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023Balancer_test.proto\022\022blox_test.Balance"
  "r\032\023brewblox_test.proto\032\021nanopb_test.prot"
  "o\"\211\001\n\020BalancedActuator\022\035\n\002id\030\001 \001(\rB\021\212\265\030\002"
  "0\001\212\265\030\002(\001\222\?\0028\010\022+\n\trequested\030\002 \001(\021B\030\212\265\030\0020\001"
  "\212\265\030\003\020\200 \222\?\0028 \212\265\030\002(\001\022)\n\007granted\030\003 \001(\021B\030\212\265\030"
  "\0020\001\212\265\030\003\020\200 \222\?\0028 \212\265\030\002(\001\"[\n\005Block\022C\n\007client"
  "s\030\001 \003(\0132$.blox_test.Balancer.BalancedAct"
  "uatorB\014\212\265\030\0020\001\212\265\030\002(\001:\r\212\265\030\003\030\265\002\212\265\030\002H\007b\006prot"
  "o3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Balancer_5ftest_2eproto_deps[2] = {
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_Balancer_5ftest_2eproto_sccs[2] = {
  &scc_info_BalancedActuator_Balancer_5ftest_2eproto.base,
  &scc_info_Block_Balancer_5ftest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Balancer_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Balancer_5ftest_2eproto = {
  false, false, descriptor_table_protodef_Balancer_5ftest_2eproto, "Balancer_test.proto", 322,
  &descriptor_table_Balancer_5ftest_2eproto_once, descriptor_table_Balancer_5ftest_2eproto_sccs, descriptor_table_Balancer_5ftest_2eproto_deps, 2, 2,
  schemas, file_default_instances, TableStruct_Balancer_5ftest_2eproto::offsets,
  file_level_metadata_Balancer_5ftest_2eproto, 2, file_level_enum_descriptors_Balancer_5ftest_2eproto, file_level_service_descriptors_Balancer_5ftest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_Balancer_5ftest_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_Balancer_5ftest_2eproto)), true);
namespace blox_test {
namespace Balancer {

// ===================================================================

void BalancedActuator::InitAsDefaultInstance() {
}
class BalancedActuator::_Internal {
 public:
};

BalancedActuator::BalancedActuator(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:blox_test.Balancer.BalancedActuator)
}
BalancedActuator::BalancedActuator(const BalancedActuator& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&granted_) -
    reinterpret_cast<char*>(&id_)) + sizeof(granted_));
  // @@protoc_insertion_point(copy_constructor:blox_test.Balancer.BalancedActuator)
}

void BalancedActuator::SharedCtor() {
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&granted_) -
      reinterpret_cast<char*>(&id_)) + sizeof(granted_));
}

BalancedActuator::~BalancedActuator() {
  // @@protoc_insertion_point(destructor:blox_test.Balancer.BalancedActuator)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void BalancedActuator::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void BalancedActuator::ArenaDtor(void* object) {
  BalancedActuator* _this = reinterpret_cast< BalancedActuator* >(object);
  (void)_this;
}
void BalancedActuator::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void BalancedActuator::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const BalancedActuator& BalancedActuator::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_BalancedActuator_Balancer_5ftest_2eproto.base);
  return *internal_default_instance();
}


void BalancedActuator::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.Balancer.BalancedActuator)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&granted_) -
      reinterpret_cast<char*>(&id_)) + sizeof(granted_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BalancedActuator::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint32 id = 1 [(.nanopb) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // sint32 requested = 2 [(.nanopb) = {
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          requested_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // sint32 granted = 3 [(.nanopb) = {
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          granted_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* BalancedActuator::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.Balancer.BalancedActuator)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1 [(.nanopb) = {
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  // sint32 requested = 2 [(.nanopb) = {
  if (this->requested() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(2, this->_internal_requested(), target);
  }

  // sint32 granted = 3 [(.nanopb) = {
  if (this->granted() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(3, this->_internal_granted(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.Balancer.BalancedActuator)
  return target;
}

size_t BalancedActuator::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.Balancer.BalancedActuator)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 id = 1 [(.nanopb) = {
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  // sint32 requested = 2 [(.nanopb) = {
  if (this->requested() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_requested());
  }

  // sint32 granted = 3 [(.nanopb) = {
  if (this->granted() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_granted());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void BalancedActuator::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.Balancer.BalancedActuator)
  GOOGLE_DCHECK_NE(&from, this);
  const BalancedActuator* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<BalancedActuator>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.Balancer.BalancedActuator)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.Balancer.BalancedActuator)
    MergeFrom(*source);
  }
}

void BalancedActuator::MergeFrom(const BalancedActuator& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.Balancer.BalancedActuator)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.requested() != 0) {
    _internal_set_requested(from._internal_requested());
  }
  if (from.granted() != 0) {
    _internal_set_granted(from._internal_granted());
  }
}

void BalancedActuator::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.Balancer.BalancedActuator)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BalancedActuator::CopyFrom(const BalancedActuator& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.Balancer.BalancedActuator)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BalancedActuator::IsInitialized() const {
  return true;
}

void BalancedActuator::InternalSwap(BalancedActuator* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BalancedActuator, granted_)
      + sizeof(BalancedActuator::granted_)
      - PROTOBUF_FIELD_OFFSET(BalancedActuator, id_)>(
          reinterpret_cast<char*>(&id_),
          reinterpret_cast<char*>(&other->id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BalancedActuator::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void Block::InitAsDefaultInstance() {
}
class Block::_Internal {
 public:
};

Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  clients_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:blox_test.Balancer.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      clients_(from.clients_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:blox_test.Balancer.Block)
}

void Block::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Block_Balancer_5ftest_2eproto.base);
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.Balancer.Block)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void Block::ArenaDtor(void* object) {
  Block* _this = reinterpret_cast< Block* >(object);
  (void)_this;
}
void Block::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Block& Block::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Block_Balancer_5ftest_2eproto.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.Balancer.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clients_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .blox_test.Balancer.BalancedActuator clients = 1 [(.brewblox.field) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_clients(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Block::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.Balancer.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .blox_test.Balancer.BalancedActuator clients = 1 [(.brewblox.field) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_clients_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_clients(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.Balancer.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.Balancer.Block)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox_test.Balancer.BalancedActuator clients = 1 [(.brewblox.field) = {
  total_size += 1UL * this->_internal_clients_size();
  for (const auto& msg : this->clients_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.Balancer.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Block>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.Balancer.Block)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.Balancer.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.Balancer.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  clients_.MergeFrom(from.clients_);
}

void Block::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.Balancer.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.Balancer.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::InternalSwap(Block* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  clients_.InternalSwap(&other->clients_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Balancer
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox_test::Balancer::BalancedActuator* Arena::CreateMaybeMessage< ::blox_test::Balancer::BalancedActuator >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::Balancer::BalancedActuator >(arena);
}
template<> PROTOBUF_NOINLINE ::blox_test::Balancer::Block* Arena::CreateMaybeMessage< ::blox_test::Balancer::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox_test::Balancer::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
