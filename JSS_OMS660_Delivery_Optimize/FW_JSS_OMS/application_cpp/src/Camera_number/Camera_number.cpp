#include "Camera_number.h"

Camera_number* Camera_number::instance = nullptr;

using namespace std;

uint8_t Camera_number::get_old_cam_num() {
	return old_cam_num;
}

void Camera_number::set_old_cam_num(uint8_t camera_number_new) {
	old_cam_num = camera_number_new;
}

uint8_t Camera_number::get_new_cam_num() {
	return new_cam_num;
}

void Camera_number::set_new_cam_num(uint8_t camera_number_new) {
	new_cam_num = camera_number_new;
}

Camera_number* Camera_number::getInstance() {
	 if (!instance) {
		 instance = new Camera_number;
	 }
	 return instance;
}
