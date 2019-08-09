#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
template<class T>
class Queue 
{
public:
    Queue(int size = 10)
    : _start(new T[size+1]())
    ,_begin(0)
    ,_end(0)
    ,_size(size)
    {cout<<"Queue()"<<endl;}

    ~Queue();

    bool full();
    bool empty();
    void push(T t);
    void pop();
    T front();
    T end();
private:
    T * _start;
    int _size,_begin,_end;
};
template<class T>
Queue<T>::~Queue()
{
    if(_start)
   {
        delete[] _start;
    }
}
template<class T>
void Queue<T>::push(T t)
{
    if(!full())
    {
        _start[_end]=t;
        _end=(_end+1)%_size;
    }
    else
    {
        cout<<"queue is full"<<endl;
    }
}
template<class T>
void Queue<T>::pop()
{
    if(!empty())
    {
        _end=(_end+_size-1)%_size;
    }
    cout<<"queue is empty"<<endl;
}
template<class T>
T Queue<T>::front()
{
    if(!empty())
    {
        return _start[_begin];
    }
    cout<<"queue is empty"<<endl;
    return _start[_begin];
}
template<class T>
T Queue<T>::end()
{
    if(!empty())
    {
        return _start[(_end+_size-1)%_size];
    }
    cout<<"queue is empty"<<endl;
    return _start[_begin];
}
template<class T>
bool Queue<T>::empty()
{
    return _end==_begin;
}
template<class T>
bool Queue<T>::full()
{
    return (_end+1)%_size==_begin;
}

void test()
{
    Queue<int> queue(10);
    queue.pop();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    cout<<"front="<<queue.front()<<endl;
    cout<<"end="<<queue.end()<<endl;
}

int main(void)
{
    test();
    return 0;
}