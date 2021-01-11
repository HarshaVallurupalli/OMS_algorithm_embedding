/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5:       Copyright (C) 2019 The Qt Company
* - QwtPlot3D: Copyright (C) 2003-2005 Michael Bieber
***************************************************************************************/

#include "PlotSurface.h"
#include <QDebug>
//#include <GL/glu.h>
#define GL_GLEXT_PROTOTYPES


#define MAX_AMPLITUDE_LOG  63
#define MAX_AMPLITUDE    2895
#define MAX_AMPLITUDE_PN 4095
#define NUM_COLORS     6000


using namespace Qwt3D;


PlotSurface::PlotSurface(uint width_, uint height_, Settings &set_, QWidget *parent) : SurfacePlot (parent),
set(set_),
width(width_),
height(height_)
{    
    usrColor = nullptr;
    stdColor = nullptr;
    functionDistance = nullptr;
    fullScreenState = false;

    tripData = new Qwt3D::Triple* [width];
    for(uint i=0; i<width; i++)
        tripData[i] = new Qwt3D::Triple[height];

    connect(&set.cloud, SIGNAL(fovChanged()), this, SLOT(fovChanged()));

}

PlotSurface::~PlotSurface(){

}


void PlotSurface::initialisation(int scrWidth, int scrHeight){

    screenWidth = scrWidth;
    screenHeight = scrHeight;

    coordinates()->setGridLines(true,true);
    setCoordinateStyle(NOCOORD);
    setFloorStyle(Qwt3D::NOFLOOR);
    setSmoothMesh(true);
    legend()->setLimits(set.getRangeMin(), set.getRangeMax());
    showColorLegend(set.cloud.isShowLegend());
    setColor();

    /*if(scrWidth > 0 && scrHeight > 0){
        if(screenWidth > screenHeight)
            resizeGL(screenWidth, screenWidth);
        else resizeGL(screenHeight, screenHeight);

    } else {
        updateGL();
    }*/

    resizeGL(2500, 2500);

}

void PlotSurface::setFullScreenState(bool state){
    fullScreenState = state;
}

void PlotSurface::updateResizeGL()
{
    resizeGL(2500, 2500);
}

void PlotSurface::createData(){

    Qwt3D::SurfacePlot::createData();

    updateGraphicAtributes();
}

void PlotSurface::keyPressEvent(QKeyEvent *e){

    emit keyPressed(true);

    Qwt3D::SurfacePlot::keyPressEvent(e);

    if(e->key() == Qt::Key_Escape){
        fullScreenState = false;
        emit fullScreen(false);
    }

}

void PlotSurface::mouseDoubleClickEvent(QMouseEvent* e){
    Q_UNUSED(e)
    fullScreenState = !fullScreenState;
    emit fullScreen(fullScreenState);
}

void PlotSurface::keyReleaseEvent(QKeyEvent *e){
    emit keyPressed(false);
    Qwt3D::SurfacePlot::keyPressEvent(e);
}

void PlotSurface::mousePressEvent(QMouseEvent *e){
    emit keyPressed(true);
    Qwt3D::SurfacePlot::mousePressEvent(e);
}

void PlotSurface::mouseReleaseEvent(QMouseEvent *e){
    emit keyPressed(false);
    Qwt3D::SurfacePlot::mouseReleaseEvent(e);
}


void PlotSurface::updateGUI(int **distance, int **amplitude){

    double x_min, y_min, x_max, y_max;

    if(!epcTransform.isInitialised()){
        epcTransform.initialisation(set.cloud.getFOV(), width, height, set.cloud.getCameraMatrix(), set.cloud.getDistortionCoeffs());
    }

    if(set.cloud.isPoints())
        functionDistance->create();   

    if(set.cloud.isCartesian())
        transformation(set.cloud.getAngleObjectZ(), distance, width, height);

    epcTransform.getRect(x_min, y_min, x_max, y_max, set.cloud.isUndistortion());

    static bool firstTime = true;

    if(set.cloud.isPoints() || firstTime){
        firstTime = false;
        functionDistance->setMesh(static_cast<uint>(width), static_cast<uint>(height));
        functionDistance->setDomain(0, width, 0, height);
        functionDistance->setMin(x_min, y_min, set.getRangeMin());
        functionDistance->setMax(x_max, y_max, set.getRangeMax());
    }


    if(!set.cloud.isPoints()){
        loadData(distance, amplitude, set.cloud.isCartesian());
    }

    /*if(screenWidth > screenHeight)
        resizeGL(screenWidth, screenWidth);
    else resizeGL(screenHeight, screenHeight);

    updateGL();*/

    resizeGL(2500, 2500);

    updateGL();
}


