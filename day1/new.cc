#include<stdlib.h>
#include<iostream>
using std::cout;
using std::endl;
void test0()
{
    int * pint=(int*)malloc(sizeof(int));//系统调用
    *pint=10;
    int*pint2=(int*)malloc(sizeof(int)*10);
    free(pint);
    free(pint2);
}
void test1(){
    int * pint=new int(1);//new表达式
    cout<<" *pint="<<*pint<<endl;
    int *pint2=new int[10]();
    delete pint;//delete表达式
    delete [] pint2;
}
int main(void){
    test1();
    return 0;
}