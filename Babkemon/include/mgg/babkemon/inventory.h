// inventory.h
#ifndef MGG_BABKEMON_INVENTORY_H_
#define MGG_BABKEMON_INVENTORY_H_

#include "common\item.h"

#include "player.h"

#include <map>

namespace mgg {

namespace babkemon {

class Inventory {

  Player* player_;

  std::map<int, Item*> items_;

  int capacity_;
  int weight_;

public:
  Inventory(Player* const player);

  int AddItem(Item* const item);
  void RemoveItem(int item_id);
  Item* const GetItem(int item_id);
  int IncreaseItemAmount(ItemType type, int amount = 1);
  int DecreaseItemAmount(ItemType type, int amount = 1);
  void SetItemAmount(int item_id, int amount);
  
  int remained_weight() const;
};

}

}

#endif