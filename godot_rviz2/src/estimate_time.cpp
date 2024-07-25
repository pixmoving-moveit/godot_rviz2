//  Copyright 2024 Teddy Liu. All rights reserved.
#include "string"
#include "estimate_time.hpp"


void EstimateTimeInfo::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_estimate_time_info"), &EstimateTimeInfo::get_estimate_time_info);
  TOPIC_SUBSCRIBER_BIND_METHODS(EstimateTimeInfo);

}

int32_t EstimateTimeInfo::get_estimate_time_info()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0;

  return last_msg.value()->estimate_time;
}


