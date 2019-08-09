#include<log4cpp/Category.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using namespace log4cpp;
inline std::string getline(int line)
{
    std::ostringstream oss;
    oss << line;
    return oss.str();
}
#define message_line(msg) std::string(msg).append("(").append(__FILE__).append(":").append(__func__).append(":").append(getline(__LINE__)).append(")").c_str()                                                      .append(")").c_str()
class Mylogger
{

public:
    static Mylogger * getInstance()
    {
        if(_pInstance==nullptr)
        {
            _pInstance= new Mylogger();
        }
        return _pInstance;
    }

    static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
    void warn(const char * msg)
    {
        _mycategory.warn(msg);
    }
    void error(const char *msg)
    {
        _mycategory.error(msg);
    }
    void debug(const char * msg)
    {
        _mycategory.debug(msg);
    }
    void info(const char * msg)
    {
        _mycategory.info(msg);
    }

private:

    Mylogger()
    :_ptnLayout1(new PatternLayout())
    ,_ptnLayout2(new PatternLayout())
    ,_ostreamAppender(new OstreamAppender("ostreamAppender","&cout"))
    ,_fileAppender(new FileAppender("fileAppender","lww.log"))
    ,_mycategory(Category::getRoot().getInstance("mycategory"))
    {
        _ostreamAppender->setLayout(ptnLayout1);
        _fileAppender->setLayout(ptnLayout2);
        _mycategory.setPriority(Priority::DEBUG);
        _mycategory.addAppender(ostreamAppender);
        _mycategory.addAppender(fileAppender);

    }


    ~Mylogger()
    {
        Category::shutdown();
    }
private:
    PatternLayout * _ptnLayout1;
    PatternLayout * _ptnLayout2;
    OstreamAppender * _ostreamAppender;
    FileAppender * _fileAppender;
    Category & _mycategory;
    static Mylogger* _pInstance;

};
Mylogger * Mylogger::_pInstance=nullptr;
int main(void)
{
    Mylogger * log=Mylogger::getInstance();
    log->warn(getline("warn msg"));
    log->error(getline("error msg"));
    log->debug(getline("debug msg"));
    log->info(getline("info msg"));
    Mylogger::destroy();
    return 0;
}