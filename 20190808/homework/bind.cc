#include<iostream>
#include<functional>
using std::cout;
using std::endl;
void display()
{
    cout<<"display()"<<endl;
}
void print()
{
    cout<<"print()"<<endl;
}


typedef void(*Function)();//函数类型，函数本身也是一种类型
//函数的类型就是用返回值和形参列表来进行定义的

class Example
{
public: 
    Example()=default;
    void display()
    {
        cout<<"Example::display()"<<endl;
    }
    int add(int x,int y)
    {
        return x+y;
    }
    int _data=10;
};



int test0(void)
{
    void(*f)()=display;//f充当变量
    f();
    f=print;
    f();
    return 0;
}
void test1()
{
    Function f=display;//函数类型的对象
    f();
    f=print;
    f();
}

void test2()
{
    //function是类模板
    std::function<void()>  f =display;//也可以看作函数类型或者一个函数容器
    //返回值是void，参数类型是无参
    f();
    f=print;
    f();
    Example e;
    f=std::bind(&Example::display,e);//借助std::bind进行适配
    f();
}

int add(int x, int y)
{
    cout << "x = " << x << endl
		 << "y = " << y << endl;
	return x + y;
}

void test3()
{
    auto f = std::bind(add, 1, 2);
    cout << "f()=" << f() << endl;

    //占位符
    using namespace std::placeholders;
    auto f2=std::bind(add,1,_1);
    cout<<"f2(100)="<<f2(100)<<endl;

    auto f3=std::bind(add,_1,10);
    cout<<"f3(10)="<<f3(10)<<endl;

    //绑定成员函数
    Example e;
    auto f4=std::bind(&Example::add,&e,_1,_2);
    cout<<"f4(11,12)="<<f4(11,12)<<endl;

    auto f5=std::bind(&Example::add,&e,10,20);
    cout<<"f5(11,12)="<<f5(11,12)<<endl;//11,12无效参数，不起作用

    auto f6=std::bind(&Example::_data,&e);
    cout<<"f6()="<<f6()<<endl;

    auto f7 = std::bind(&Example::add, e, _1, _2);
    //对于成员函数而言，绑定时this指针所在的位置可以
	//传递地址，也可以传递对象本身
	cout << "f7(11, 12) = " << f7(11, 12) << endl;
}


int main(void)
{
   // test1();
    //test2();
    test3();
    return 0;
}