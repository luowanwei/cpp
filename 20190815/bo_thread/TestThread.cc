#include"Thread.h"
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;
class Mythread
{
    public:
    void run() 
    {
        ::srand(::clock());
        while(1)
        {
            int number=::rand()%100;
            cout<<">>number="<<number<<endl;
            ::sleep(1);
        }
    }
};

int main(void)
{
    Mythread Mythread;
    unique_ptr<Thread> thread(new Thread(std::bind(&Mythread::run,&Mythread)));
    thread->start();
    thread->join();
    return 0;
}