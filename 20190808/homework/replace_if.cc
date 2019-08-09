#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
using std::replace_if;
using std::ostream_iterator;
bool compare(int number)
{
    return number>3;//值被写死了，不够灵活
}
int main(void)
{
    vector<int> numbers{1,2,3,4,5,6};
    std::less<int> lt;//需要传递两个参数才能完成调用
    cout<<lt(3,4)<<endl;
    std::greater<int> gt;
    //replace_if(numbers.begin(),numbers.end(),compare,7);
    //replace_if(numbers.begin(),numbers.end(),std::bind1st(lt,3),7);
    replace_if(numbers.begin(),numbers.end(),std::bind2nd(lt,3),7);
    //函数绑定器
    copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;

}