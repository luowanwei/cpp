#include<iostream>
using std::cout;
using std::endl;
#define NUMBER 100
void test0()
{//内置类型：char/short/int/long/float double void 
//指针类型
    const int number=1;//常量
   // number=10;//error
}
void test1()
{
    int number=10;
    int number2=20;
    const int * pa=&number;//常量指针
    *pa=20;//不能通过pa执政修改所指变量的值
    pa=&number2;//可以改变pa的指向

    int const * pc=&number;
    *pc=20;
    pc=&number2;
    
    int * const pb=&number;//指针常量
    *pb=20//可以通过pb指针修改所指变量的值
    pb=&number2;//不能改变pb的指向

    const int * const pd=&number;//两者都不能进行修改

}
int main(void)
{
    test0();
}