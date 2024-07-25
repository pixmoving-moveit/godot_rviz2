//  Copyright 2024 Teddy Liu. All rights reserved.

#include "string"

#include "throttle_report.hpp"  


// 获取油门百分比的方法
void ActuationStatusThrottle::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_throttle"), &ActuationStatusThrottle::get_throttle);
  TOPIC_SUBSCRIBER_BIND_METHODS(ActuationStatusThrottle);
}

float ActuationStatusThrottle::get_throttle()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->status.accel_status;
}