#ifndef qwt3d_SurfacePlot_h__2004_03_05_11_36_begin_guarded_code
#define qwt3d_SurfacePlot_h__2004_03_05_11_36_begin_guarded_code

#include "qwt3d_plot.h"

namespace Qwt3D
{

//A class representing  Surfaces
//  A SurfacePlot ...

class SurfacePlot : public Plot3D
{
    Q_OBJECT

public:
    SurfacePlot( QWidget *parent = nullptr, const QGLWidget *shareWidget = nullptr);
    ~SurfacePlot();
    void updateNormals(); // Recalculates surface normals;
    int	resolution() const {return resolution_p;} // Returns data resolution (1 means all data)
    std::pair<int,int> facets() const; // Returns the number of mesh cells for the ORIGINAL data
    bool loadFromData(Qwt3D::Triple** data, unsigned int columns, unsigned int rows, bool uperiodic = false, bool vperiodic = false);
    bool loadFromData(double** data, unsigned int columns, unsigned int rows, double minx, double maxx, double miny, double maxy);
    bool loadFromData(Qwt3D::TripleField const& data, Qwt3D::CellField const& poly);

    Qwt3D::FLOORSTYLE floorStyle() const { return floorstyle_;} // Return floor style
    void setFloorStyle( Qwt3D::FLOORSTYLE val ) {floorstyle_ = val;} // Sets floor style
    void showNormals(bool); // Draw normals to every vertex
    bool normals() const { return datanormals_p;} // Returns \c true, if normal drawing is on

    void setNormalLength(double val); // Sets length of normals in percent per hull diagonale
    double normalLength() const { return normalLength_p; } // Returns relative length of normals
    void setNormalQuality(int val); // Increases plotting quality of normal arrows
    int normalQuality() const { return normalQuality_p; } // Returns plotting quality of normal arrows
    void setMinX(double val);
    void setMaxX(double val);
    void setMinY(double val);
    void setMaxY(double val);
    void setMinZ(double val); // Sets minimal z value.
    void setMaxZ(double val);
    void setPointSize(double pointsize);

signals:
    void resolutionChanged(int);

public slots:
    void setResolution( int );

protected:
    bool datanormals_p;
    double normalLength_p;
    int normalQuality_p;
    double pointsize;

    virtual	void calculateHull();
    virtual void createData();
    virtual void createEnrichment(Qwt3D::Enrichment& p);
    virtual void createFloorData();
    void createNormals();
    void createPoints();

    int resolution_p;

    void readIn(Qwt3D::GridData& gdata, Triple** data, unsigned int columns, unsigned int rows);
    void readIn(Qwt3D::GridData& gdata, double** data, unsigned int columns, unsigned int rows, double minx, double maxx, double miny, double maxy);
    void calcNormals(GridData& gdata);
    void sewPeriodic(GridData& gdata);
    //void calcLowResolution();

private:
    double minX, maxX, minY, maxY, minZ, maxZ;
    void Data2Floor();
    void Isolines2Floor();

    Qwt3D::FLOORSTYLE floorstyle_;

    // grid plot
    Qwt3D::GridData* actualDataG_;
    virtual void createDataG();
    virtual void createFloorDataG();
    void createNormalsG();
    void Data2FloorG();
    void Isolines2FloorG();
    void setColorFromVertexG(int ix, int iy, bool skip = false);


    // mesh plot
    Qwt3D::CellData* actualDataC_;
    virtual void createDataC();
    virtual void createFloorDataC();
    void createNormalsC();
    void Data2FloorC();
    void Isolines2FloorC();
    void setColorFromVertexC(int node, bool skip = false);
};

} // ns


#endif
