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
:public Thread
{
    void run() override
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
    Mythread thread1;
    //Mythread thread2=thread1;//禁止复制
    
    unique_ptr<Thread> thread(new Mythread());
    thread->start();
    thread->join();
    return 0;
}