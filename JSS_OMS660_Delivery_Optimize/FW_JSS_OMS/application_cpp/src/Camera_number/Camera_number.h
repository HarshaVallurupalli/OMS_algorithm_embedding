using namespace std;
#include<stdint.h>

#define CAM1 1
#define CAM2 2
#define CAM3 3
#define CAM4 4

class Camera_number {
	private:
	uint8_t new_cam_num;

	uint8_t old_cam_num;

	static Camera_number* instance;

	Camera_number() {
		new_cam_num = 1;
		old_cam_num = 1;
	}

	public:
	 uint8_t get_old_cam_num();

	 void set_old_cam_num(uint8_t camera_number_new);

	 uint8_t get_new_cam_num();

	 void set_new_cam_num(uint8_t camera_number_new);

	 static Camera_number* getInstance();
};
