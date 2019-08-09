 ///
 /// @file    cow_string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-30 15:49:29
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class CowString
{
public:
	CowString()
	: _pstr(new char[1 + 4]() + 4)
	{
		initRefcount();
		cout << "CowString()" << endl;
	}

	CowString(const char * pstr)
	: _pstr(new char[strlen(pstr) + 5]() + 4)
	{
		cout << "CowString(const char *)" << endl;
		initRefcount();
		strcpy(_pstr, pstr);
	}

	CowString(const CowString & rhs)//复制构造函数的实现
	: _pstr(rhs._pstr)
	{	//O(1)时间复杂度
		cout << "CowString(const CowString & )" << endl;
		increaseRefcount();
	}

	CowString & operator=(const CowString & rhs)//赋值运算符
	{
		cout << "CowString & operator=(const CowString &)" << endl;
		if(this != &rhs) {//三部曲操作
			release();

			_pstr = rhs._pstr;//执行浅拷贝
			increaseRefcount();//引用计数加1
		}
		return *this;
	}

	const char * c_str() const
	{	return _pstr;	}

	int size() const 
	{	return strlen(_pstr);	}


	~CowString()
	{
		release();
	}

	int refcount() const 
	{	return *(int *)(_pstr - 4);	}

	char & operator[](int idx);

#if 1
	const char & operator[](int idx) const//下标运算符重载
	{	
		cout << "const char & operator[](int idx) const" << endl;
		return _pstr[idx]; 
	}
#endif
	
	friend std::ostream & operator<<(std::ostream & os, const CowString & rhs);//输出运算符定义

private:
	void initRefcount()//引用计数初始化
	{	*(int*)(_pstr - 4) = 1;}

	void increaseRefcount()//引用计数加一
	{	++*(int*)(_pstr - 4);}

	void decreaseRefcount()//引用计数减一
	{	--*(int*)(_pstr - 4);}

	void release()
	{
		decreaseRefcount();//先减一
		if(0 == refcount()) {//引用计数为0时才开始回收
			delete [] (_pstr - 4);	
			cout << ">> delete heap data!" << endl;
		}
	}
private:
	char * _pstr;
};
 
std::ostream & operator<<(std::ostream & os, const CowString & rhs)
{
	os << rhs._pstr;
	return os;
}

//只要字符串的引用计数大于1， 就会进行深拷贝
// 
//问题：下标访问运算符无法区分出接下来的操作是读操作还是写操作
//
//
char & CowString::operator[](int idx)//返回一个char的引用
{
	if(idx >=0 && idx < size()) {
		if(refcount() > 1) {//判断引用计数的值
			decreaseRefcount();//引用计数减1
			
			char * ptmp = new char[size() + 5]() + 4;//进行深拷贝
			strcpy(ptmp, _pstr);
			_pstr = ptmp;
			initRefcount();//进行引用计数的初始化
		}
		return _pstr[idx];
	} else {
		static char nullchar = '\0';
		return nullchar;
	}
}

void func(const CowString & str)//const写法只能调用const成员函数
{
	cout << str[0] << endl;
}


int main(void)
{
	CowString s1 = "hello,world";

	//CowString s2 = "hello,world";
	CowString s2 = s1;//复制构造

	CowString s3 = "shenzhen";
	cout << "s3 = " << s3 << endl;
	s3 = s1;//执行赋值运算符操作之后
 
	cout << "执行赋值操作之后:" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;

	cout << "\n 修改共享字符串的内容之后:" << endl;
	s3[0] = 'X';//写时复制
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;

	cout << "\n 执行读操作之后:" << endl;
	cout << "s1[0] = " << s1[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;

	return 0;
}
