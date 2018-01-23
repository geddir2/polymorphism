#include <vector>
#include "utilities.h"
using namespace std;
class Polygon {
public:
    Polygon(const string nme,const vector< Point > pts) : name(nme), vertices(pts){}
    string getName() const { return name;}
    virtual ~Polygon() {}
    bool HasAllEqualSides();
    bool HasAllEqualAngles();
    bool HasARightAngle();
    bool HasAnObtuseAngle();
    bool HasOnlyTwoEqualSides();
    bool HasAnAcuteAngle();
    bool OppositeAngles();
    bool ParaLSides();
    bool baseAndTopSame();
    bool IsConvex();
    bool MiddleAngle();
    bool IsConcave();
    bool bottomSame();
    bool sameDistanceArrow();
protected:
    string name;
    vector < Point > vertices;
};
class Triangle :  virtual public Polygon{
public:
    Triangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts){if (pts.size() != 3){throw 3;}}
};
class IsoscelesTriangle : virtual public Triangle{
public:
    IsoscelesTriangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts),Triangle(nme,pts){if (pts.size() != 3 || !(this->HasOnlyTwoEqualSides())){throw 3;}}
};
class EquilateralTriangle : virtual public IsoscelesTriangle{
public:
    EquilateralTriangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts),Triangle(nme,pts),IsoscelesTriangle(nme,pts){if (pts.size() != 3 || !(this->HasAllEqualSides()) ||!(this->HasAllEqualAngles())){throw 3;}}
};
class RightTriangle : virtual public Triangle{
public:
    RightTriangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts),Triangle(nme,pts){if (pts.size() != 3 || !(this->HasARightAngle())){throw 3;}}
};
class ObtuseTriangle : virtual public Triangle{
public:
    ObtuseTriangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts),Triangle(nme,pts){if (pts.size() != 3 || !(this->HasAnObtuseAngle())){throw 3;}}
};
class IsoscelesObtuseTriangle :  virtual public IsoscelesTriangle, virtual public Triangle, virtual public ObtuseTriangle{
public:
    IsoscelesObtuseTriangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts),Triangle(nme,pts),IsoscelesTriangle(nme,pts),ObtuseTriangle(nme,pts){if (pts.size() != 3 || !(this->HasAnObtuseAngle()) ||!(this->HasOnlyTwoEqualSides())){throw 3;}}
};
class IsoscelesRightTriangle : virtual public RightTriangle, virtual public Triangle, virtual public IsoscelesTriangle{
public:
    IsoscelesRightTriangle(const string nme,const vector< Point > pts)
    : Polygon(nme,pts),Triangle(nme,pts),RightTriangle(nme,pts),IsoscelesTriangle(nme,pts){if (pts.size() != 3 || !(this->HasARightAngle()) || !(this->HasOnlyTwoEqualSides())){throw 3;}}
};
class Quadrilateral : public Polygon{
public:
    Quadrilateral(const string nme,const vector< Point > pts)
    : Polygon(nme,pts){ if (pts.size() != 4){ throw 4;}}
};
class Trapezoid :  virtual public  Quadrilateral{
public:
    Trapezoid(const string nme,const vector< Point > pts)
    :Quadrilateral(nme,pts){if (pts.size() != 4 || !(this->ParaLSides())){throw 4;}}
};
class IsoscelesTrapezoid :  virtual public  Trapezoid {
public:
    IsoscelesTrapezoid(const string nme,const vector< Point > pts)
    :Quadrilateral(nme,pts),Trapezoid(nme,pts){if (pts.size() != 4 || this->IsConcave()||!(this->bottomSame())||!(this->ParaLSides())){throw 4;}}
};
class Parallelogram : virtual public Trapezoid{
public:
    Parallelogram(const string nme,const vector< Point > pts)
    :Quadrilateral(nme,pts),Trapezoid(nme,pts){ if(pts.size() != 4 ||!(this->baseAndTopSame()) ||  !(this->OppositeAngles())){throw 4;}}
};
class Rectangle :  virtual public Parallelogram,  public IsoscelesTrapezoid{
public:
    Rectangle(const string nme,const vector< Point > pts)
    : Quadrilateral(nme,pts), Trapezoid(nme,pts),Parallelogram(nme,pts), IsoscelesTrapezoid(nme,pts){if (pts.size() != 4 || !this->HasARightAngle() ||this->HasAnObtuseAngle()){throw 4;}}
};
class Kite :  virtual public Quadrilateral{
public:
    Kite(const string nme,const vector< Point > pts)
    : Quadrilateral(nme,pts){if (pts.size() != 4 ||!(this->MiddleAngle())){throw 4;}}
};
class Rhombus:virtual  public Parallelogram,  virtual public Kite{
public:
    Rhombus(const string nme,const vector< Point > pts)
    : Quadrilateral(nme,pts),Trapezoid(nme,pts),Parallelogram(nme,pts), Kite(nme,pts){if (pts.size() != 4 || !(this->HasAllEqualSides()) ||!(this->OppositeAngles() )){throw 4;}}
};
class Square : public Rectangle,  public Rhombus{
public:
    Square(const string nme,const vector< Point > pts)
    : Quadrilateral(nme,pts), Trapezoid(nme,pts), Parallelogram(nme,pts),Kite(nme,pts),Rectangle(nme,pts),Rhombus(nme,pts){ if(pts.size() != 4 || !(this->HasAllEqualAngles())||!(this->HasAllEqualSides()) ){throw 4;}}
};
class Arrow :  public Quadrilateral{
public:
    Arrow(const string nme,const vector< Point > pts)
    : Quadrilateral(nme,pts){if(pts.size() != 4 || !(this->IsConcave()) ||!(sameDistanceArrow()) ){throw 4;}}
};


