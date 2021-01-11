/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef SELECTION_H
#define SELECTION_H

#include <QObject>

class Selection: public QObject
{
  Q_OBJECT

  public:
    Selection();
    ~Selection();
    void clear();
    int getX() const;
    int getY() const;
    int getX2() const;
    int getY2() const;
    int getWidth() const;
    int getHeight() const;
    int getNumPixel() const;
    unsigned int getPixelIndex(unsigned int imageWidth) const;
    unsigned int getDcsIndex() const;
    bool contains(const int x, const int y) const;

  signals:
    void selectionChanged(const int x, const int y, const int width, const int height);
    void selectionChanged(const int x, const int y, const int width, const int height, const int dcsIndex);

  public slots:
    void setSinglePixel(const int x, const int y);
    void setSinglePixel(const int x, const int y, const int dcsIndex);
    void setRange(const int x1, const int x2, const int y1, const int y2);

  private:
    int x;
    int y;
    int width;
    int height;
    int dcsIndex;
};

#endif // SELECTION_H
