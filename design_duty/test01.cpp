#include<iostream>
using namespace std;
//职责 链模式
class Manager
{
    protected:
        Manager *m_manager;
        string m_name;
    public:
        Manager(Manager *manager, string name):m_manager(manager), m_name(name){}
        virtual void DealWithRequest(string name, int num){}
};
//经理 
class CommonManager : public Manager
{
    public:
        CommonManager(Manager *manager, string name):Manager(manager,name){}
        void DealWithRequest(string name, int num)
        {
            if(num<500)
            {
                cout<<"经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"$"<<endl;
            }
            else
            {
                cout<<"经理"<<m_name<<"无法处理,交由总监处理"<<endl;
                m_manager->DealWithRequest(name, num);

            }
        }
};
//总监
class Majordemo:public Manager
{
    public:
        Majordemo(Manager *manager, string name):Manager(manager,name){}
        void DealWithRequest(string name, int num)
        {
            if(num<1000)
            {
                cout<<"总监"<<m_name<<"批准"<<name<<"加薪"<<num<<"$"<<endl;
            }
            else 
            {
                cout<<"总监"<<m_name<<"无法处理,交由总经理处理"<<endl;
                m_manager->DealWithRequest(name, num);
            }
        }
};
class GeneralManager:public Manager
{
    public:
        GeneralManager(Manager *manager, string name):Manager(manager,name){}
        void DealWithRequest(string name, int num)
        {
            cout<<"总经理不处理."<<endl;
        }
};
int main()
{
    Manager *general = new GeneralManager(NULL,"A");
    Manager *majordemo = new Majordemo(general,"B");
    Manager *common = new CommonManager(majordemo, "C");
    common->DealWithRequest("D",300);
    common->DealWithRequest("E",600);
    common->DealWithRequest("F",1000);
    delete common;delete majordemo; delete general;
    return 0;
}
