#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
Base(long base)
:_base(base)
{}


virtual
void print() const
{
    cout<<"void print() const"<<endl;
    cout<<">>_base="<<_base<<endl;
}


private:
    long _base;
};

class Derived
:public Base 
{
public:
    Derived(long base,long derived)
    : Base(base)
    ,_derived(derived)
    {}

void print() const
{
    cout<<"void print() const"<<endl;
    cout<<">>_derived="<<_derived<<endl;
}

virtual
void print(int x) const
{
    cout<<"void print(int x) const"<<endl;
    cout<<"x="<<x<<endl;
}
private:
    long _derived;
};

class Derived2
:public Base
{
public:
    Derived2(long base,long derived)
    :Base(base)
    , _derived2(derived)
    {}

    void print() const
    {
        cout<<"void print() const"<<endl;
        cout<<">>_derived2="<<_derived2<<endl;
    }
private:
 long _derived2;

};
void print(Base * base)
{
    base->print();
}
int main(void)
{
    cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
    cout<<"sizeof(Derived)="<<sizeof(Derived)<<endl;
    cout<<"sizeof(Derived2)="<<sizeof(Derived2)<<endl;

    Base base(1);
    Derived derived(11,12);
    Derived2 derived2(21,22);

    print(&base);
    print(&derived);
    print(&derived2);

    cout<<"对象名调用时:"<<endl;
    base.print();
    derived.print();
    derived.Base::print();
    derived2.print();

}