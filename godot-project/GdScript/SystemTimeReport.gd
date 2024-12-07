
# extends Label

# func _ready():
# 	# 设置帧率
# 	set_process(true)

# func _process(delta):
# 	# 获取当前系统时间的字典表示
# 	var time = Time.get_time_dict_from_system()
	
# 	# 将时间格式化为字符串，并赋值给 Label 的 text 属性
# 	text = "%02d:%02d:%02d" % [time.hour, time.minute, time.second]



extends Label

func _ready():
	# 设置帧率
	set_process(true)

func _process(delta):
	# 获取当前系统日期时间的字典表示
	var time = Time.get_datetime_dict_from_system()
	
	# 格式化日期和时间字符串
	# var datetime_str = "%04d-%02d-%02d    %02d:%02d:%02d" % [time["year"], time["month"], time["day"], time["hour"], time["minute"], time["second"]]
	var date_str = "%04d-%02d-%02d" % [time["year"], time["month"], time["day"]]
	var time_str = "%02d:%02d:%02d" % [time["hour"], time["minute"], time["second"]]
	# 星期转换为中文
	var weekdays = ["星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期日"]
	var weekday_str = weekdays[time["weekday"] - 1]

	# 更新 Label 控件的 text 属性
	# text = "%s      %s" % [datetime_str, weekday_str]

	text = "%s    %s              %s" % [date_str, weekday_str, time_str]


