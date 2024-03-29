 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-24 11:32:07
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


//单例对象自动释放
//方法二: 静态成员函数 + atexit


class Singleton
{
public:
	static Singleton * getInstance()
	{ //在多线程环境下是非线程安全的
	  // 加锁
		if(nullptr == _pInstance) {
			::atexit(destroy);//能够解决自动释放问题
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()//返回值是void，参数值又是无参
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}

private:
	//非静态数据成员就是单例对象的一部分
	static Singleton * _pInstance;
};

//Singleton * Singleton::_pInstance = nullptr;//懒汉模式
//
//在进入main函数之前就创建单例对象
Singleton * Singleton::_pInstance = getInstance();//饿汉模式


 
int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	Singleton * p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;

	//Singleton::destroy();

	return 0;
}
