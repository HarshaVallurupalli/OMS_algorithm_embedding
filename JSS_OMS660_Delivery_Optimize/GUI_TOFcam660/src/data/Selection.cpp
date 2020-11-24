/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "Selection.h"
#include <QDebug>

Selection::Selection()
{
  clear();
}

Selection::~Selection()
{

}

void Selection::clear()
{
  x = 0;
  y = 0;
  width = 1;
  height = 1;
  dcsIndex = 0;

  emit selectionChanged(this->x, this->y, this->width, this->height);
}

void Selection::setSinglePixel(const int x, const int y)
{
  this->x = x;
  this->y = y;
  this->width = 1;
  this->height = 1;

  emit selectionChanged(this->x, this->y, this->width, this->height);
}

void Selection::setSinglePixel(const int x, const int y, const int dcsIndex)
{
  this->x = x;
  this->y = y;
  this->width = 1;
  this->height = 1;
  this->dcsIndex = dcsIndex;

  emit selectionChanged(this->x, this->y, this->width, this->height, this->dcsIndex);
}

void Selection::setRange(const int x1, const int x2, const int y1, const int y2)
{
  this->x = x1;
  this->y = y1;
  this->width = x2 - x1;
  if (this->width < 1)
  {
    this->width = 1;
  }
  this->height = y2 - y1;
  if (this->height < 1)
  {
    this->height = 1;
  }

  emit selectionChanged(this->x, this->y, this->width, this->height);
}

int Selection::getX() const
{
  return x;
}

int Selection::getY() const
{
  return y;
}

int Selection::getX2() const
{
  return (x + width - 1);
}

int Selection::getY2() const
{
  return (y + height - 1);
}

int Selection::getWidth() const
{
  return width;
}

int Selection::getHeight() const
{
  return height;
}

int Selection::getNumPixel() const
{
  return getWidth() * getHeight();
}

unsigned int Selection::getPixelIndex(unsigned int imageWidth) const
{
  unsigned int pixelIndex = (getY() * imageWidth) + getX();  
  return pixelIndex;
}

unsigned int Selection::getDcsIndex() const
{
  return dcsIndex;
}

bool Selection::contains(const int x, const int y) const
{
  if (x < this->x)
  {
    return false;
  }

  if (x > (this->x + this->width - 1))
  {
    return false;
  }

  if (y < this->y)
  {
    return false;
  }

  if (y > (this->y + this->height - 1))
  {
    return false;
  }

  return true;
}

