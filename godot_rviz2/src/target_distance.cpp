//  Copyright 2024 Teddy Liu. All rights reserved.
#include "string"
#include "target_distance.hpp"


void TargetDistanceInfo::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_target_distance_info"), &TargetDistanceInfo::get_target_distance_info);
  TOPIC_SUBSCRIBER_BIND_METHODS(TargetDistanceInfo);

}

int32_t TargetDistanceInfo::get_target_distance_info()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0;

  return last_msg.value()->target_distance;
}


