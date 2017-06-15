#include<iostream>
using namespace std;
//策略模式
enum RA{LRU, FIFO, RANDOM};
class ReplaceAlgorithm
{
    public:
        virtual void Replace() = 0;
};
//三种具体的替换方法
class LRU_ReplaceAlgorithm:public ReplaceAlgorithm
{
    public:
        void Replace()
        {
            cout<<"Least Recently Used replace algorithm"<<endl;
        }
};

class FIFO_ReplaceAlgorithm:public ReplaceAlgorithm
{
    public:
        void Replace()
        {
            cout<<"First in First out replace algorithm"<<endl;
        }
};
class Random_ReplaceAlgorithm:public ReplaceAlgorithm
{
    public:
        void Replace()
        {
            cout<<"Random replace algorithm"<<endl;
        }
};
template <class RA>
class Cache
{
    private:
        RA m_ra;
    public:
        Cache()     
        {}
        ~Cache()
        {}
        void Replace()
        {
            m_ra.Replace();
        }
};
int main()
{
    Cache<Random_ReplaceAlgorithm> cache;//模板实现
    cache.Replace();
    return 0;
}