void PlotSurface::fovChanged(){
    epcTransform.resetInitialisation();
}

void PlotSurface::updateGraphicAtributes(){

    uint cellWidth = set.cloud.getCellWidth();
    uint numCells  = set.cloud.getNumberCells();
    int offsetX = set.cloud.getGridOffsetX();
    int offsetY = set.cloud.getGridOffsetY();
    int offsetZ = set.cloud.getGridOffsetZ();                
    EpcColor gridColor = set.cloud.getGridColor();    
    EpcColor axisColor = set.cloud.getAxisColor();
    axisColor.a = gridColor.a;
    double angle = set.cloud.getFOV() / 2.0;
    uint minDistance = set.getRangeMin();
    uint maxDistance = set.getRangeMax();
    double w2 = width/2.0;
    double h2 = height/2.0;


    if(set.cloud.isCartesian()){

        if(set.cloud.isShowAxis2D())
            axisPiramide2D(angle, minDistance, maxDistance, w2, offsetY + static_cast<int>(height/2), 0.0, axisColor);

        if(set.cloud.isShowAxis3D())
            axisPiramide3D(angle, angle, minDistance, maxDistance, w2, h2, 0.0, axisColor);

    }else{

        if(set.cloud.isShowAxis2D())
            axisCube2D(minDistance, maxDistance, w2, offsetY, 0.0, axisColor);

        if(set.cloud.isShowAxis3D())
            axisCube3D(minDistance, maxDistance, w2, h2, 0.0, axisColor);
    }

    if(set.cloud.isShowGrid()){

        offsetX += width  / 2;
        offsetY += height / 2;

        if(set.cloud.isRectGrid())
            gridRect(numCells, cellWidth, offsetX, offsetY, offsetZ, gridColor);
        else
            gridPolar(angle, minDistance, numCells, cellWidth, offsetX, offsetY, offsetZ, gridColor);

    }

    displayLabels(set.cloud.isShowLabels());

}

void PlotSurface::gridRect(uint numCells, double widthCell, double offsetX, double offsetY, double offsetZ, EpcColor  &color){

    double sz =  widthCell * numCells;
    double dx = widthCell;
    double x0 = 0 + offsetX  - sz/2;
    double x1 = sz + offsetX - sz/2;
    double z0 = 0 + offsetZ;
    double z1 = sz + offsetZ;
    double y = 0 + offsetY;

    Qwt3D::setDeviceLineWidth( 1 );    
    glColor4d(color.r, color.g, color.b, color.a);

    glPushMatrix();
    glBegin( GL_LINES );

    glVertex3d(x0, y, z0);
    glVertex3d(x1, y, z0);

    glVertex3d(x1, y, z0);
    glVertex3d(x1, y, z1);

    glVertex3d(x1, y, z1);
    glVertex3d(x0, y, z1);

    glVertex3d(x0, y, z1);
    glVertex3d(x0, y, z0);

    for(uint i=0; i<numCells; i++){
        glVertex3d(x0 + i*dx, y, z0);
        glVertex3d(x0 + i*dx, y, z1);
    }

    for(uint i=0; i<numCells; i++){
        glVertex3d(x0, y, z0 + i*dx);
        glVertex3d(x1, y, z0 + i*dx);
    }

    glEnd();
    glPopMatrix();

}

void PlotSurface::gridPolar(double alfaX, uint distMin, uint numCells, double widthCell, double offsetX, double offsetY, double offsetZ, EpcColor &color){

    double x0, x1, x2, x3, y0, z0, z1;
    float alfa1 = static_cast<float>(PI * (90.0 - alfaX) / 180.0);
    float dAlfa = static_cast<float>(PI * 2 * alfaX  / 180);
    uint distMax = static_cast<uint>(distMin + numCells * widthCell);

    alfaX = PI * alfaX / 180;
    double dx1 = distMin * sin(alfaX);
    double dx2 = distMax * sin(alfaX);

    Qwt3D::setDeviceLineWidth( 1 );
    glColor4d(color.r, color.g, color.b, color.a);

    glPushMatrix();
    glBegin( GL_LINES );

    x0 = -dx1 + offsetX;
    x1 =  dx1 + offsetX;
    x2 = -dx2 + offsetX;
    x3 =  dx2 + offsetX;
    y0 =  offsetY;
    z0 = distMin * cos(alfaX) + offsetZ;
    z1 = distMax * cos(alfaX) + offsetZ;

    glVertex3d(x0, y0, z0);
    glVertex3d(x2, y0, z1);

    glVertex3d(x1, y0, z0);
    glVertex3d(x3, y0, z1);

    glVertex3d(offsetX, y0, z0);
    glVertex3d(offsetX, y0, (numCells-1) * widthCell);

    glEnd();

    for(uint i=1; i< numCells; i++){
        drawArc(static_cast<float>(offsetX), static_cast<float>(offsetY), static_cast<float>(offsetZ), static_cast<float>(widthCell * i), alfa1, dAlfa, 20);
    }

    glPopMatrix();


}



