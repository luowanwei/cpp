#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CowString
{
public:
    CowString()
    :_pstr(new char[1+4]()+4)
    {
        initRefcount();
        cout<<"CowString()"<<endl;
    }
    CowString(const char* pstr)
    :_pstr(new char[strlen(pstr)+5]()+4)
    {
        cout<<"CowString(const char *)"<<endl;
        initRefcount();
        strcpy(_pstr,pstr);
    }
    CowString(const CowString & rhs)
    :_pstr(rhs._pstr)
    {
        cout<<"CowString(const CowString &)"<<endl;
        increaseRefcount();
    }
    CowString & operator=(const CowString & rhs)
    {
        cout<<"CowString & operator=(const CowString &)"<<endl;
        if(this!=&rhs)
        {
            release();
            _pstr=rhs._pstr;
            increaseRefcount();
        }
        return *this;
    }
    const char * c_str() const{
        return _pstr;
    }
    int size() const{
        return strlen(_pstr);
    }
    ~CowString()
    {
        release();
    }
    int refcount() const{
        return *(int *)(_pstr-4);
    }
    char & operator[](int idx);
    const char & operator[](int idx) const
    {
        cout<<"const char & operator[](int idx) const"<<endl;
        return _pstr[idx];
    }
    friend std::ostream & operator<<(std::ostream & os,const CowString & rhs);
private:
    void initRefcount()
    {
        *(int *)(_pstr-4)=1;
    }
    void increaseRefcount()
    {
        ++*(int *)(_pstr-4);
    }
    void decreaseRefcount()
    {
        --*(int *)(_pstr -4);
    }
    void release()
    {
        decreaseRefcount();
        if(0==refcount())
        {
            delete[] (_pstr-4);
            cout<<"delete heap data"<<endl;
        }
    }
private:
    char *_pstr;
};
std::ostream & operator<<(std::ostream & os,const CowString & rhs)
{
    os<<rhs._pstr;
    return os;
}
char & CowString::operator[](int idx)
{
    if(idx>=0&&idx<size())
    {
        if(refcount()>1)
        {
            decreaseRefcount();
            char * ptmp=new char[size()+5]()+4;
            strcpy(ptmp,_pstr);
            _pstr=ptmp;
            initRefcount();
        }
        return _pstr[idx];
    }else{
        static char nullchar='\0';
        return nullchar;
    }
}
int main(void)
{
    CowString s1="hello,world";
    CowString s2=s1;
    CowString s3="shenzhen";
    cout << "s1 = " << s1 <<endl;
    cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;

    	cout << "\n 修改共享字符串的内容之后:" << endl;
	s3[0] = 'X';//写时复制
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	printf("s1's address is %p\n", s1.c_str());
	printf("s2's address is %p\n", s2.c_str());
	printf("s3's address is %p\n", s3.c_str());
	cout << "s1's refcount = " << s1.refcount() << endl;
	cout << "s2's refcount = " << s2.refcount() << endl;
	cout << "s3's refcount = " << s3.refcount() << endl;
    return 0;
}