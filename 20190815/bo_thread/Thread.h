#pragma once
#include <pthread.h>
#include"Noncopyable.h"
#include<functional>
namespace wd
{
    class Thread
    :Noncopyable
    {
    public:
        using ThreadCallback=std::function<void()>;

        Thread(ThreadCallback && cb)
        : _pthid(0)
        , _isRunning(false)
        , cb(std::move(cb))
        {}

        ~Thread();

        void start();
        void join();

        static void * threadFunc(void *);

    private:

        //virtual void run()=0;
        //表示这个函数没有函数体,函数体在派生类里定义,
    private:
        pthread_t _pthid;
        bool _isRunning;
        ThreadCallback cb;
    };
}