void PlotSurface::axisPiramide2D(double alfaX, double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color){

    double x0, x1, x2, x3, y0, z0, z1;
    float alfa1 = static_cast<float>(PI * (90.0 - alfaX) / 180.0);
    float dAlfa = static_cast<float>(PI * 2 * alfaX  / 180.0);

    alfaX = PI * alfaX / 180;

    //distMin = distMin / cos(alfaX);
    //distMax = distMax / cos(alfaX);


    double dx1 = distMin * sin(alfaX);
    double dx2 = distMax * sin(alfaX);
    int lineWidth = set.cloud.getAxisLineWidth();

    Qwt3D::setDeviceLineWidth( lineWidth );
    glColor4d(color.r, color.g, color.b, color.a);

    glPushMatrix();
    glBegin( GL_LINES );

    x0 = -dx1 + offsetX;
    x1 =  dx1 + offsetX;
    x2 = -dx2 + offsetX;
    x3 =  dx2 + offsetX;
    y0 =  offsetY;
    z0 = distMin * cos(alfaX) + offsetZ;
    z1 = distMax * cos(alfaX) + offsetZ;

    glVertex3d(x0, y0, z0);
    glVertex3d(x2, y0, z1);

    glVertex3d(x1, y0, z0);
    glVertex3d(x3, y0, z1);

    glEnd();

    drawArc(static_cast<float>(offsetX), static_cast<float>(offsetY), static_cast<float>(offsetZ), static_cast<float>(distMin), alfa1, dAlfa, 20);
    drawArc(static_cast<float>(offsetX), static_cast<float>(offsetY), static_cast<float>(offsetZ), static_cast<float>(distMax), alfa1, dAlfa, 20);

    glPopMatrix();

}


void PlotSurface::axisPiramide3D(double alfaX, double alfaY, double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor  &color){

    double x0, x1, x2, x3, y0, y1, y2, y3, z0, z1;

    alfaX = PI * alfaX /180;
    alfaY = PI * alfaY /180;

    double dx1 = distMin * sin(alfaX);
    double dx2 = distMax * sin(alfaX);

    double dy1 = distMin * sin(alfaY);
    double dy2 = distMax * sin(alfaY);
    int lineWidth = set.cloud.getAxisLineWidth();


    Qwt3D::setDeviceLineWidth( lineWidth );
     glColor4d(color.r, color.g, color.b, color.a);

    glPushMatrix();    
    glBegin( GL_LINES );

    x0 = -dx1 + offsetX;
    x1 =  dx1 + offsetX;
    y0 =  -dy1 + offsetY;
    y1 =  dy1 + offsetY;
    z0 = distMin * cos(alfaX) + offsetZ;

    /*glVertex3d(x0, y0, z0);
    glVertex3d(x1, y0, z0);

    glVertex3d(x1, y0, z0);
    glVertex3d(x1, y1, z0);

    glVertex3d(x1, y1, z0);
    glVertex3d(x0, y1, z0);

    glVertex3d(x0, y1, z0);
    glVertex3d(x0, y0, z0);*/


    x2 = -dx2 + offsetX;
    x3 =  dx2 + offsetX;
    y2 =  -dy2 + offsetY;
    y3 =  dy2  + offsetY;
    z1 = distMax * cos(alfaX) + offsetZ;

    /*glVertex3d(x2, y2, z1);
    glVertex3d(x3, y2, z1);

    glVertex3d(x3, y2, z1);
    glVertex3d(x3, y3, z1);

    glVertex3d(x3, y3, z1);
    glVertex3d(x2, y3, z1);

    glVertex3d(x2, y3, z1);
    glVertex3d(x2, y2, z1);*/

    glVertex3d(x0, y0, z0);
    glVertex3d(x2, y2, z1);

    glVertex3d(x1, y1, z0);
    glVertex3d(x3, y3, z1);

    glVertex3d(x0, y1, z0);
    glVertex3d(x2, y3, z1);

    glVertex3d(x1, y0, z0);
    glVertex3d(x3, y2, z1);

    glEnd();
    glPopMatrix();


}


