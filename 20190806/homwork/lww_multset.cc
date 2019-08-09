#include<math.h>
#include<iostream>
#include<set>
#include<string>
using std::cout;
using std::endl;
using std::multiset;
using std::string;
template <class Container>
void display(const Container & c)
{
    typename Container::const_iterator cit=c.begin();
    while(cit!=c.end()){
        cout<<*cit<<" ";
        ++cit;

    }
    cout<<endl;
}
void test0()
{
    multiset<int> numbers;
    cout<<"numbers' size="<<numbers.size()<<endl;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(3);
    numbers.insert(4);
    numbers.insert(3);
    numbers.insert(3);
    display(numbers);
}
void test1()
{
    int arr[10]={3,6,1,2,6,5,7,9,8,3};
    multiset<int> numbers(arr,arr+10);
    display(numbers);

    multiset<int>::iterator it = numbers.begin();
    cout<<"迭代器指针指向的值为 *it="<<*it<<endl;
    numbers.erase(it);
    cout<<"删除后的元素为"<<endl;
    display(numbers);

    auto ret=numbers.insert(2);
    cout<<"增加的元素是*ret="<<*ret<<endl;

    if(numbers.count(2)){
        cout<<"使用范围count查找成功查找元素"<<endl;
    }
    else{
        cout<<"multiset 没有该元素"<<endl;
    }

    auto it2=numbers.find(3);
    if(it2==numbers.end()){
        cout<<"multiset 没有该元素"<<endl;
    }
    else{
        cout<<"使用find查找元素成功"<<endl;
        cout<<"查找的元素*it2="<<*it2<<endl;
    }

    auto lowerbound=numbers.lower_bound(6);
    cout<<"边界查找的下边界为*lowerbound="<<*lowerbound<<endl;
    auto upperbound=numbers.upper_bound(6);
    cout<<"边界查找的上边界为*upperbound="<<*upperbound<<endl;
    while(lowerbound!=upperbound)
    {
        cout<<*lowerbound<<" ";
        ++lowerbound;
    }
    cout<<endl;
}

void test2()
{
    std::pair<int,string> p(1,"shenzhen");
    cout<<p.first<<"--->"<<p.second<<endl;
}

class Point
{
public:
    Point(int ix,int iy)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }
    double getDistence() const
    {
        return sqrt(_ix*_ix+_iy*_iy);
    }
    friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
private:
    int _ix;
    int _iy;
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
    os <<"("<<"rhs._ix="<<rhs._ix
        <<","<<"rhs._iy="<<rhs._iy
        <<")";
        return os;
}

bool operator<(const Point & lhs,const Point & rhs)
{
    return lhs.getDistence()<rhs.getDistence();
}
bool operator>(const Point & lhs,const Point & rhs)
{
    return lhs.getDistence()>rhs.getDistence();
}
struct Comparator
{
    bool operator()(const Point & lhs,const Point & rhs)const
    {
        return lhs.getDistence()<rhs.getDistence();
    }
};

void test3()
{
    multiset<Point,std::greater<Point>> numbers{
        Point(1,1),
        Point(2,2),
        Point(3,3),
        Point(2,2),
    };
    display(numbers);
    multiset<Point>::iterator it=numbers.begin();
    cout<<"迭代器指向的*it="<<*it<<endl;
    display(numbers);

    auto ret=numbers.insert(Point(11,11));
        cout<<"增加的点为*ret="<<*ret<<endl;

    if(numbers.count(Point(11,11)))
    {
        cout<<"使用范围count查找成功查找元素"<<endl;
    }
    else
    {
        cout<<"multiset 没有该元素"<<endl;
    }

    auto it2=numbers.find(Point(11,11));
    if(it2==numbers.end())
    {
        cout<<"multiset 没有该元素"<<endl;
    }
    else
    {
         cout<<"使用find查找元素成功"<<endl;
        cout<<"查找的元素*it2="<<*it2<<endl;
    }
    
}
int main(void)
{
    test1();
    return 0;
}