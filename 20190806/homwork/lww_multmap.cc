#include<math.h>
#include<iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::pair;
//multimap 是关联型容器, 保存<key, value>键值对, 多个value可以由相同的key.
//map中的元素根据key和比较器排序.
template<class Container>
void display(const Container & c)
{
    typename Container::const_iterator cit = c.begin();
    for(;cit!=c.end();++cit)
    {
        cout<<cit->first<<"--->"<<cit->second<<endl;
    }
}

void test0()
{
    multimap<int,string> cities;
    cities.insert(pair<int,string>(1,"beijing"));
    cities.insert(pair<int,string>(2,"shanghai"));
    cities.insert(pair<int,string>(2,"guangzhou"));
    cities.insert(pair<int,string>(4,"shenzhen"));
    display(cities);
}

void test1()
{
    multimap<int,string> cities={
        std::make_pair(4,"shenzhen"),
        pair<int,string>(1,"beijing"),
        std::make_pair(2,"shanghai"),
        std::make_pair(2,"guangzhou"),
    };
    display(cities);
    auto ret=cities.insert(std::make_pair(5,"whhuang"));
    cout<<ret->first<<"--->"
        <<ret->second<<endl;

    display(cities);
    multimap<int,string>::iterator it=cities.find(8);
    if(it!=cities.end()){
        cout<<"查找元素成功"<<endl;
        cout<<"it->first="<<it->first<<"--->"
            <<"it->second="<<it->second<<endl;
    }
    else{
        cout << "find查找失败, 不会添加新的元素" << endl;
    }
    display(cities);
}
void test2()
{
    multimap<string,string> cities={
        std::make_pair("0755","shenzhen"),
        pair<string,string>("010","beijing"),
        std::make_pair("021","shanghai"),
        std::make_pair("0755","guangzhou"),

    };
    display(cities);
    auto ret=cities.insert(std::make_pair("027","wuhang"));
    cout<<"ret->first="<<ret->first<<"-->"
        <<"ret->second="<<ret->second<<endl;
    display(cities);

    multimap<string,string>::iterator it=cities.find("0728");
    if(it!=cities.end()){
        cout<<"find查找元素成功"<<endl;
        cout<<"it->first="<<it->first<<"-->"<<"it->second"<<it->second<<endl;

    }
    else{
        cout << "find查找失败, 不会添加新的元素" << endl;
    }
    display(cities);

}

class Point
{
public:
Point(int ix,int iy)
:_ix(ix)
,_iy(iy)
{
    cout<<"Point(int ix,int iy)"<<endl;
}
double getDistance() const
{
    return sqrt(_ix*_ix+_iy*_iy);
}
friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
private:
    int _ix;
    int _iy;

};

std::ostream & operator<<(std::ostream &os ,const Point & rhs)
{
    os<<"("<<rhs._ix
    <<","<<rhs._iy
    <<")";
    return os;
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}

struct Comparator
{
	bool operator()(const Point & lhs, const Point & rhs) const
	{
		return lhs.getDistance() < rhs.getDistance();
	}
};
void test3()
{
    multimap<Point,int,Comparator> points=
    {
        std::make_pair(Point(1,1),1),
        std::make_pair(Point(2,2),1),
        std::make_pair(Point(3,3),1),
        std::make_pair(Point(4,4),1),
    };
    display(points);
}

int main(void)
{
    test1();
    //test2();
    //test3();
    return 0;
}