#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
void display(int & number)
{
    ++number;
    cout<<number<<" ";
}
void test0()
{
    vector<int> numbers{1,2,3,4,5};
    //std::for_each(numbers.begin(),numbers.end(),display);
    //cout<<endl;
    std::for_each(numbers.begin(),numbers.end(),[&numbers](int number){
        cout<<"number="<<number<<" ";
    });
    cout<<endl;
    std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
}
void test1()
{
    vector<int> numbers{3,5,6,2,2,7,2,1,2};
    auto it=std::find(numbers.begin(),numbers.end(),2);
    cout<<"*it="<<*it<<endl;

    std::greater<int> gt;
    std::sort(numbers.begin(),numbers.end(),gt);
    std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    auto it2=std::lower_bound(numbers.begin(),numbers.end(),5,gt);
    cout<<"*it2="<<*it2<<endl;
}
int main(void)
{
   // test0();
   test1();
    return 0;
}