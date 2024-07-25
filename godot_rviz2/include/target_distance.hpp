//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include "pixmoving_hmi_msgs/msg/v2d_current_station_info.hpp"



class TargetDistanceInfo : public RefCounted 
{
    GDCLASS(TargetDistanceInfo, RefCounted);
    TOPIC_SUBSCRIBER(TargetDistanceInfo, pixmoving_hmi_msgs::msg::V2dCurrentStationInfo);

public:
    int32_t get_target_distance_info();

    TargetDistanceInfo() = default;
    ~TargetDistanceInfo() = default;

protected:
    static void _bind_methods();
};

