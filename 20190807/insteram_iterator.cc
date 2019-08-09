#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
int main(void)
{
    cout<<"please input valid integer!"<<endl;
    istream_iterator<int> isi(cin);//定义一个容器，容器的内容从标准输入获取
    vector<int> numbers;//vector是一个动态生长的数组
    cout<<"numbers size ="<<numbers.size()<<endl;
    cout<<"numbers capacity = "<<numbers.capacity()<<endl;
    //copy(isi,istream_iterator<int>(),numbers.begin());
    copy(isi,istream_iterator<int>(),std::back_inserter(numbers));//使用插入迭代器
    copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    return 0;
}