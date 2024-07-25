extends Sprite2D

var throttle_report = ActuationStatusThrottle.new()
var throttle_scale = 5.3/180.0

func _ready():
	throttle_report.subscribe("/vehicle/status/actuation_status", false)

func _process(_delta):
	if !throttle_report.has_new():
		print("DEBUG: No new throttle data!")
		return
	var throttle = throttle_report.get_throttle() * 100.0
	
	$ProgressBar.value = throttle
	
	# angle of rotation of the pointer
	if throttle < 0:
		$ThrottleHand.set_rotation(0 * throttle_scale)
	else:
		$ThrottleHand.set_rotation(throttle * throttle_scale)
	
	throttle_report.set_old()
