extends Sprite2D

var brake_report = ActuationStatusBrake.new()

func _ready():
	brake_report.subscribe("/vehicle/status/actuation_status", false)

func _process(delta: float) -> void:
	if !brake_report.has_new():
		print("DEBUG: No new brake data!")
		return
	
	var brake_value = brake_report.get_brake() * 100.0
	
	# 更新 ProgressBar 的值
	$ProgressBar.value = brake_value
	brake_report.set_old()

