#include <iostream>
using std::cout;
using std::endl;
#define pi 3.1415

class Circle
{
public:
    Circle()
    :_r(0)
    {
        cout<<"Circle()"<<endl;
    }
    Circle(double r)
    :_r(r)
    {
        cout<<"Circle(double r)"<<endl;
    }
    double getArea()
    {
        return pi*_r*_r;
    }
    double getPerimeter()
    {
        return 2*pi*_r;
    }
    void show()
    {
        cout<<"r="<<_r<<endl
            <<"getPerimeter="<<getPerimeter()<<endl
            <<"area="<<getArea()<<endl;
    }
private:
    double _r;
};


class Cylinder
:public Circle
{
public:
    Cylinder(double r,double h)
    :Circle(r)
    ,_h(h)
    {
        cout<<"Cylinder(double r,double h)"<<endl;
    }
    double getVolume()
    {
        return getArea()*_h;
    }
    void showVolume()
    {
        cout<<"getVolume="<<getVolume()<<endl;
    }
private:
    double _h;
};
int main(void)
{
    Cylinder v(3,1);
    v.show();
    v.showVolume();
    return 0;
}