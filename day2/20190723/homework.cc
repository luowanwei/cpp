#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class String 
{
    public:
        String()//无参构造函数
        : _pstr(new char[1]())
        {
            strcpy(_pstr,"0");
            cout<<"String()"<<endl;
        }
        String(const char * pstr)//重载构造函数
        : _pstr(new char[strlen(pstr)+1]())
        {
            strcpy(_pstr,pstr);
            cout<<"String(const char * pstr)"<<endl;
        }
        String(const String & rhs)//深拷贝
        : _pstr(new char[strlen(rhs._pstr)+1]())
        {
            cout << "String(const String & rhs)" << endl;
		    strcpy(_pstr, rhs._pstr);
        }
        String & operator=(const String & rhs)
        {
            if(this !=&rhs){
                cout << "String & operator=(const String & rhs)" << endl;
                delete [] _pstr;
                _pstr = new char[strlen(rhs._pstr)+1]();
                strcpy(_pstr,rhs._pstr);
            }
            return *this;
        }
        ~String()//析构函数
        {
            if(_pstr)
                delete [] _pstr;
            cout<<"~String()"<<endl;
        }
        void print();
    private:
        char * _pstr;
};

inline void String::print()
{
    printf("pstr = %p\n", _pstr);
	cout << "pstr:" << _pstr << endl;
}

int main(void)
{
	String str1;
	str1.print();
	
	String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
	
	return 0;
}