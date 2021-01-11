#include "Integration_times.h"
#include <math.h>

Integration_times* Integration_times::instance = nullptr;

using namespace std;

uint16_t Integration_times::get_Old_Integration_time_low()
{
	return Old_Integration_time_low;
}
uint16_t Integration_times::get_New_Integration_time_low()
{
	return New_Integration_time_low;
}
//
uint16_t Integration_times::get_Old_Integration_time_high()
{
	return 	Old_Integration_time_high;
}
uint16_t Integration_times::get_New_Integration_time_high()
{
	return 	New_Integration_time_high;
}
//
void Integration_times::set_Old_Integration_time_low(uint16_t Integration_time)
{
	Old_Integration_time_low = Integration_time;
}
void Integration_times::set_New_Integration_time_low(uint16_t Integration_time)
{
	New_Integration_time_low = Integration_time;
}
//
void Integration_times::set_Old_Integration_time_high(uint16_t Integration_time)
{
	Old_Integration_time_high = Integration_time;
}
void Integration_times::set_New_Integration_time_high(uint16_t Integration_time)
{
	New_Integration_time_high = Integration_time;
}
//
void Integration_times::Calculate_Scaling_factor()
{
	Scaling_factor = sqrt((float)(New_Integration_time_high)/(float)(New_Integration_time_low));// scaling factor = int time high/int time low
}
float Integration_times::get_Scaling_factor()
{
	return Scaling_factor;
}

Integration_times* Integration_times::getInstance()
{
	 if (!instance)
	 {
		 instance = new Integration_times;
	 }
	 return instance;
}
