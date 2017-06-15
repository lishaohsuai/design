#include<iostream>
using namespace std;

//简单工厂模式
//这就违反了开放封闭原则：软件实体（类、模块、函数）可以扩展，但是不可修改。

enum CTYPE{COREA, COREB};
class SingleCore
{
    public:
    SingleCore(){}
    virtual void Show() = 0;
};
//单核A
class SingleCoreA:public SingleCore
{
    public:
        SingleCoreA(){}
        void Show() 
        {
            cout<<"SingleCore A"<<endl;
        }
};
//单核B
class SingleCoreB:public SingleCore
{
    public:
        SingleCoreB(){}
        void Show()
        {
            cout<<"SingleCore B"<<endl;
        }
};
class Factory
{
    public:
        Factory(){}
        static SingleCore* CreateSingleCore(enum CTYPE ctype)
        {
            if(ctype == COREA)//工厂内部判断
                return new SingleCoreA;
            else if(ctype == COREB)
                return new SingleCoreB;
            else 
                return NULL;
        }
};
int main()
{
    int num;
    cout<<"what you want"<<endl;
    cin>>num;
    SingleCore *p =NULL;
    if(num == 0)
        p =  Factory::CreateSingleCore(COREA);
    else 
        p =  Factory::CreateSingleCore(COREB);
    p->Show();
    
    return 0;
}