void PlotSurface::axisCube2D(double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color){

    double x0, x1, y0, z0, z1;
    double dx1 = width/2;

    int lineWidth = set.cloud.getAxisLineWidth();
    Qwt3D::setDeviceLineWidth( lineWidth );
     glColor4d(color.r, color.g, color.b, color.a);

    glPushMatrix();
    glBegin( GL_LINES );

    y0 = offsetY;
    x0 = -dx1 + offsetX;
    x1 =  dx1 + offsetX;
    z0 = distMin + offsetZ;
    z1 = distMax + offsetZ;

    glVertex3d(x0, y0, z0);
    glVertex3d(x0, y0, z1);

    glVertex3d(x1, y0, z0);
    glVertex3d(x1, y0, z1);

    glVertex3d(x0, y0, z0);
    glVertex3d(x1, y0, z0);

    glVertex3d(x0, y0, z1);
    glVertex3d(x1, y0, z1);

    glEnd();
    glPopMatrix();

}



void PlotSurface::axisCube3D(double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color){

    double x0, x1, x2, x3, y0, y1, y2, y3, z0, z1;
    double dx1 = width/2;
    double dx2 = dx1;
    double dy1 = height/2;
    double dy2 = dy1;

    int lineWidth = set.cloud.getAxisLineWidth();
    Qwt3D::setDeviceLineWidth( lineWidth );
    glColor4d(color.r, color.g, color.b, color.a);

    glPushMatrix();
    glBegin( GL_LINES );

    x0 = -dx1 + offsetX;
    x1 =  dx1 + offsetX;
    y0 =  -dy1 + offsetY;
    y1 =  dy1 + offsetY;
    z0 = distMin + offsetZ;

    glVertex3d(x0, y0, z0);
    glVertex3d(x1, y0, z0);

    glVertex3d(x1, y0, z0);
    glVertex3d(x1, y1, z0);

    glVertex3d(x1, y1, z0);
    glVertex3d(x0, y1, z0);

    glVertex3d(x0, y1, z0);
    glVertex3d(x0, y0, z0);


    x2 = -dx2 + offsetX;
    x3 =  dx2 + offsetX;
    y2 =  -dy2 + offsetY;
    y3 =  dy2  + offsetY;
    z1 = distMax + offsetZ;

    glVertex3d(x2, y2, z1);
    glVertex3d(x3, y2, z1);

    glVertex3d(x3, y2, z1);
    glVertex3d(x3, y3, z1);

    glVertex3d(x3, y3, z1);
    glVertex3d(x2, y3, z1);

    glVertex3d(x2, y3, z1);
    glVertex3d(x2, y2, z1);

    glVertex3d(x0, y0, z0);
    glVertex3d(x2, y2, z1);

    glVertex3d(x1, y1, z0);
    glVertex3d(x3, y3, z1);

    glVertex3d(x0, y1, z0);
    glVertex3d(x2, y3, z1);

    glVertex3d(x1, y0, z0);
    glVertex3d(x3, y2, z1);


    glEnd();
    glPopMatrix();

}


void PlotSurface::drawArc(float cx, float cy, float cz, float r, float start_angle, float arc_angle, int num_segments){

   float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
   float tangetial_factor = tanf(theta);
   float radial_factor = cosf(theta);

   float x = r * cosf(start_angle);  //we start at the start angle
   float z = r * sinf(start_angle);

   glBegin(GL_LINE_STRIP);

   for(int i = 0; i < num_segments; i++)
   {
      glVertex3f(cx + x, cy, cz + z);

      float tx = -z;
      float tz = x;

      x += tx * tangetial_factor;
      z += tz * tangetial_factor;

      x *= radial_factor;
      z *= radial_factor;
   }

   glEnd();


}

void PlotSurface::drawText(double x, double y, double z, QString &str){

    EpcColor color = set.cloud.getGridColor();
    QFont font("Arial");
    font.setPointSize(24);
    font.setWeight( QFont::Normal );
    font.setUnderline(false);
    glColor4d(color.r, color.g, color.b, 1.0);
    renderText(x, y, z, str, font);
}



