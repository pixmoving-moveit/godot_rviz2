extends Control

var current_station_info_report = CurrentStationInfo.new()
var target_station_info_report = TargetStationInfo.new()
var estimate_time_info_report = EstimateTimeInfo.new()
var target_distance_info_report = TargetDistanceInfo.new()


var CurrentStation
var TargetStation
var EstimateTime
var TargetDistance

var max_estimate_time_value : float = 100.0


func _ready():
	current_station_info_report.subscribe("/app/display/current_station_info", false)
	target_station_info_report.subscribe("/app/display/current_station_info", false)
	estimate_time_info_report.subscribe("/app/display/current_station_info", false)

	
	# 查找名为CurrentStation\TargetStation\EstimateTimeSlider 的节点
	CurrentStation = get_node("CurrentStation")
	TargetStation = get_node("TargetStation")
	EstimateTime = get_node("EstimateTimeSlider")

	# 设置 HSlider 的范围
	EstimateTime.min_value = 0
	EstimateTime.max_value = max_estimate_time_value

	# 检查节点是否找到
	if (CurrentStation == null) or (TargetStation == null):
		print("Error: CurrentStation node not found.")
	else:
		print("CurrentStation node found.")

func _process(_delta):
	current_station_report()
	target_station_report()
	estimate_time_report()

func current_station_report():
	if !current_station_info_report.has_new():
		print("DEBUG: No new current station data!")
		return
	
	# 获取当前站点信息
	var current_station_info = current_station_info_report.get_current_station_info()

	if CurrentStation != null:
		CurrentStation.text = current_station_info
		print("当前车站信息：", current_station_info)  # 输出获取到的当前车站信息

	else:
		CurrentStation.text = "未知站点信息"
		print("Error: CurrentStation node not found.")

	current_station_info_report.set_old()

func target_station_report():
	if !target_station_info_report.has_new():
		print("DEBUG: No new next station data!")
		return

	var target_station_info = target_station_info_report.get_target_station_info()

	if TargetStation != null:
		TargetStation.text = target_station_info
		print("目标车站信息：", target_station_info)  # 输出获取到的目标车站信息

	else:
		CurrentStation.text = "未知站点信息"
		print("Error: TargetStation node not found.")

	target_station_info_report.set_old()

	
func estimate_time_report():
	if !estimate_time_info_report.has_new():
		print("No new estimate time.")
		return

	var estimate_time_info = estimate_time_info_report.get_estimate_time_info()

	if EstimateTime != null:
		# 保证 estimate_time_info 在合理的范围内
		EstimateTime.value = clamp(estimate_time_info, 0, max_estimate_time_value)
	else:
		print("Error: estimate time node not found.")

	estimate_time_info_report.set_old()
