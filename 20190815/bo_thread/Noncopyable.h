#pragma once
namespace wd
{
class Noncopyable
{
    protected:
    Noncopyable()
    {}

    ~Noncopyable()
    {}
    Noncopyable(const Noncopyable &)=delete;
    Noncopyable & operator=(const Noncopyable & )=delete;
    //禁止类的拷贝行为只需要把相应的函数设为 = delete即可
};
}