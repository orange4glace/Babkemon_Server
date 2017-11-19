// item.h
#ifndef MGG_BABKEMON_BABKEMON_ITEM_H_
#define MGG_BABKEMON_BABKEMON_ITEM_H_

#include "item_group.h"
#include "item_type.h"

#include "item\item_packet.h"

#include <atomic>
#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

class Item {

  static std::atomic<int> next_item_id_;

  ItemGroup group_;
  ItemType type_;
  int id_;

  int amount_;
  int stack_size_;

  bool stackable_;

protected:
  Item(ItemGroup group, ItemType type);

  void set_stack_size(int val);

public:
  ItemGroup group() const;
  ItemType type() const;
  int id() const;

  int amount() const;
  int stack_size() const;
  bool stackable() const;

  void set_stackable(bool val);
  void set_amount(int val);

  int weight_size() const;

  virtual void Serialize(Proud::CMessage& a) const = 0;
  virtual void Deserialize(Proud::CMessage& a) = 0;

};

}

}

#endif