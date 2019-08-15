#include"Thread.h"
#include<iostream>
using std::cout;
using std::endl;
namespace wd
{
Thread::~Thread()
{
    if(_isRunning)
    {
        pthread_detach(_pthid);
        //使得th线程在结束运行时自行释放所占用的 内存资源
    }
}
void Thread::start()
{
    pthread_create(&_pthid,nullptr,threadFunc,this);
    _isRunning=true;//执行结束，子线程跑起来了
}
void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pthid,nullptr);//等待子线程执行的结束
        //函数pthread_join用来等待一个线程的结束,线程间同步的操作
        _isRunning=false;//等到了
    }
}

void * Thread::threadFunc(void * arg)
{
    Thread * pthread=static_cast<Thread *>(arg);
    //tatic_cast相当于传统的C语言里的强制转换
    if(pthread)
    {
        pthread->cb();//执行任务
    }
    return nullptr;
}
}