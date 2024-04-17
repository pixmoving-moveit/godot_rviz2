extends MeshInstance3D

var dynamic_objects = DynamicObjects.new()
var only_known_object = true
var object_3d_model_mode = false

var pool_size = 100
var model_types = {
	"car": {"scene": preload("res://DynamicObject/Car.tscn"), "pool": []},
	"pedestrian": {"scene": preload("res://DynamicObject/Pedestrian.tscn"), "pool": []},
	"truck": {"scene": preload("res://DynamicObject/Truck.tscn"), "pool": []},
	"trailer": {"scene": preload("res://DynamicObject/Trailer.tscn"), "pool": []},
	"bus": {"scene": preload("res://DynamicObject/Bus.tscn"), "pool": []},
	"bicycle": {"scene": preload("res://DynamicObject/Bicycle.tscn"), "pool": []},
	"motorcycle": {"scene": preload("res://DynamicObject/Motorcycle.tscn"), "pool": []}
}

func _ready():
	dynamic_objects.subscribe("/perception/object_recognition/objects", false)
	initialize_model_pools()

func initialize_model_pools():
	for model_type in model_types:
		for i in range(pool_size):
			var node = model_types[model_type]["scene"].instantiate()
			node.visible = false
			add_child(node)
			model_types[model_type]["pool"].append(node)

func _process(_delta):
	if not dynamic_objects.has_new():
		return

	if object_3d_model_mode:
		var object_list = dynamic_objects.get_dynamic_object_list(only_known_object)
		reset_visibility()
		update_models(object_list)
	else:
		var arr = []
		arr.resize(Mesh.ARRAY_MAX)
		var verts = PackedVector3Array()
		var normals = PackedVector3Array()

		var triangle_list = dynamic_objects.get_triangle_list(only_known_object)

		for point in triangle_list:
			verts.append(point["position"])
			normals.append(point["normal"])

		arr[Mesh.ARRAY_VERTEX] = verts
		arr[Mesh.ARRAY_NORMAL] = normals

		if !verts.is_empty():
			reset_visibility()
			mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, arr)
	dynamic_objects.set_old()

func reset_visibility():
	mesh.clear_surfaces()
	for model_type in model_types:
		for node in model_types[model_type]["pool"]:
			node.visible = false

func update_models(object_list):
	var model_indices = {}
	for model_type in model_types.keys():
		model_indices[model_type] = 0
	for object in object_list:
		var model_type = object["class"]
		if model_type in model_types:
			var pool = model_types[model_type]["pool"]
			var index = model_indices[model_type]
			if index < pool.size():
				var node = pool[index]
				node.visible = true
				node.set_position(Vector3(object["position"].x, object["position"].y - object["size"].y * 0.5, object["position"].z))
				node.set_rotation(object["rotation"])
				model_indices[model_type] += 1

func _on_OnlyKnownObjectCheckButton_toggled(button_pressed):
	only_known_object = button_pressed

func _on_d_model_object_toggled(toggled_on):
	object_3d_model_mode = toggled_on
