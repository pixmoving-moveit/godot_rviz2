//  Copyright 2024 Teddy Liu. All rights reserved.


#include "autoware_engage.hpp"

#include <string>

void AutowareEngage::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_engage"), &AutowareEngage::get_engage);
  TOPIC_SUBSCRIBER_BIND_METHODS(AutowareEngage);
}

double AutowareEngage::get_engage()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->engage;
}