 ///
 /// @file    log4cpp1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-26 16:11:26
 ///
 
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;
 
int main(void)
{
	OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
	//把日志信息输出到终端
	ostreamAppender->setLayout(new BasicLayout());
   //设置一个格式化布局
	Category & root = Category::getRoot();
	root.setPriority(Priority::CRIT);//设置优先级
	root.addAppender(ostreamAppender);

	root.alert("this is alert message");//进行日志记录
	root.crit("this is crit message");
	root.error("this is error message");
	root.warn("this is warn message");
	root.info("this is info message");
	root.notice("this is notice message");


	Category::shutdown();//进行回收

	return 0;
}
