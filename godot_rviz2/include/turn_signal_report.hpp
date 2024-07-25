//  Copyright 2024 Teddy Liu. All rights reserved.


#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include <autoware_auto_vehicle_msgs/msg/turn_indicators_report.hpp>


class TurnSignalReport : public RefCounted
{
  GDCLASS(TurnSignalReport, RefCounted);
  TOPIC_SUBSCRIBER(TurnSignalReport, autoware_auto_vehicle_msgs::msg::TurnIndicatorsReport);

public:
  double get_turn_report();

  TurnSignalReport() = default;
  ~TurnSignalReport() = default;

protected:
  static void _bind_methods();
};
