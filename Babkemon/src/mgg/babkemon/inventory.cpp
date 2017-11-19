// inventory.cpp
#include "inventory.h"

#include "common\item\item_packet.h"
#include "common\item_factory.h"

#include "pidl\common_pidl.h"

namespace mgg {

namespace babkemon {

Inventory::Inventory(Player* const player) :
  player_(player),
  capacity_(10),
  weight_(0) {

}

int Inventory::AddItem(Item* const item) {
  assert(!items_.count(item->id()));
  if (item->stackable()) {
    int ret = IncreaseItemAmount(item->type(), item->amount());
    delete item;
    return ret;
  }
  else {
    if (item->weight_size() > remained_weight()) return false;
    items_[item->id()] = item;

    // NETCODE
    item::ItemPacket packet(item);
    pidl::CommonPIDL::instance().ProxyAddItem(player_, packet);
    return item->amount();
  }
  return 0;
}

void Inventory::RemoveItem(int item_id) {
  assert(items_.count(item_id));
  auto item = items_[item_id];
  weight_ -= item->weight_size();
  items_.erase(item_id);

  // NETCODE
  pidl::CommonPIDL::instance().ProxyRemoveItem(player_, item_id);
  delete item;
}

Item* const Inventory::GetItem(int item_id) {
  if (items_.count(item_id)) return items_[item_id];
  return nullptr;
}

int Inventory::IncreaseItemAmount(ItemType type, int amount) {
  Item* item = nullptr;
  // Find item if has
  for (auto& item_kv : items_) {
    auto i = item_kv.second;
    if (i->type() == type) {
      item = i;
      break;
    }
  }
  if (item == nullptr) {
    if (remained_weight() == 0) return 0;
    item = ItemFactory::CreateItem(type);
    items_[item->id()] = item;

    // NETCODE
    item::ItemPacket packet(item);
    pidl::CommonPIDL::instance().ProxyAddItem(player_, packet);
  }
  assert(item->stackable());
  int available = remained_weight() * item->stack_size()
    + (item->amount() % item->stack_size());
  int amount_get = amount;
  if (available < amount) amount_get = available;

  SetItemAmount(item->id(), amount_get);
  return amount_get;
}

int Inventory::DecreaseItemAmount(ItemType type, int amount) {
  Item* item = nullptr;
  // Find item if has
  for (auto& item_kv : items_) {
    auto i = item_kv.second;
    if (i->type() == type) {
      item = i;
      break;
    }
  }
  if (item == nullptr) return 0;
  assert(item->stackable());
  int dec = (item->amount() < amount ? item->amount() : amount);

  SetItemAmount(item->id(), item->amount() - dec);
  if (item->amount() == 0) RemoveItem(item->id());
  return dec;
}

void Inventory::SetItemAmount(int id, int amount) {
  assert(items_.count(id));
  auto item = items_[id];
  weight_ -= item->weight_size();
  item->set_amount(amount);
  weight_ += item->weight_size();

  // NETCODE
  pidl::CommonPIDL::instance().ProxySetItemAmount(player_, id, amount);
}

int Inventory::remained_weight() const {
  return capacity_ - weight_;
}

}

}