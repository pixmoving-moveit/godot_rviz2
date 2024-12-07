//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"
#include "autoware_auto_vehicle_msgs/msg/engage.hpp"


class AutowareEngage : public RefCounted
{
  GDCLASS(AutowareEngage, RefCounted);
  TOPIC_SUBSCRIBER(AutowareEngage, autoware_auto_vehicle_msgs::msg::Engage);

public:
  double get_engage();

  AutowareEngage() = default;
  ~AutowareEngage() = default;

protected:
  static void _bind_methods();
};
