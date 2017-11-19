// item.cpp
#include "common/item.h"

namespace mgg {

namespace babkemon {

std::atomic<int> Item::next_item_id_(0);

Item::Item(ItemGroup group, ItemType type) :
  id_(),
  group_(group),
  type_(type),
  amount_(1),
  stack_size_(1),
  stackable_(false) {

}

void Item::set_stack_size(int val) {
  stack_size_ = val;
}

ItemGroup Item::group() const {
  return group_;
}

ItemType Item::type() const {
  return type_;
}

int Item::id() const {
  return id_;
}

int Item::amount() const {
  return amount_;
}

int Item::stack_size() const {
  return stack_size_;
}

bool Item::stackable() const {
  return stackable_;
}

void Item::set_stackable(bool val) {
  stackable_ = val;
}

void Item::set_amount(int val) {
  amount_ = val;
}

int Item::weight_size() const {
  return amount_ / stack_size_ + (amount_ % stack_size_ ? 1 : 0);
}

}

}