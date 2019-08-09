 ///
 /// @file    log4cpp2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-26 16:51:10
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;
 
int main(void)
{
	PatternLayout * ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d %c [%p] %m%n");//设置日志具体的格式
 
	PatternLayout * ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d %c [%p] %m%n");

	OstreamAppender * ostreamAppender = new OstreamAppender(
		"ostreamAppender",
		&cout);//把日志信息输出到终端
	ostreamAppender->setLayout(ptnLayout1);//输出布局

	FileAppender * fileAppender = new FileAppender(
		"fileAppender",
		"wangdao.log");//第二个appender
	fileAppender->setLayout(ptnLayout2);

	Category & mycategory = Category::getRoot().getInstance("mycategory");
	mycategory.setPriority(Priority::DEBUG);
	mycategory.addAppender(ostreamAppender);
	mycategory.addAppender(fileAppender);

	mycategory.alert("this is alert message");
	mycategory.crit("this is crit message");
	mycategory.error("this is error message");
	mycategory.warn("this is warn message");
	mycategory.info("this is info message");
	mycategory.notice("this is notice message");

	Category::shutdown();

	return 0;
}
