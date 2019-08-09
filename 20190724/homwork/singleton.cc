#include <iostream> 
using std::cout;
using std::endl;
class Singleton
{
    public:
        static Singleton * getInstance()
        {
            if(nullptr==_pInstance)
            {
                _pInstance=new Singleton();
            }
            return _pInstance;
        }
        static void destroy()
        {
            if(_pInstance)
            delete _pInstance;
        }
    private:
        Singleton()//构造函数私有化
        {
            cout<<"Singleton()"<<endl;
        }
        ~Singleton()
        {
            cout << "~Singleton()" << endl;
        }
    private:
        static Singleton * _pInstance;
};
Singleton * Singleton::_pInstance=nullptr;
int main(void)
{
    Singleton * a=Singleton::getInstance();
    Singleton * b=Singleton::getInstance();
    cout<<"a="<<a<<endl
        <<"b="<<b<<endl;
    Singleton::destroy();
    return 0;
}