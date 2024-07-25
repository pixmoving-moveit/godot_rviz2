//  Copyright 2024 Teddy Liu. All rights reserved.

#include "string"

#include "brake_report.hpp"  


// 获取油门百分比的方法
void ActuationStatusBrake::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_brake"), &ActuationStatusBrake::get_brake);
  TOPIC_SUBSCRIBER_BIND_METHODS(ActuationStatusBrake);
}

float ActuationStatusBrake::get_brake()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->status.brake_status;
}