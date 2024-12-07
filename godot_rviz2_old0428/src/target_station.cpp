//  Copyright 2024 Teddy Liu. All rights reserved.
#include "string"
#include "target_station.hpp"

// #include "core/ustring.h" // 引入Godot字符串类型的头文件
#include <iostream>  // 添加头文件以使用 std::cout





void TargetStationInfo::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_target_station_info"), &TargetStationInfo::get_target_station_info);
  TOPIC_SUBSCRIBER_BIND_METHODS(TargetStationInfo);

}


String TargetStationInfo::get_target_station_info()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) {
    std::cout << "没有最新的消息。" << std::endl;  // 输出调试信息到控制台
    return "Null";
  }

  // 从ROS 2消息中获取目标车站信息的字符串
  const auto& target_station_name = last_msg.value()->target_station.name;

  // 将字符串内容转换为Godot引擎的String类型
  String godot_string = String::utf8(target_station_name.c_str());

  // 输出获取到的当前车站信息
  std::cout << "获取到的目标车站信息为：" << godot_string.utf8().get_data() << std::endl;

  return godot_string;
}