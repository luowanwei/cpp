#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class LRUCache
{
public:
    LRUCache(int capacity)
    :_capacity(capacity)
    {}
    int get(int key)
    {
        auto it=_hashList.find(key);
        //无序关联式容器，find的时间复杂度应该是o(1)
        if(it!=_hashList.end())
        {
            //查找到元素
            int ret=it->second->value;
            _nodes.splice(_nodes.begin(),_nodes,it->second);
            //移动list的位置
            _hashList[key]=_nodes.begin();
            //修改其在hashlish中的位置
            return ret;
        }
        else
        {
            return -1;
        }
        
   }
    void put(int key,int value)
    {
        //先要判断下节点有没有满
        auto it=_hashList.find(key);
        if(it==_hashList.end())
        {
            //新节点
            if(_nodes.size()==_capacity)
            {
                //淘汰节点
                int k=_nodes.back().key;
                _nodes.pop_back();
                _hashList.erase(k);
            }
            _nodes.push_front(CacheNode(key,value));//往头部添加结点
            _hashList[key]=_nodes.begin();
        }
        else
        {
            //更新节点值
            it->second->value=value;
            _nodes.splice(_nodes.begin(),_nodes,it->second);
            _hashList[key]=_nodes.begin();
        }
        
    }
private:
    struct CacheNode{
        CacheNode(int k,int v)
        :key(k),value(v)
        {}
        int key;
        int value;
    };
private:
    size_t _capacity;
    list<CacheNode> _nodes;
    unordered_map<int,list<CacheNode>::iterator> _hashList;
};

int main(void)
{
    LRUCache Cache(2);
    Cache.put(1,1);
    Cache.put(2,2);
    cout<<"Cache.get(1)="<<Cache.get(1)<<endl;
    cout<<"Cache.get(2)="<<Cache.get(2)<<endl;
    Cache.put(3,3);
    cout<<"Cache.get(3)="<<Cache.get(3)<<endl;
    cout<<"Cache.get(1)="<<Cache.get(1)<<endl;
    return 0;
}