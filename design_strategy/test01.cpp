#include<iostream>
using namespace std;
//策略模式

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
class Cache
{
    private:
        ReplaceAlgorithm *m_ra;
    public:
        Cache(ReplaceAlgorithm *ra)
        {
            m_ra = ra;
        }
        ~Cache()
        {
            delete m_ra;
        }
        void Replace()
        {
            m_ra->Replace();
        }
};
int main()
{
    Cache cache(new LRU_ReplaceAlgorithm());//暴露的太多的细节
    cache.Replace();
    return 0;
}
