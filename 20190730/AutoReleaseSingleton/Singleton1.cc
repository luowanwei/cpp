 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-24 11:32:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//单例对象自动释放
//方法一: 嵌套类 + 静态对象


class Singleton
{
	class AutoRelease//执行一个自动释放的功能，为了singleton进行服务
	{
	public:
		AutoRelease() {	cout << "AutoRelease()" << endl;}
		~AutoRelease() {
			cout << "~AutoRelease()" << endl;
			if(_pInstance)//如果是非静态，不能直接拿到，现在是静态的，被整个类的所有对象进行共享
				delete _pInstance;
		}
	};
public:
	static Singleton * getInstance()
	{ //在多线程环境下是非线程安全的
	  // 加锁
		if(nullptr == _pInstance) {
			_pInstance = new Singleton();
		}
		return _pInstance;//最终只会保留一个
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	Singleton() {	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}

private:
	//AutoRelease _auto;//非静态数据成员就是单例对象的一部分，成为了一部分，则不能销毁，因此只能是静态的
	static Singleton * _pInstance;
	static AutoRelease _auto;
};

Singleton * Singleton::_pInstance = nullptr;//上来时没有直接得到对象的，懒(懒加载)汉模式
//
//在进入main函数之前就创建单例对象，不会发生线程安全问题
//Singleton * Singleton::_pInstance = getInstance();//上来之后进入main函数之前创建一个单例对象，饿汉模式

Singleton::AutoRelease Singleton::_auto;//静态对象拿到类外定义

 
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
