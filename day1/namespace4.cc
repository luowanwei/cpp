#include<iostream>
using std::cout;
using std::endl;
int number=1;
namespace wd
{
    int number=2;
    void display(int number)
    {
        //就近原则，直接覆盖其他空间的同名实体
        cout<<"形参number="<<number<<endl;
        cout<<"wd::number="<<wd::number<<endl;
        cout<<"全局变量number="<<::number<<endl;//匿名的命名空间
    }
}
int main(void)
{
    wd::display(10);
    return 0;
}