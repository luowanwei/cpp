#include<iostream>
#include<memory>
using std::cout;
using std::endl;
template<class T>
class Myvector
{
public:
    using iterator = T*;
    using const_iterator = const T *;
    Myvector()
    :_start(nullptr)
    ,_finish(nullptr)
    ,_end_of_storage(nullptr)
    {}
    ~Myvector()
    {
        if()
    }

    size_t size() const 
    {
      return  _finish - _start;
    }
    size_t capacity() const
    {
       return _end_of_storage-_start;
    }
    void push_back(const T & value);
    void pop_back();

    iterator begin() const 
    {
        return _start;
    }

    iterator end() const{
        return _finish;
    }

    T & operator[](size_t idx)
    {
        return _start[idx];
    }
private:
    void reallocate();//重新分配空间

private:
    static std::allocator<T> _alloc;
    T * _start;
    T * _finish;
    T * _end_of_storage;
};

template < class T>
void Myvector<T>::push_back(const T & value)
{
    if(size()==capacity())
    {
        reallocate();
    }
    _alloc.construct(_finish++,value);//在_finish指针的位置构造对象
}


template<class T>
void Myvector<T>::pop_back()
{
    if(size()>0)
    {
        _alloc.destroy(--finish);
    }
}


template<class T>
void Myvector<T>::reallocate()
{
    size_t capa=capacity();
    size_t newCapa=2*capa>0?2*capa:1;
    

    T * ptmp=_alloc.allocate(newCapa);
    //没有任何元素的空间，没有对象
    if(_start){
        std::uninitialized_copy(_start,_finish,ptmp);
        while(_finish!=_start)
        _alloc.destroy(--_finish);//destory销毁一个元素
        _alloc.deallocate(_start,capa);//回收空间
    }
    _start=ptmp;
    _finish=_start+capa;
    _end_of_storage=_start+newCapa;//重新调整位置

}
template < class Container>
void display(const Container & c)
{
    typename Container::const_iterator cit = c.begin();
    while(cit!=c.end())
    {
        cout<<"*cit="<<*cit<<" ";
    }
    cout<<endl;
}//打印元素

template<class Container>
void showCapacity(const Container & c)
{
    cout<<"c size="<<c.size()<<endl;
    cout<<"c capacity="<<c.capacity()<<endl;
}

int main(void)
{
    Myvector<int> numbers;
    showCapacity(numbers);
    return 0;
}