#pragma once
#include"Noncopyable.h"
#include <pthread.h>
namespace wd
{
    class Thread
    :Noncopyable
    {
    public:
        Thread()
        : _pthid(0)
        , _isRunning(false)
        {}

        virtual ~Thread();

        void start();
        void join();

        static void * threadFunc(void *);

    private:

        virtual void run()=0;
        //表示这个函数没有函数体,函数体在派生类里定义,
    private:
        pthread_t _pthid;
        bool _isRunning;
    };
}