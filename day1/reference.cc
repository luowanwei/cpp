#include<iostream>
using std::cout;
using std::endl;
void test0()
{
    int number=10;
    int &ref=number;//&和变量在一起，为引用符号
    //引用一经初始化，不会改变指向
    //引用是一个受限制的指针
    //int &ref2;//error 引用必须进行初始化
    cout<<"&number="<<&number<<endl;
    cout<<"&ref="<<&ref<<endl;
    cout<<"number="<<number<<endl;
    cout<<"ref="<<ref<<endl;


    ref=20;


    cout<<"number="<<number<<endl;
    cout<<"ref="<<ref<<endl;
}
int main(void)
{
    test0();
    return 0;
}