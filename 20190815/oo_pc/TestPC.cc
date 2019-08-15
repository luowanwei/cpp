 ///
 /// @file    TestPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:39:00
 ///

#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace wd;
 
int main(void)
{
	TaskQueue taskque(10);//当前队列放10个元素

	unique_ptr<Thread> producer(new Producer(taskque));
	unique_ptr<Thread> consumer(new Consumer(taskque));

	producer->start();
	consumer->start();//开启线程的运行

	producer->join();
	consumer->join();//等待线程执行结束
 
	return 0;
}
