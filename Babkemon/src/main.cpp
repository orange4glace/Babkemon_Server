// main.cpp

#include "server.h"

#include "field\field_manager.h"
#include "battle\battle_manager.h"
#include "utility\scheduler.h"

int main()
{

  mgg::babkemon::Scheduler::Init();
  mgg::babkemon::Time::Init();
  mgg::babkemon::field::FieldManager::Init();
  mgg::babkemon::Server::Initialize();
  L_DEBUG << "";


  while (1);

  return 0;
}
