#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using std::cout;
using std::endl;
using std::vector;
using std::remove;
using std::ostream_iterator;
void test0()
{
    vector<int> numbers{5, 3, 1, 2, 66, 7, 1, 66, 8, 9, 66};
    copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    auto it=remove(numbers.begin(),numbers.end(),66);
    //把remove的返回值作为erase区间形式第一个实参传递很常见，这是个惯用法。
    numbers.erase(it,numbers.end());
    copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

}

void test1()
{
    vector<int> numbers;
    cout<<"numbers size ="<<numbers.size()<<endl;
    cout<<"numbers capacity="<<numbers.capacity()<<endl;
    numbers.push_back(1);//在遍历元素的过程中，做了添加元素的操作.
    cout<<"numbers size="<<numbers.size()<<endl;
    cout<<"numbers capacity="<<numbers.capacity()<<endl;
    bool flag=true;
    auto it= numbers.begin();
    for(;it!=numbers.end();++it){
        cout<<"*it="<<*it<<" ";
        if(flag){
            numbers.push_back(2);
            cout<<"numbers size ="<<numbers.size()<<endl;
            cout<<"numbers capacity="<<numbers.capacity()<<endl;
            flag=false;
        }
    }

}
int main(void){
    test0();
    //test1();
    return 0;
}