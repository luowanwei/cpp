#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
template<class T>
class Singleton
{
public:
    template<typename... Args>
    static T getinstance(Args... args)
    {
        if(!singletion)
        {
            singletion=new T(args...);
        }
        return singletion;
    }
    static void destroy()
    {
        if(singletion)
        {
            delete singletion;
        }
    }
private:
    static  T* singletion;

};
template<class T>
T * Singleton<T>::singletion=NULL;
class Point
{
public:
    Point()=default;
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout<<"Point(int x,int y)"<<endl;
    }
private:
    int _ix=0;
    int _iy=0;
};
class Computer
{
public:
    Computer(const char* model,double price)
    :_model(model)
    ,_price(price)
    {
        cout<<"Computer(const char* model,double price)"<<endl;
    }
    void print()
    {
        cout<<"model"<<_model<<endl;
        cout<<"price"<<_price<<endl;
    }
private:
    string _model;
    double _price;
};
void test()
{
    Computer *p1 = Singleton<Computer>::getinstance("Xiaomi", 6666);
    Computer *p2 = Singleton<Computer>::getinstance("Xiaomi", 6666);
    p1->print();
    p2->print();
    Point *p3 = Singleton<Point>::getinstance(1, 2);
    Point *p4 = Singleton<Point>::getinstance(1, 2);
    p3->print();
    p4->print();
    Singleton<Point>::destroy(); 
}
int main(void)
{
    test();
    return 0;
}