double PlotSurface::interpolate( double x, double x0, double y0, double x1, double y1){

    if(fabs(x1 - x0) < std::numeric_limits<double>::epsilon())  return y0;
    else return ((x-x0)*(y1-y0)/(x1-x0) + y0);
}



void PlotSurface::createColorMapPixel(int numSteps, int indx, unsigned char &red, unsigned char &green, unsigned char &blue){

    double k = 1;
    double B0 = -0.125 * k - 0.25;
    double B1 = B0 + 0.25 * k;
    double B2 = B1 + 0.25 * k;
    double B3 = B2 + 0.25 * k;

    double G0 = B1;
    double G1 = G0 + 0.25 * k;
    double G2 = G1 + 0.25 * k;
    double G3 = G2 + 0.25 * k + 0.125;

    double R0 = B2;
    double R1 = R0 + 0.25 * k;
    double R2 = R1 + 0.25 * k;
    double R3 = R2 + 0.25 * k + 0.25;

    double i = static_cast<double>(indx) / numSteps - 0.25 * k;

    if( i>= R0 && i < R1 ){
        red = static_cast<unsigned char>(interpolate(i, R0, 0, R1, 255));
    } else if((i >= R1) && (i < R2)){
        red = 255;
    } else if((i >= R2) && (i < R3)) {
        red = static_cast<unsigned char>(interpolate(i, R2, 255, R3, 0));
    } else {
        red = 0;
    }

    if( i>= G0 && i < G1 ){
        green = static_cast<unsigned char>(interpolate(i, G0, 0, G1, 255));
    } else if((i>=G1)&&(i<G2)){
        green = 255;
    } else if((i >= G2)&&(i < G3)){
        green = static_cast<unsigned char>(interpolate(i, G2, 255, G3, 0));
    } else {
        green = 0;
    }


    if( i>= B0 && i < B1 ){
        blue = static_cast<unsigned char>(interpolate(i, B0, 0, B1, 255));
    } else if((i >= B1)&&(i < B2)){
        blue = 255;
    } else if((i >= B2)&&(i < B3)) {
        blue = static_cast<unsigned char>(interpolate(i, B2, 255, B3, 0));
    } else{
        blue = 0;
    }

}


void PlotSurface::setColor(){

    if(set.cloud.isGrayPointCloud()){
        cvGray.clear();

        for(uint y= 0; y<height; y++)
            for(uint x= 0; x<width; x++){
                double val = y;
                cvGray.emplace_back(RGBA(val/255.0, val/255.0, val/255.0));
            }

        usrColor = new UserColor(this);
        usrColor->setImageWidth(width);
        usrColor->setImageHeight(height);
        usrColor->setColorVector(cvGray);
        setDataColor(usrColor);
    } else {
        int numSteps = NUM_COLORS;
        unsigned char red, green, blue;
        cvColor.clear();

        for(int i=0;  i< numSteps; i++){
            createColorMapPixel(numSteps, i, red, green, blue);
            cvColor.emplace_back(RGBA(blue/255.0, green/255.0, red/255.0));
        }

        stdColor = new StandardColor(this);
        stdColor->setColorVector(cvColor);
        setDataColor(stdColor);
    }

}

void PlotSurface::updateColor(int **data){
    uint x, y;
    double val;

    if(set.cloud.isGrayPointCloud()){
        cvGray.clear();
        usrColor->incrementColorIdx(true);  // reset userColor field increment
        double logBase = log(MAX_AMPLITUDE)/ 63;

        for( y=0; y<height; ++y)
            for( x=0; x<width; ++x){
                val = (log(data[x][y]) / logBase) / 64;
                cvGray.emplace_back(RGBA(val, val, val));
            }

        usrColor->setColorVector(cvGray);
    }
}


