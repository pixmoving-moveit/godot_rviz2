//  Copyright 2024 Teddy Liu. All rights reserved.


#include "traffic_signal_report.hpp"
#include <string>

void TrafficLightReport::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_trafficlight_report"), &TrafficLightReport::get_trafficlight_report);
  TOPIC_SUBSCRIBER_BIND_METHODS(TrafficLightReport);
}

double TrafficLightReport::get_trafficlight_report()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->signals[0].elements[0].color;
}
