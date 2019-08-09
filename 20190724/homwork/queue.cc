#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
const int MAXSIZE=10;
class Queue
{
    public:
        Queue()//构造函数
        :_head(0)
        ,_tail(0)
        {
            memset(_queue,0,sizeof(_queue));
        }

        ~Queue(){}//析构

        void push(int val)//元素入队 
        {
            if((_queue[_head]==0)&&(_queue[_tail]==0))
            {
                _queue[_tail++]=val;
            }
            else if((_tail-_head+1+MAXSIZE)%MAXSIZE!=0)
            {
                _queue[_tail++]=val;
            }
        }
        void pop()//元素出队
        {
            if(_tail!=_head)
            {
                _head++;
            }
        }
        int front()//读取队头元素
        {
            if(_tail!=_head)
            {
                cout<<"_queue[_head]="<<_queue[_head]<<endl;
                return _queue[_head];
            }
            else
            {
            return -1;
            }
        }
        int back()//读取队尾元素
        {
            if(_tail!=_head)
            {
                cout<<"_queue[_tail-1]="<<_queue[_tail-1]<<endl;
                return _queue[_tail-1];
            }
            else
            {
            return -1;
            }
        }
        bool emty()
        {
            if(_tail==_head)
            {
                return 0;
            }
        }
        bool full()
        {
            if((_head+1+MAXSIZE) == _tail)
            {
                return 0;
            }
        }
    private:
        int _queue[MAXSIZE];
        int _head;
        int _tail;
};

int main(void)
{
        Queue q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.front();
        q.back();
        q.pop();
        q.pop();
        q.front();
        q.back();
        return 0;
}