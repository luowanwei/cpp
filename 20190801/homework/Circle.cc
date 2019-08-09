#include <iostream>
#define pi 3.1415
using std::cout;
using std::endl;

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
int main(void)
{
    Circle c(8);
    c.show();
    return 0;
}