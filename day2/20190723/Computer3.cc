 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 11:44:54
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float price)//computer构造函数的写法
	: _brand(new char[strlen(brand)+ 1]())
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char*, float)" << endl;
	}

	void print();

	//系统提供的不满足需求
	//~Computer(){}

	~Computer()
	{//析构函数的作用是用来清理对象开辟的资源
		if(_brand)
			delete [] _brand;//释放堆空间

		cout << "~Computer()" << endl;
	}

private:
	char * _brand;//品牌换成指针写法，使用系统提供的析构函数，会造成内存泄漏
	float _price;
};
 

inline void Computer::print()
{
	cout << "brand:" << _brand << endl
		 << "price:" << _price << endl;
}


Computer gPc("Xiaomi", 7500);//全局对象，生命周期结束也会进行自动销毁

int test0(void)
{
	//自定义类类型
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;//16个字节，字节对齐导致的
	Computer pc("Thinkpad", 8888);
	cout <<  "pc = ";
	pc.print();

	Computer pc2("ACER", 6666);
	cout << "pc2 = ";
	pc2.print();

	gPc.print();

	static Computer pc3("Lenovo", 5555);//静态对象也会自动销毁
	pc3.print();

	Computer * pc4 = new Computer("MateBook", 7500);
	pc4->print();

	delete pc4;
 
	return 0;
}

int main(void)
{
	test0();
	return 0;
}
