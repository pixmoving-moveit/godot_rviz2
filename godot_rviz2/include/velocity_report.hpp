//
//  Copyright 2022 Yukihiro Saito. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "core/variant/variant.h"
#include "topic_subscriber.hpp"

#include "autoware_vehicle_msgs/msg/velocity_report.hpp"

/**
 * @class VelocityReport
 * @brief The VelocityReport class provides an interface to obtain the current velocity of the
 * vehicle.
 *
 * This class subscribes to the VelocityReport message from Autoware and provides a method to
 * retrieve the current longitudinal velocity of the vehicle.
 */
class VelocityReport : public RefCounted
{
  GDCLASS(VelocityReport, RefCounted);
  TOPIC_SUBSCRIBER(VelocityReport, autoware_vehicle_msgs::msg::VelocityReport);

public:
  /**
   * @brief Retrieves the current vehicle velocity.
   *
   * @return double Current longitudinal velocity of the vehicle.
   */
  double get_velocity();

  VelocityReport() = default;
  ~VelocityReport() = default;

protected:
  /**
   * @brief Binds methods to the Godot system.
   */
  static void _bind_methods();
};
