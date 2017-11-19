// time.cpp
#include "utility/time.h"

namespace mgg {

namespace babkemon {

std::chrono::milliseconds Time::last_captured_time_;
game_time Time::current_time_ = 0;
boost::mutex Time::mutex_;

}

}