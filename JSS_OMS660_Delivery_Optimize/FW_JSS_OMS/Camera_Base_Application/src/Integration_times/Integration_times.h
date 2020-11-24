using namespace std;
#include <stdint.h>

class Integration_times {
	private:
	uint16_t Old_Integration_time_low;
	uint16_t Old_Integration_time_high;
	uint16_t New_Integration_time_low;
	uint16_t New_Integration_time_high;
	float Scaling_factor;

	static Integration_times* instance;

Integration_times(){
	Old_Integration_time_low=1;
	Old_Integration_time_high=1;
	New_Integration_time_low=1;
	New_Integration_time_high=1;
	Scaling_factor=1;
	}
	public:
	 uint16_t get_New_Integration_time_low();
	 void set_New_Integration_time_low(uint16_t Integration_time_low);

	 uint16_t get_New_Integration_time_high();
	 void set_New_Integration_time_high(uint16_t Integration_time_high);

	 uint16_t get_Old_Integration_time_low();
	 void set_Old_Integration_time_low(uint16_t Integration_time_low);

	 uint16_t get_Old_Integration_time_high();
	 void set_Old_Integration_time_high(uint16_t Integration_time_high);

	 void Calculate_Scaling_factor();
	 float get_Scaling_factor();

	 static Integration_times* getInstance();
};




