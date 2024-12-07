extends Sprite2D

var mode_report = ModeReport.new()

func _ready():
	mode_report.subscribe("/vehicle/status/control_mode", false)

func _process(_delta):
	if !mode_report.has_new():
		print("DEBUG: No new mode data!")
		return

	var current_mode = mode_report.get_mode_report()

	# 根据订阅到的值进行映射
	var mode_text = match_mode(current_mode)
	print("Current Mode:", mode_text)


	# 将当前MODE显示在 ModeLabel 上
	$ModeLabel.text = mode_text

	mode_report.set_old()

# 根据档位值进行映射
func match_mode(mode_value):
	match mode_value:
		0: return "NO_COMMAND"
		1: return "AUTO"	
		2: return "A_STEER_ONLY"	
		3: return "A_VELOCITY_ONLY"  
		4: return "MANUAL"	
		5: return "DISENGAGED"	
		6: return "NOT_READY"	
		# 如果有其他值，可以在这里继续添加映射关系
		_: return "UNKNOWN"
		
