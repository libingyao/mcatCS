// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: kdt3.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "kdt3.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Node_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Node_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_kdt3_2eproto() {
  protobuf_AddDesc_kdt3_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "kdt3.proto");
  GOOGLE_CHECK(file != NULL);
  Node_descriptor_ = file->message_type(0);
  static const int Node_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, p_max_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, son_max_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, son_),
  };
  Node_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Node_descriptor_,
      Node::default_instance_,
      Node_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Node, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Node));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_kdt3_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Node_descriptor_, &Node::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_kdt3_2eproto() {
  delete Node::default_instance_;
  delete Node_reflection_;
}

void protobuf_AddDesc_kdt3_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nkdt3.proto\"I\n\004Node\022\r\n\005p_max\030\001 \003(\003\022\017\n\007s"
    "on_max\030\002 \003(\003\022\t\n\001x\030\003 \003(\001\022\t\n\001y\030\004 \003(\001\022\013\n\003so"
    "n\030\005 \003(\003", 87);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "kdt3.proto", &protobuf_RegisterTypes);
  Node::default_instance_ = new Node();
  Node::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_kdt3_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_kdt3_2eproto {
  StaticDescriptorInitializer_kdt3_2eproto() {
    protobuf_AddDesc_kdt3_2eproto();
  }
} static_descriptor_initializer_kdt3_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Node::kPMaxFieldNumber;
const int Node::kSonMaxFieldNumber;
const int Node::kXFieldNumber;
const int Node::kYFieldNumber;
const int Node::kSonFieldNumber;
#endif  // !_MSC_VER

Node::Node()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Node)
}

void Node::InitAsDefaultInstance() {
}

Node::Node(const Node& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Node)
}

void Node::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Node::~Node() {
  // @@protoc_insertion_point(destructor:Node)
  SharedDtor();
}

void Node::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Node::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Node::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Node_descriptor_;
}

const Node& Node::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_kdt3_2eproto();
  return *default_instance_;
}

Node* Node::default_instance_ = NULL;

Node* Node::New() const {
  return new Node;
}

void Node::Clear() {
  p_max_.Clear();
  son_max_.Clear();
  x_.Clear();
  y_.Clear();
  son_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Node::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Node)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated int64 p_max = 1;
      case 1: {
        if (tag == 8) {
         parse_p_max:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 8, input, this->mutable_p_max())));
        } else if (tag == 10) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_p_max())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(8)) goto parse_p_max;
        if (input->ExpectTag(16)) goto parse_son_max;
        break;
      }

      // repeated int64 son_max = 2;
      case 2: {
        if (tag == 16) {
         parse_son_max:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 16, input, this->mutable_son_max())));
        } else if (tag == 18) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_son_max())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_son_max;
        if (input->ExpectTag(25)) goto parse_x;
        break;
      }

      // repeated double x = 3;
      case 3: {
        if (tag == 25) {
         parse_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 1, 25, input, this->mutable_x())));
        } else if (tag == 26) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, this->mutable_x())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(25)) goto parse_x;
        if (input->ExpectTag(33)) goto parse_y;
        break;
      }

      // repeated double y = 4;
      case 4: {
        if (tag == 33) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 1, 33, input, this->mutable_y())));
        } else if (tag == 34) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, this->mutable_y())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(33)) goto parse_y;
        if (input->ExpectTag(40)) goto parse_son;
        break;
      }

      // repeated int64 son = 5;
      case 5: {
        if (tag == 40) {
         parse_son:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 1, 40, input, this->mutable_son())));
        } else if (tag == 42) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, this->mutable_son())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_son;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Node)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Node)
  return false;
#undef DO_
}

void Node::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Node)
  // repeated int64 p_max = 1;
  for (int i = 0; i < this->p_max_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      1, this->p_max(i), output);
  }

  // repeated int64 son_max = 2;
  for (int i = 0; i < this->son_max_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      2, this->son_max(i), output);
  }

  // repeated double x = 3;
  for (int i = 0; i < this->x_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(
      3, this->x(i), output);
  }

  // repeated double y = 4;
  for (int i = 0; i < this->y_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(
      4, this->y(i), output);
  }

  // repeated int64 son = 5;
  for (int i = 0; i < this->son_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(
      5, this->son(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Node)
}

::google::protobuf::uint8* Node::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Node)
  // repeated int64 p_max = 1;
  for (int i = 0; i < this->p_max_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(1, this->p_max(i), target);
  }

  // repeated int64 son_max = 2;
  for (int i = 0; i < this->son_max_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(2, this->son_max(i), target);
  }

  // repeated double x = 3;
  for (int i = 0; i < this->x_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteDoubleToArray(3, this->x(i), target);
  }

  // repeated double y = 4;
  for (int i = 0; i < this->y_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteDoubleToArray(4, this->y(i), target);
  }

  // repeated int64 son = 5;
  for (int i = 0; i < this->son_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt64ToArray(5, this->son(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Node)
  return target;
}

int Node::ByteSize() const {
  int total_size = 0;

  // repeated int64 p_max = 1;
  {
    int data_size = 0;
    for (int i = 0; i < this->p_max_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->p_max(i));
    }
    total_size += 1 * this->p_max_size() + data_size;
  }

  // repeated int64 son_max = 2;
  {
    int data_size = 0;
    for (int i = 0; i < this->son_max_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->son_max(i));
    }
    total_size += 1 * this->son_max_size() + data_size;
  }

  // repeated double x = 3;
  {
    int data_size = 0;
    data_size = 8 * this->x_size();
    total_size += 1 * this->x_size() + data_size;
  }

  // repeated double y = 4;
  {
    int data_size = 0;
    data_size = 8 * this->y_size();
    total_size += 1 * this->y_size() + data_size;
  }

  // repeated int64 son = 5;
  {
    int data_size = 0;
    for (int i = 0; i < this->son_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int64Size(this->son(i));
    }
    total_size += 1 * this->son_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Node::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Node* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Node*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Node::MergeFrom(const Node& from) {
  GOOGLE_CHECK_NE(&from, this);
  p_max_.MergeFrom(from.p_max_);
  son_max_.MergeFrom(from.son_max_);
  x_.MergeFrom(from.x_);
  y_.MergeFrom(from.y_);
  son_.MergeFrom(from.son_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Node::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Node::CopyFrom(const Node& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Node::IsInitialized() const {

  return true;
}

void Node::Swap(Node* other) {
  if (other != this) {
    p_max_.Swap(&other->p_max_);
    son_max_.Swap(&other->son_max_);
    x_.Swap(&other->x_);
    y_.Swap(&other->y_);
    son_.Swap(&other->son_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Node::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Node_descriptor_;
  metadata.reflection = Node_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)