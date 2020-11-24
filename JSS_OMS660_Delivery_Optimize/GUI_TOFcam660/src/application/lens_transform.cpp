#include "lens_transform.h"
#include <math.h>
#include <QDebug>



LensTransform::LensTransform()
{

    initialisation(0.02, 320, 240, 0, 0, true); // sensor pixel size 0.02 mm, sensor 320x240, center offset x, y

}

void LensTransform::initLensDistortionTable(bool wideField)
{
    distortionTableSize = 101;

    if(wideField)
    {
        angle[0]  = 0.0;
        angle[1]  = 0.742;
        angle[2]  = 1.483;
        angle[3]  = 2.225;
        angle[4]  = 2.967;
        angle[5]  = 3.708;
        angle[6]  = 4.45;
        angle[7]  = 5.192;
        angle[8]  = 5.933;
        angle[9]  = 6.675;
        angle[10] = 7.417;
        angle[11] = 8.158;
        angle[12] = 8.9;
        angle[13] = 9.642;
        angle[14] = 10.384;
        angle[15] = 11.125;
        angle[16] = 11.867;
        angle[17] = 12.609;
        angle[18] = 13.35;
        angle[19] = 14.092;
        angle[20] = 14.834;
        angle[21] = 15.575;
        angle[22] = 16.317;
        angle[23] = 17.059;
        angle[24] = 17.8;
        angle[25] = 18.542;
        angle[26] = 19.284;
        angle[27] = 20.025;
        angle[28] = 20.767;
        angle[29] = 21.509;
        angle[30] = 22.25;
        angle[31] = 22.992;
        angle[32] = 23.734;
        angle[33] = 24.475;
        angle[34] = 25.217;
        angle[35] = 25.959;
        angle[36] = 26.701;
        angle[37] = 27.442;
        angle[38] = 28.184;
        angle[39] = 28.926;
        angle[40] = 29.667;
        angle[41] = 30.409;
        angle[42] = 31.151;
        angle[43] = 31.892;
        angle[44] = 32.634;
        angle[45] = 33.376;
        angle[46] = 34.117;
        angle[47] = 34.859;
        angle[48] = 35.601;
        angle[49] = 36.342;
        angle[50] = 37.084;
        angle[51] = 37.826;
        angle[52] = 38.567;
        angle[53] = 39.309;
        angle[54] = 40.051;
        angle[55] = 40.792;
        angle[56] = 41.534;
        angle[57] = 42.276;
        angle[58] = 43.018;
        angle[59] = 43.759;
        angle[60] = 44.501;
        angle[61] = 45.243;
        angle[62] = 45.984;
        angle[63] = 46.726;
        angle[64] = 47.468;
        angle[65] = 48.209;
        angle[66] = 48.951;
        angle[67] = 49.693;
        angle[68] = 50.434;
        angle[69] = 51.176;
        angle[70] = 51.918;
        angle[71] = 52.659;
        angle[72] = 53.401;
        angle[73] = 54.143;
        angle[74] = 54.884;
        angle[75] = 55.626;
        angle[76] = 56.368;
        angle[77] = 57.109;
        angle[78] = 57.851;
        angle[79] = 58.593;
        angle[80] = 59.335;
        angle[81] = 60.076;
        angle[82] = 60.818;
        angle[83] = 61.56;
        angle[84] = 62.301;
        angle[85] = 63.043;
        angle[86] = 63.785;
        angle[87] = 64.526;
        angle[88] = 65.268;
        angle[89] = 66.01;
        angle[90] = 66.751;
        angle[91] = 67.493;
        angle[92] = 68.235;
        angle[93] = 68.976;
        angle[94] = 69.718;
        angle[95] = 70.46;
        angle[96] = 71.201;
        angle[97] = 71.943;
        angle[98] = 72.685;
        angle[99] = 73.426;
        angle[100] = 74.168;

        //size mm
        rp[0] = 0.0;
        rp[1] = 0.048;
        rp[2] = 0.095;
        rp[3] = 0.143;
        rp[4] = 0.19;
        rp[5] = 0.238;
        rp[6] = 0.286;
        rp[7] = 0.333;
        rp[8] = 0.381;
        rp[9] = 0.428;
        rp[10] = 0.476;
        rp[11] = 0.523;
        rp[12] = 0.571;
        rp[13] = 0.618;
        rp[14] = 0.665;
        rp[15] = 0.713;
        rp[16] = 0.76;
        rp[17] = 0.807;
        rp[18] = 0.854;
        rp[19] = 0.901;
        rp[20] = 0.948;
        rp[21] = 0.995;
        rp[22] = 1.042;
        rp[23] = 1.089;
        rp[24] = 1.135;
        rp[25] = 1.182;
        rp[26] = 1.228;
        rp[27] = 1.275;
        rp[28] = 1.321;
        rp[29] = 1.367;
        rp[30] = 1.413;
        rp[31] = 1.459;
        rp[32] = 1.505;
        rp[33] = 1.551;
        rp[34] = 1.596;
        rp[35] = 1.641;
        rp[36] = 1.687;
        rp[37] = 1.732;
        rp[38] = 1.777;
        rp[39] = 1.822;
        rp[40] = 1.866;
        rp[41] = 1.911;
        rp[42] = 1.955;
        rp[43] = 1.999;
        rp[44] = 2.043;
        rp[45] = 2.087;
        rp[46] = 2.13;
        rp[47] = 2.173;
        rp[48] = 2.216;
        rp[49] = 2.259;
        rp[50] = 2.302;
        rp[51] = 2.344;
        rp[52] = 2.386;
        rp[53] = 2.428;
        rp[54] = 2.47;
        rp[55] = 2.511;
        rp[56] = 2.552;
        rp[57] = 2.593;
        rp[58] = 2.634;
        rp[59] = 2.674;
        rp[60] = 2.714;
        rp[61] = 2.754;
        rp[62] = 2.793;
        rp[63] = 2.832;
        rp[64] = 2.871;
        rp[65] = 2.909;
        rp[66] = 2.948;
        rp[67] = 2.985;
        rp[68] = 3.023;
        rp[69] = 3.06;
        rp[70] = 3.096;
        rp[71] = 3.132;
        rp[72] = 3.168;
        rp[73] = 3.204;
        rp[74] = 3.239;
        rp[75] = 3.273;
        rp[76] = 3.308;
        rp[77] = 3.341;
        rp[78] = 3.375;
        rp[79] = 3.408;
        rp[80] = 3.44;
        rp[81] = 3.472;
        rp[82] = 3.504;
        rp[83] = 3.535;
        rp[84] = 3.565;
        rp[85] = 3.595;
        rp[86] = 3.625;
        rp[87] = 3.654;
        rp[88] = 3.682;
        rp[89] = 3.71;
        rp[90] = 3.738;
        rp[91] = 3.765;
        rp[92] = 3.791;
        rp[93] = 3.817;
        rp[94] = 3.842;
        rp[95] = 3.866;
        rp[96] = 3.89;
        rp[97] = 3.914;
        rp[98] = 3.936;
        rp[99] = 3.959;
        rp[100] = 3.98;

    }else{


        //Narow field

        angle[0] = 0.00;
        angle[1] = 0.19;
        angle[2] = 0.38;
        angle[3] = 0.57;
        angle[4] = 0.76;
        angle[5] = 0.95;
        angle[6] = 1.14;
        angle[7] = 1.33;
        angle[8] = 1.52;
        angle[9] = 1.71;
        angle[10] = 1.90;
        angle[11] = 2.09;
        angle[12] = 2.28;
        angle[13] = 2.47;
        angle[14] = 2.66;
        angle[15] = 2.85;
        angle[16] = 3.04;
        angle[17] = 3.23;
        angle[18] = 3.42;
        angle[19] = 3.61;
        angle[20] = 3.80;
        angle[21] = 3.99;
        angle[22] = 4.18;
        angle[23] = 4.37;
        angle[24] = 4.56;
        angle[25] = 4.75;
        angle[26] = 4.94;
        angle[27] = 5.13;
        angle[28] = 5.33;
        angle[29] = 5.52;
        angle[30] = 5.71;
        angle[31] = 5.90;
        angle[32] = 6.09;
        angle[33] = 6.28;
        angle[34] = 6.47;
        angle[35] = 6.66;
        angle[36] = 6.85;
        angle[37] = 7.04;
        angle[38] = 7.23;
        angle[39] = 7.42;
        angle[40] = 7.61;
        angle[41] = 7.80;
        angle[42] = 7.99;
        angle[43] = 8.18;
        angle[44] = 8.37;
        angle[45] = 8.56;
        angle[46] = 8.75;
        angle[47] = 8.94;
        angle[48] = 9.13;
        angle[49] = 9.32;
        angle[50] = 9.51;
        angle[51] = 9.70;
        angle[52] = 9.89;
        angle[53] = 10.08;
        angle[54] = 10.27;
        angle[55] = 10.46;
        angle[56] = 10.65;
        angle[57] = 10.84;
        angle[58] = 11.03;
        angle[59] = 11.22;
        angle[60] = 11.41;
        angle[61] = 11.60;
        angle[62] = 11.79;
        angle[63] = 11.98;
        angle[64] = 12.17;
        angle[65] = 12.36;
        angle[66] = 12.55;
        angle[67] = 12.74;
        angle[68] = 12.93;
        angle[69] = 13.12;
        angle[70] = 13.31;
        angle[71] = 13.50;
        angle[72] = 13.69;
        angle[73] = 13.88;
        angle[74] = 14.07;
        angle[75] = 14.26;
        angle[76] = 14.45;
        angle[77] = 14.64;
        angle[78] = 14.83;
        angle[79] = 15.02;
        angle[80] = 15.21;
        angle[81] = 15.40;
        angle[82] = 15.59;
        angle[83] = 15.79;
        angle[84] = 15.98;
        angle[85] = 16.17;
        angle[86] = 16.36;
        angle[87] = 16.55;
        angle[88] = 16.74;
        angle[89] = 16.93;
        angle[90] = 17.12;
        angle[91] = 17.31;
        angle[92] = 17.50;
        angle[93] = 17.69;
        angle[94] = 17.88;
        angle[95] = 18.07;
        angle[96] = 18.26;
        angle[97] = 18.45;
        angle[98] = 18.64;
        angle[99] = 18.83;
        angle[100] = 19.02;



        //Real
        rp[0] = 0.0;
        rp[1] = 0.04;
        rp[2] = 0.08;
        rp[3] = 0.11;
        rp[4] = 0.15;
        rp[5] = 0.19;
        rp[6] = 0.23;
        rp[7] = 0.26;
        rp[8] = 0.30;
        rp[9] = 0.34;
        rp[10] = 0.38;
        rp[11] = 0.41;
        rp[12] = 0.45;
        rp[13] = 0.49;
        rp[14] = 0.53;
        rp[15] = 0.57;
        rp[16] = 0.60;
        rp[17] = 0.64;
        rp[18] = 0.68;
        rp[19] = 0.72;
        rp[20] = 0.75;
        rp[21] = 0.79;
        rp[22] = 0.83;
        rp[23] = 0.87;
        rp[24] = 0.91;
        rp[25] = 0.94;
        rp[26] = 0.98;
        rp[27] = 1.02;
        rp[28] = 1.06;
        rp[29] = 1.10;
        rp[30] = 1.13;
        rp[31] = 1.17;
        rp[32] = 1.21;
        rp[33] = 1.25;
        rp[34] = 1.29;
        rp[35] = 1.33;
        rp[36] = 1.36;
        rp[37] = 1.40;
        rp[38] = 1.44;
        rp[39] = 1.48;
        rp[40] = 1.52;
        rp[41] = 1.56;
        rp[42] = 1.60;
        rp[43] = 1.63;
        rp[44] = 1.67;
        rp[45] = 1.71;
        rp[46] = 1.75;
        rp[47] = 1.79;
        rp[48] = 1.83;
        rp[49] = 1.87;
        rp[50] = 1.91;
        rp[51] = 1.95;
        rp[52] = 1.99;
        rp[53] = 2.02;
        rp[54] = 2.06;
        rp[55] = 2.10;
        rp[56] = 2.14;
        rp[57] = 2.18;
        rp[58] = 2.22;
        rp[59] = 2.26;
        rp[60] = 2.30;
        rp[61] = 2.34;
        rp[62] = 2.38;
        rp[63] = 2.42;
        rp[64] = 2.46;
        rp[65] = 2.50;
        rp[66] = 2.54;
        rp[67] = 2.58;
        rp[68] = 2.62;
        rp[69] = 2.66;
        rp[70] = 2.70;
        rp[71] = 2.74;
        rp[72] = 2.79;
        rp[73] = 2.83;
        rp[74] = 2.87;
        rp[75] = 2.91;
        rp[76] = 2.95;
        rp[77] = 2.99;
        rp[78] = 3.03;
        rp[79] = 3.08;
        rp[80] = 3.12;
        rp[81] = 3.16;
        rp[82] = 3.20;
        rp[83] = 3.24;
        rp[84] = 3.29;
        rp[85] = 3.33;
        rp[86] = 3.37;
        rp[87] = 3.42;
        rp[88] = 3.46;
        rp[89] = 3.50;
        rp[90] = 3.55;
        rp[91] = 3.59;
        rp[92] = 3.63;
        rp[93] = 3.68;
        rp[94] = 3.72;
        rp[95] = 3.77;
        rp[96] = 3.81;
        rp[97] = 3.85;
        rp[98] = 3.90;
        rp[99] = 3.94;
        rp[100] = 3.99;
    }

    //Ref Norow field
    /*  rp[0] = 0.00;
    rp[1] = 0.04;
    rp[2] = 0.08;
    rp[3] = 0.11;
    rp[4] = 0.15;
    rp[5] = 0.19;
    rp[6] = 0.23;
    rp[7] = 0.26;
    rp[8] = 0.30;
    rp[9] = 0.34;
    rp[10] = 0.38;
    rp[11] = 0.41;
    rp[12] = 0.45;
    rp[13] = 0.49;
    rp[14] = 0.53;
    rp[15] = 0.57;
    rp[16] = 0.60;
    rp[17] = 0.64;
    rp[18] = 0.68;
    rp[19] = 0.72;
    rp[20] = 0.75;
    rp[21] = 0.79;
    rp[22] = 0.83;
    rp[23] = 0.87;
    rp[24] = 0.91;
    rp[25] = 0.94;
    rp[26] = 0.98;
    rp[27] = 1.02;
    rp[28] = 1.06;
    rp[29] = 1.10;
    rp[30] = 1.13;
    rp[31] = 1.17;
    rp[32] = 1.21;
    rp[33] = 1.25;
    rp[34] = 1.29;
    rp[35] = 1.32;
    rp[36] = 1.36;
    rp[37] = 1.40;
    rp[38] = 1.44;
    rp[39] = 1.48;
    rp[40] = 1.52;
    rp[41] = 1.55;
    rp[42] = 1.59;
    rp[43] = 1.63;
    rp[44] = 1.67;
    rp[45] = 1.71;
    rp[46] = 1.75;
    rp[47] = 1.78;
    rp[48] = 1.82;
    rp[49] = 1.86;
    rp[50] = 1.90;
    rp[51] = 1.94;
    rp[52] = 1.98;
    rp[53] = 2.02;
    rp[54] = 2.06;
    rp[55] = 2.10;
    rp[56] = 2.13;
    rp[57] = 2.17;
    rp[58] = 2.21;
    rp[59] = 2.25;
    rp[60] = 2.29;
    rp[61] = 2.33;
    rp[62] = 2.37;
    rp[63] = 2.41;
    rp[64] = 2.45;
    rp[65] = 2.49;
    rp[66] = 2.53;
    rp[67] = 2.57;
    rp[68] = 2.61;
    rp[69] = 2.65;
    rp[70] = 2.69;
    rp[71] = 2.73;
    rp[72] = 2.76;
    rp[73] = 2.80;
    rp[74] = 2.84;
    rp[75] = 2.88;
    rp[76] = 2.93;
    rp[77] = 2.97;
    rp[78] = 3.01;
    rp[79] = 3.05;
    rp[80] = 3.09;
    rp[81] = 3.13;
    rp[82] = 3.17;
    rp[83] = 3.21;
    rp[84] = 3.25;
    rp[85] = 3.29;
    rp[86] = 3.33;
    rp[87] = 3.37;
    rp[88] = 3.41;
    rp[89] = 3.45;
    rp[90] = 3.49;
    rp[91] = 3.54;
    rp[92] = 3.58;
    rp[93] = 3.62;
    rp[94] = 3.66;
    rp[95] = 3.70;
    rp[96] = 3.74;
    rp[97] = 3.79;
    rp[98] = 3.83;
    rp[99] = 3.87;
    rp[100] = 3.91;*/

}


