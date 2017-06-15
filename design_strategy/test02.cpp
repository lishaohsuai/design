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
class Cache
{
    private:
        ReplaceAlgorithm *m_ra;
    public:
        Cache(enum RA ra)
        {
            if(ra == LRU)
            {
                m_ra = new LRU_ReplaceAlgorithm();
            }
            else if(ra == FIFO)
            {
                m_ra = new FIFO_ReplaceAlgorithm();
            }
            else if(ra == RANDOM)
            {
                m_ra = new Random_ReplaceAlgorithm();
            }
            else
                m_ra = NULL;
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
    Cache cache(LRU);//指定标签即可
    cache.Replace();
    return 0;
}
