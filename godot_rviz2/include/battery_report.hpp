//  Copyright 2024 Teddy Liu. All rights reserved.

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include <pix_robobus_driver_msgs/msg/bms_report.hpp>


class BmsReportBattery : public RefCounted 
{
    GDCLASS(BmsReportBattery, RefCounted);
    TOPIC_SUBSCRIBER(BmsReportBattery, pix_robobus_driver_msgs::msg::BmsReport);

public:
    int get_battery();

    BmsReportBattery() = default;
    ~BmsReportBattery() = default;

protected:
    static void _bind_methods();
};
