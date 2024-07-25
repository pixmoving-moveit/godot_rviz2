extends TextureRect

var traffic_signal_report = TrafficLightReport
var signal_states = []  # 存储交通信号灯状态的数组
var timer : Timer

func _ready():
	# 获取 TrafficLightReport 实例
	traffic_signal_report = TrafficLightReport.new()
	traffic_signal_report.subscribe("/perception/traffic_light_recognition/traffic_signals", false)

	# 创建计时器节点
	timer = Timer.new()
	add_child(timer)
	timer.wait_time = 0.5  # 设置计时器等待时间为0.5秒
	timer.one_shot = true
	#timer.connect("timeout", self, "_on_timer_timeout")
	timer.timeout.connect(_on_timer_timeout)

	# 设置节点初始不可见
	self.visible = false

func _process(delta: float) -> void:
	if !traffic_signal_report.has_new():
		print("No new traffic light data.")
		# self.visible = false
		return

	var current_signal = traffic_signal_report.get_trafficlight_report()

	# 在添加新数据之前检查数组的大小
	if signal_states.size() >= 10:
		signal_states.remove(0)  # 删除数组的第一个元素

	# 将当前信号状态添加到数组中
	signal_states.append(current_signal)

	# 标记数据为旧
	traffic_signal_report.set_old()

	# 重置计时器
	timer.stop()
	timer.start()

	# 渲染时使用数组中的最新状态
	render_latest_signal_state()

func _on_timer_timeout():
	# 在计时器超时时清空数组
	signal_states.clear()

	# 重新设置可见性
	render_latest_signal_state()

func render_latest_signal_state():
	# 如果数组不为空，使用最新的状态来设置可见性
	if signal_states.size() > 0:
		var latest_state = signal_states[signal_states.size() - 1]
		self.visible = (latest_state == 2)
	else:
		# 如果数组为空，设置可见性为false
		self.visible = false

