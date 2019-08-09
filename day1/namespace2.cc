#include<iostream>
//using namespace std;//using 编译指令 std是标准空间的意思
//一次把std中的所有实体全部引入
using std::cout;
using std::endl;
namespace wd
{
    int number=10;
    void display()
    {
        cout<<"display()"<<endl;
    }
}//end of namespace wd
int main(void)
{
    cout<<"number="<<wd::number<<endl;
    wd::display();//::是作用域限定符
    return 0;
}