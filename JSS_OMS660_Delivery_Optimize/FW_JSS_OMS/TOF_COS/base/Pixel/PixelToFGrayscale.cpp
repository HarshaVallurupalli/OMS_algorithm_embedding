#include "PixelToFGrayscale.h"

PixelToF_Grayscale::PixelToF_Grayscale()
{

}

PixelToF_Grayscale::~PixelToF_Grayscale()
{

}

uint16_t PixelToF_Grayscale::getValue() const
{
  return pixel;
}

bool PixelToF_Grayscale::getSaturated() const
{
  if (getValue() == TypePixelCode::PIXEL_CODE_SATURATION)
	{
	  return true;
	}
	return false;
}

bool PixelToF_Grayscale::getBadPixel() const
{
	if (getValue() == TypePixelCode::PIXEL_CODE_BAD)
	{
	  return true;
	}
	return false;
}
