#include<iostream>
//using namespace std;//using 编译指令 std是标准空间的意思
//一次把std中的所有实体全部引入
using std::cout;
using std::endl;
namespace wd
{
    int show();
}
namespace tls
{
    int print()
    {
        cout<<"tls::print()"<<endl;
        wd::show();
    }
}//end of namespace tls
namespace wd
{
    int display()
    {
        cout<<"wd::display()"<<endl;
        tls::print();
    }
    int show()
    {
        cout<<"wd::show()"<<endl;
    }
}//end of namespace wd

int main(void)
{
    wd::display();//::是作用域限定符
    return 0;
}