void PlotSurface::loadData(int **distance, int **amplitude, bool cartesian){

    uint l, x, y;
    uint val, d1, d2, d3;
    uint dist[328 * 252];
    tripleField.clear();
    cellField.clear();
    Cell cell(3);

    uint minDist =  set.getRangeMin();
    uint maxDist =  set.getRangeMax();

    for(l=0, y=0; y < height; y++){
        for(x=0; x < width; x++, l++ ){
            if(cartesian){
                dist[l] = static_cast<uint>(distance[x][y]);
                tripleField.emplace_back(tripData[x][y]);
            }else{
                val = static_cast<uint>(distance[x][y]);
                dist[l] = val;                
                if(!set.cloud.isUndistortion()) tripleField.emplace_back(Triple(x, y, val));
                else tripleField.emplace_back(Triple(epcTransform.getUndistortMapX(y, x), epcTransform.getUndistortMapY(y, x), val));
            }
        }
    }

    uint w1 = width  - 1;
    uint h1 = height - 1;
    int valFilter = set.cloud.getPCLFilterThreshold(true); //return phase

    for(l=0, y=0; y< height; y++){
        for(x=0; x< width; x++, l++){

            if(y<h1){
                if(x<w1){
                    d1 = dist[l];
                    d2 = dist[l+1];
                    d3 = dist[l+ width];
                    if( d1>minDist && d1<maxDist && d2>minDist && d2<maxDist && d3>minDist && d3<maxDist && pcFilter(d1, d2, d3, valFilter)){
                        cell[0] = l;
                        cell[1] = l + 1;
                        cell[2] = l + width;
                        cellField.emplace_back(cell);
                    }
                }

                if(x>0){
                    d1 = dist[l];
                    d2 = dist[l+width];
                    d3 = dist[l+ width-1];
                    if( d1>minDist && d1<maxDist && d2>minDist && d2<maxDist && d3>minDist && d3<maxDist && pcFilter(d1, d2, d3, valFilter)){
                        cell[0] = l;
                        cell[1] = l + width;
                        cell[2] = l + w1;
                        cellField.emplace_back(cell);
                    }
                }
            }
        }

    }

    if(set.cloud.isGrayPointCloud()){
        usrColor->setCellFieldUserColor(cellField);
         updateColor(amplitude);
    }

    loadFromData(tripleField, cellField);
}


void PlotSurface::transformation(double angleGrad, int **data, uint width_, uint height_){

    double x0, y0, x1, y1;    
    epcTransform.getRect(x0, y0, x1, y1, set.cloud.isUndistortion());
    double width_offset  = (x1 - x0) / 2.0 + x0;
    double height_offset = (y1 - y0) / 2.0 + y0;
    double angle = angleGrad * PI / 180;
    double sin_angle = sin(angle);
    double cos_angle = cos(angle);

    for(uint y=0; y < height_; y++)
        for(uint x=0; x < width_; x++ ){
            uint value = static_cast<uint>(data[x][y]);

            if(value < set.getRangeMin() || value > set.getRangeMax())
                value = 0;

            epcTransform.cartesianTransform3D(sin_angle, cos_angle, x, y, value, tripData[x][y].x, tripData[x][y].y, tripData[x][y].z, width_offset, height_offset, set.cloud.isUndistortion());
        }

    if(set.cloud.isPoints())
       loadFromData(tripData, width_, height_);

}


bool PlotSurface::pcFilter(uint d1, uint d2, uint d3, int threshold){

    int dist1 = static_cast<int>(d1);
    int dist2 = static_cast<int>(d2);
    int dist3 = static_cast<int>(d3);

    if(!set.cloud.isPCLFilter())
        return true;
    else if(abs(dist1-dist2)>threshold || abs(dist1-dist3)>threshold || abs(dist2-dist3)>threshold)
        return false;

    return true;
}

void PlotSurface::loadDefault(double angleX, double angleY, double angleZ, double zoom) {
    setRotation(angleX, angleY, angleZ);
    setOrtho(false);
    setScale(1.0, 1.0, 1.0);
    setZoom(zoom);
}


void PlotSurface::setLabelsProperties()
{
    EpcColor clr = set.cloud.getLabelColor();
    QFont font = set.cloud.getLabelFont();
    label.setColor(clr.r, clr.g, clr.b);
    label.setFont(font.family(), font.pixelSize(), font.weight());
}

void PlotSurface::displayText(int x, int y, uint z, QString &text)
{    
    Qwt3D::Triple pos(x,y,z);
    label.setPosition(pos);
    label.setString(text);
    label.draw();
}


void PlotSurface::displayLabels(bool state){

    if(state){
        uint z=0;
        int offsetX = width/2;
        int offsetY = set.cloud.getGridOffsetY();

        uint numSteps = set.cloud.getNumberCells();
        uint stepZ = set.cloud.getCellWidth();
        uint minDist = set.getRangeMin();
        uint maxDist = set.getRangeMax();
        QString str;

        for(uint i=0; i< numSteps && z < maxDist; i++){
            z = i * stepZ;
            if(z >= minDist){
                double zm = z/1000.0;
                str.sprintf("%2.2fm", zm);
                displayText(offsetX, offsetY, z, str);
            }
        }

    } //end if state

}


void PlotSurface::updateShowColorLegend(){

    showColorLegend(set.cloud.isShowLegend());

}


