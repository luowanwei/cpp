#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<fstream>
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::ofstream;
using std::ostream_iterator;
int main(void)
{
    vector<int> numbers{1,2,3,4,5};
    for(auto it=numbers.begin();it!=numbers.end();++it)
        cout<<"*it="<<*it<<" ";
    cout<<endl;

    ostream_iterator<int> osi(cout," ");//把vector里的东西放到cout容器里
    copy(numbers.begin(),numbers.end(),osi);//copy到另一个容器里
    cout<<endl;
    return 0;
}