//  Copyright 2024 Teddy Liu. All rights reserved.


#include "string"
#include "battery_report.hpp"

void BmsReportBattery::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("get_battery"), &BmsReportBattery::get_battery);
    TOPIC_SUBSCRIBER_BIND_METHODS(BmsReportBattery);
}

int BmsReportBattery::get_battery() 
{
    const auto last_msg = get_last_msg();
    if (!last_msg) return 0;  // Modify this accordingly based on your message structure

    // Access the gear information from the message and return it
    return last_msg.value()->battery_soc;  // Update this line based on the actual field name in your message
}