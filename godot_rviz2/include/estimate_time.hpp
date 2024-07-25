//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include "pixmoving_hmi_msgs/msg/v2d_current_station_info.hpp"



class EstimateTimeInfo : public RefCounted 
{
    GDCLASS(EstimateTimeInfo, RefCounted);
    TOPIC_SUBSCRIBER(EstimateTimeInfo, pixmoving_hmi_msgs::msg::V2dCurrentStationInfo);

public:
    int32_t get_estimate_time_info();

    EstimateTimeInfo() = default;
    ~EstimateTimeInfo() = default;

protected:
    static void _bind_methods();
};

