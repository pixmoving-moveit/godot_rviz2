//  Copyright 2024 Teddy Liu. All rights reserved.


#include "autoware_mode_report.hpp"

#include <string>

void ModeReport::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_mode_report"), &ModeReport::get_mode_report);
  TOPIC_SUBSCRIBER_BIND_METHODS(ModeReport);
}

int8_t ModeReport::get_mode_report()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->mode;
}
