#include <iostream>
using std::cout;
using std::endl;
using std::string;
class person
{
public:
    person(string name,int age)
    :_name(name)
    ,_age(age)
    {
        cout<<"person(string name,int age)"<<endl;
    }
    void display()
    {
        cout<<"name="<<_name<<endl
            <<"age="<<_age<<endl;
    }
private:
    string _name;
    int _age;
};
class employee
:public person
{
public:
    employee(string name,int age,string department,double salary)
    :person(name,age)
    ,_department(department)
    ,_salary(salary)
    {
        cout<<"employee(string name,int age,string department,double salary)"<<endl;
    }
    void display()
    {
        person::display();
        cout<<"department="<<_department<<endl
            <<"salary="<<_salary<<endl;
    }
    double getSalary()
    {
        return _salary;
    }

private:
    string _department;
    double _salary;


};
int main(void)
{
    employee a("aaa",22,"a",1000);
    employee b("bbb",22,"b",2000);
    employee c("ccc",22,"c",3000);
    a.display();
    b.display();
    c.display();
 
    cout<<"argv salary="<<(a.getSalary()+b.getSalary()+c.getSalary())/3<<endl;
    return 0;
}