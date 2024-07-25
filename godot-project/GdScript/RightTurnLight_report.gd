extends TextureRect

var right_turn_report


func _ready():
	# 获取 TurnSignalReport 实例
	right_turn_report = TurnSignalReport.new()
	right_turn_report.subscribe("/vehicle/status/turn_indicators_status", false)

func _process(delta: float) -> void:
	if !right_turn_report.has_new():
		print("DEBUG: No new turn light data!")
		return

	var right_turn_status = right_turn_report.get_turn_report()


	# 根据条件设置可见性
	if right_turn_status == 3:
		self.visible = true
	else:
		self.visible = false

	# 标记数据为旧
	right_turn_report.set_old()
