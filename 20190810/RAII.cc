 ///
 /// @file    RAII.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-10 11:18:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class RAII
{
public:
	RAII(T * p)
	: _p(p)
	{}
//访问资源的方法
	T * operator->()//箭头运算符
	{
		return _p;
	}

	T & operator*()//解引用运算符
	{
		return *_p;
	}

	T * get() {	return _p;	}

	void reset(T * p) //重新托管一个新的资源
	{
		delete _p;
		_p = p;
	}

	~RAII() 
	{
		if(_p)
			delete _p;
	}

private:
	T * _p;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	} 

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
		     << ")" << endl;
	}

	~Point(){	cout << "~Point()" << endl;	}
private:
	int _ix;
	int _iy;
};
 
std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
 
int main(void)
{
	//智能指针
	RAII<Point> pointer(new Point(1, 2));
	cout << "*pointer = " << *pointer << endl;
	pointer->print();

	return 0;
}
