//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include <autoware_auto_vehicle_msgs/msg/gear_report.hpp>


class GearReport : public RefCounted 
{
    GDCLASS(GearReport, RefCounted);
    TOPIC_SUBSCRIBER(GearReport, autoware_auto_vehicle_msgs::msg::GearReport);

public:
    int get_gear();

    GearReport() = default;
    ~GearReport() = default;

protected:
    static void _bind_methods();
};