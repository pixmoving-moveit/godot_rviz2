//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include "pixmoving_hmi_msgs/msg/v2d_current_station_info.hpp"



class CurrentStationInfo : public RefCounted 
{
    GDCLASS(CurrentStationInfo, RefCounted);
    TOPIC_SUBSCRIBER(CurrentStationInfo, pixmoving_hmi_msgs::msg::V2dCurrentStationInfo);

public:
    String get_current_station_info();


    CurrentStationInfo() = default;
    ~CurrentStationInfo() = default;

protected:
    static void _bind_methods();
};

