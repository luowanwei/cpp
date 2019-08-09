#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class MutexLock
{
    public:
        MutexLock()
        {
            pthread_mutex_init(&_mutex,NULL);
        }
        ~MutexLock(){}
        void lock()
        {
            cout<<"lock()"<<endl;
            pthread_mutex_lock(&_mutex);
        }
        void unlock()
        {
            cout<<"unlock()"<<endl;
            pthread_mutex_unlock(&_mutex);
        }
        pthread_mutex_t* getMutexPointer()//获取锁的地址
        {
            return &_mutex;
        }
    private:
        MutexLock(const MutexLock &rhs);//拷贝构造函数私有化
        MutexLock & operator =(const MutexLock &rhs);//复制构造函数私有化
    private:
        pthread_mutex_t _mutex;
};


class Condition
{
    public:
        Condition(MutexLock &mutex)//传互斥锁的引用
        :_mutex(mutex)
        {
            pthread_cond_init(&_cond,NULL);
            cout<<"Condition(MutexLock &mutex)"<<endl;
        }
        void wait()
        {
            pthread_cond_wait(&_cond,_mutex.getMutexPointer());
            cout<<"wait()"<<endl;
        }
        void nodify()//signal
        {
            pthread_cond_signal(&_cond);
            cout<<"nodify()"<<endl;
        }
        void nodifyAll()//signalall
        {
            pthread_cond_broadcast(&_cond);
            cout<<"nodifyAll()"<<endl;
        }
    private:
    pthread_cond_t _cond;
    MutexLock &_mutex;//传互斥锁的引用
};

int main(void)
{
    MutexLock mutex;
    Condition condition(mutex);
    mutex.lock();
    condition.wait();
    cout<<"加了互斥锁中间的操作"<<endl;
    mutex.unlock();
    return 0;
}