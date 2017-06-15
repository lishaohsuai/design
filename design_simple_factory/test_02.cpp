#include<iostream>
using namespace std;

//工厂方法模式，是指定义一个用于创建对象的接口，让子类决定实例化哪一个类。
//这时，客户要做的是找好工厂，比如要A型号的核，就找A工厂要；否则找B工厂要，不再需要告诉工厂具体要什么型号的处理器核了。
//
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
    virtual  SingleCore * CreateSingleCore() = 0;
};
class FactoryA:public Factory
{
    public:
        FactoryA(){}
        SingleCore* CreateSingleCore();
};
class FactoryB:public Factory
{
    public:
        FactoryB(){}
        SingleCore* CreateSingleCore();
};
SingleCore* FactoryA::CreateSingleCore()
{
    return new SingleCoreA;
}
SingleCore* FactoryB::CreateSingleCore()
{
    return new SingleCoreB;
}
int main()
{
    int num;
    cout<<"what you want"<<endl;
    cin>>num;
    SingleCore *p =NULL;
    Factory *t1 = new FactoryA;
    Factory *t2 = new FactoryB;
    if(num == 0)
        p =  t1->CreateSingleCore();
    else 
        p =  t2->CreateSingleCore();
    p->Show();
    
    return 0;
}
