#include<iostream>
//using namespace std;//using 编译指令 std是标准空间的意思
namespace wd
{
    int number=10;
    void display()
    {
        std::cout<<"display()"<<std::endl;
    }
}//end of namespace wd
int main(void)
{
    std::cout<<"number="<<wd::number<<std::endl;
    wd::display();//::是作用域限定符
    return 0;
}