double LensTransform::interpolate(double x_in, double x0, double y0, double x1, double y1){

    if(fabs(x1 - x0) < std::numeric_limits<double>::epsilon())  return y0;
    else return ((x_in-x0)*(y1-y0)/(x1-x0) + y0);
}

double LensTransform::getAngle(double x, double y, double sensorPointSizeMM)
{
    double radius = sensorPointSizeMM * sqrt(x*x + y*y);
    double alfaGrad = 0;

    for(int i=1; i<distortionTableSize; i++)
    {
        if(radius >= rp[i-1] && radius <= rp[i]){

            alfaGrad = interpolate(radius, rp[i-1], angle[i-1], rp[i], angle[i]);
        }
    }

    return alfaGrad;
}


void LensTransform::runRoiTransform(int **data, unsigned int leftX, unsigned int leftY, unsigned int rightX, unsigned int rightY, double sin_angle, double cos_angle, int offsetX, int offsetY)
{
    uint x, y;
    double destY, destZ;

    for(y = leftY; y <= rightY; y++){
        for(x = leftX; x <= rightX; x++){
            destY = data[x][y] * yUA[x][y];
            destZ = data[x][y] * zUA[x][y];
            xOut[x][y] = data[x][y] * xUA[x][y] + offsetX;
            yOut[x][y] = destY - destZ * sin_angle + offsetY;
            zOut[x][y] = destZ * cos_angle;
        }
    }
}

