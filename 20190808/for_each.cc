 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-08 10:59:56
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

void display(int & number)
{
	++number;
	cout << number << " ";
}

void test0()
{//for_each()内部遍历
// std::for_each()比较简单，其用处却很频繁，通常用于容器中元素的合法性检查，预处理等场景。
	vector<int> numbers{1, 2, 3, 4, 5};

	//std::for_each(numbers.begin(), numbers.end(), display);

	//lambda表达式 ==> 匿名函数
	std::for_each(numbers.begin(), numbers.end(), [&numbers](int number){
		//cout << "numbers.size() = " << numbers.size() << endl;
		//小括号代表的形参列表，大括号代表的函数，[](){}代表匿名函数
		//[&numbers]不复制，[=numbers]会复制
		cout << number << " ";
	});


	cout << endl;
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void test1()
{//find从给定区间中查找单个元素
//count统计区间中某个元素出现的次数.
	vector<int> numbers{7, 1, 2, 6, 8, 9, 3, 4, 5};
	//对线性容器进行查找时，要采用的是std::find/std::count
	//find其时间复杂度为O(N)
	auto it = std::find(numbers.begin(), numbers.end(), 3);
	cout << "*it = " << *it << endl;

	//为了提高查找速度, 可以先排序，再采用二分查找算法进行查找
	//
	//std::sort默认情况下，按升序方式进行排序
	//std::sort(numbers.begin(), numbers.end());
	std::greater<int> gt;
	std::sort(numbers.begin(), numbers.end(), gt);//以gt的方式进行排序
	std::copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//二分查找时间复杂度O(logN)
	auto it2 = std::lower_bound(numbers.begin(), numbers.end(), 3, gt);
	cout << "*it2 = " << *it2 << endl;
}
 
int main(void)
{
	//test0();
	test1();
 
	return 0;
}
