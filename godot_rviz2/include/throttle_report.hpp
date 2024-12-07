//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include <tier4_vehicle_msgs/msg/actuation_status_stamped.hpp>


class ActuationStatusThrottle : public RefCounted 
{
    GDCLASS(ActuationStatusThrottle, RefCounted);
    TOPIC_SUBSCRIBER(ActuationStatusThrottle, tier4_vehicle_msgs::msg::ActuationStatusStamped);

public:
    float get_throttle();

    ActuationStatusThrottle() = default;
    ~ActuationStatusThrottle() = default;

protected:
    static void _bind_methods();
};