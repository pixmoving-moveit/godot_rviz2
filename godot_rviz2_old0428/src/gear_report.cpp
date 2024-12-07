//  Copyright 2024 Teddy Liu. All rights reserved.

#include "string"
#include "gear_report.hpp"

void GearReport::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("get_gear"), &GearReport::get_gear);
    TOPIC_SUBSCRIBER_BIND_METHODS(GearReport);
}

int GearReport::get_gear() 
{
    const auto last_msg = get_last_msg();
    if (!last_msg) return 0;  // Modify this accordingly based on your message structure

    // Access the gear information from the message and return it
    return last_msg.value()->report;  // Update this line based on the actual field name in your message
}