void LensTransform::runTransform(int **data, int width, int height)
{    
    for(int y=0; y< height; y++){
        for(int x=0; x< width; x++){

            xOut[x][y] = data[x][y] * xUA[x][y];
            yOut[x][y] = data[x][y] * yUA[x][y];
            zOut[x][y] = data[x][y] * zUA[x][y];
        }
    }
}

void LensTransform::initialisation(double sensorPointSizeMM, int width, int height, int offsetX, int offsetY, bool wideField)
{
    int x, y, row, col;
    numCols = width;
    numRows = height;

    initLensDistortionTable(wideField);

    int r0 = 1 - numRows/2 + offsetY;
    int c0 = 1 - numCols/2 + offsetX;

    for(y=0, row = r0; y < numRows; row++, y++){
        for(x=0, col = c0; x < numCols; col++, x++){

            double c = col - 0.5;
            double r = row - 0.5;

            double angleGrad = getAngle(c, r, sensorPointSizeMM);
            double angleRad =  angleGrad * 3.14159265 / 180.0;

            double rp = sqrt(c * c + r * r);
            double rUA = sin(angleRad);

            xUA[x][y] = c * rUA / rp;
            yUA[x][y] = r * rUA / rp;
            zUA[x][y] = cos(angleRad);
        }
    }

}



























