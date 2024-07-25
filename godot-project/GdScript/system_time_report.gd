# 绘制表盘数字
extends Control
# 基础参数
var center = Vector2(100, 100) # 表盘中心
var r = 50 # 表盘半径缩小为50
var h_r = 25 # 时针长度缩小为25
var m_r = 30 # 分针长度缩小为30
var s_r = 35 # 秒针长度缩小为35

var default_font = ThemeDB.fallback_font
var default_font_size = ThemeDB.fallback_font_size

func _process(delta):
	queue_redraw()

func _draw():
	# 获取当前时间信息
	var dict = Time.get_datetime_dict_from_system()
	# 绘制表盘
	draw_circle(center, 50, Color("#ccc")) # 缩小为50
	# 绘制时针、分针、秒针
	draw_line(center, (Vector2.UP * h_r).rotated((2 * PI / 12) * dict["hour"]) + center, Color("#444"), 3) # 将时针的宽度调整为3
	draw_line(center, (Vector2.UP * m_r).rotated((2 * PI / 60) * dict["minute"]) + center, Color("#444"), 2) # 将分针的宽度调整为2
	draw_line(center, (Vector2.UP * s_r).rotated((2 * PI / 60) * dict["second"]) + center, Color("#444"), 1) # 将秒针的宽度调整为1

	# 绘制表盘数字
	for i in range(1, 13):
		# 计算数字的位置
		var digit_position = (Vector2.UP * 40).rotated((2 * PI / 12) * i) + center - Vector2(5, -5) # 将数字位置的距离表盘中心的距离调整为40
		# 在数字位置绘制数字
		draw_string(default_font, digit_position, str(i), HORIZONTAL_ALIGNMENT_CENTER, -1, default_font_size, Color("#444"))


