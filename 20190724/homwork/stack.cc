#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class Stack
{
    public:
        Stack()
        :_num(0){}
        ~Stack(){}
        void push(int val)//近栈
        {
            if(_num<10)
            {
                _arr[_num++]=val;
            }
        }
        void pop()//出栈
        {
            if(_num>0)
            {
                _num--;
            }
        }
        int top()//返回栈顶元素
        {
            if(_num>0)
            {
                cout<<"_arr[_num-1]="<<_arr[_num-1]<<endl;
                return _arr[_num-1];
            }
            else
            {
                return -1;
            }
        }
        bool empty()//判断栈空
        {
            return _num == 0;
        }
        bool full()//判断栈满
        {
            return _num == 10;
        }
    private:
        int _arr[10];//栈可容纳的最大元素
        int _num;//当前长度

    
};
int main(void)
{
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.top();
    a.pop();
    a.top();
    return 0;
}
