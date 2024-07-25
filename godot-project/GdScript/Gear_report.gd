extends Sprite2D

var gear_report = GearReport.new()

func _ready():
	gear_report.subscribe("/vehicle/status/gear_status", false)

func _process(delta: float) -> void:
	if !gear_report.has_new():
		print("DEBUG: No new gear data!")
		return

	var current_gear = gear_report.get_gear()

	# Mapping according to the subscribed gear value
	var gear_text = match_gear(current_gear)
	print("Current Gear:", gear_text)

	# Displaying the current gear on GearLabel
	$GearLabel.text = gear_text

	gear_report.set_old()

# Mapping the gear value
func match_gear(gear_value):
	match gear_value:
		0: return "NONE"
		1: return "N"   # "NEURAL"
		2: return "D"   # "DRIVE"
		20: return "R"  # "REVERSE"
		22: return "P"  # "PARK"
		# Add more mappings here if necessary
		_: return "UNKNOWN"
