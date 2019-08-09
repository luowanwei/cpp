#include<iostream>
using std::cout;
using std::endl;
class   Singleton
{
public:
    static Singleton * getInstance()
    {
        if(nullptr==_pInstance)
        {
            _pInstance=new Singleton();
        }
        cout<<"getInstance()"<<endl;
        return _pInstance;
        
    }
    static void destory()
    {
        if(_pInstance)
            delete _pInstance;
        cout<<"destory()"<<endl;
    }
private:
    Singleton()
    {
        cout<<"Singleton()"<<endl;
    }
    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
    }
private:
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance=nullptr;
int main(void)
{
    Singleton *p1=Singleton::getInstance();
    Singleton * p2=Singleton::getInstance();
    Singleton * p3=Singleton::getInstance();
    cout<<"p1="<<p1<<endl;
    cout<<"p2="<<p2<<endl;
    cout<<"p3="<<p3<<endl;
    Singleton::destory();
    return 0;
}