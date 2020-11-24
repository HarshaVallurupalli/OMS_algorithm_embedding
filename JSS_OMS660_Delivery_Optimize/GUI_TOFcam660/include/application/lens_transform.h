#ifndef LENSTRANSFORM_H
#define LENSTRANSFORM_H


class LensTransform
{
public:
    LensTransform();
    ~LensTransform(){}        
    void initialisation(double sensorPointSizeMM, int width, int height, int offsetX, int offsetY, bool wideField);
    void runTransform(int **data, int width, int height);
    void runRoiTransform(int **data, unsigned int leftX,  unsigned int leftY,  unsigned int rightX,  unsigned int rightY, double sin_angle, double cos_angle, int offsetX, int offsetY);

    //output
    double xOut[320][240];
    double yOut[320][240];
    double zOut[320][240];

private:
    int distortionTableSize;
    int numCols;
    int numRows;
    double angle[101];
    double rp[101];

    double xUA[320][240];
    double yUA[320][240];
    double zUA[320][240];


    void initLensDistortionTable(bool wideField);
    double interpolate(double x_in, double x0, double y0, double x1, double y1);
    double getAngle(double x, double y, double sensorPointSizeMM);

};

#endif // LENSTRANSFORM_H
