//  Copyright 2024 Teddy Liu. All rights reserved.


#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include <autoware_perception_msgs/msg/traffic_signal_array.hpp>



class TrafficLightReport : public RefCounted
{
  GDCLASS(TrafficLightReport, RefCounted);
  TOPIC_SUBSCRIBER(TrafficLightReport, autoware_perception_msgs::msg::TrafficSignalArray);

public:
  double get_trafficlight_report();

  TrafficLightReport() = default;
  ~TrafficLightReport() = default;

protected:
  static void _bind_methods();
};
