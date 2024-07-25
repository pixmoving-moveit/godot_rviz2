//  Copyright 2024 Teddy Liu. All rights reserved.


#include "turn_signal_report.hpp"

#include <string>

void TurnSignalReport::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_turn_report"), &TurnSignalReport::get_turn_report);
  TOPIC_SUBSCRIBER_BIND_METHODS(TurnSignalReport);
}

double TurnSignalReport::get_turn_report()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->report;
}
