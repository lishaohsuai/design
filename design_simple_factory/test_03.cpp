#include<iostream>
using namespace std;

//工厂方法模式，是指定义一个用于创建对象的接口，让子类决定实例化哪一个类。
//这时，客户要做的是找好工厂，比如要A型号的核，就找A工厂要；否则找B工厂要，不再需要告诉工厂具体要什么型号的处理器核了。
//如果这家公司发展迅速，推出了很多新的处理器核，那么就要开设相应的新工厂.
//抽象方法模式 无需制定具体的累.
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
//多核
class MultiCore
{
    public:
        virtual void Show()=0;
};
class MultiCoreA:public MultiCore
{
    public:
        void Show()
        {
            cout<<"Multi CoreA"<<endl;
        }
};
class MultiCoreB:public MultiCore
{
    public:
    void Show()
    {
        cout<<"Multi CoreB"<<endl;
    }
};
class Factory
{
public:
    Factory(){}
    virtual MultiCore* CreateMultiCore() = 0;
    virtual  SingleCore * CreateSingleCore() = 0;
};
class FactoryA:public Factory
{
    public:
        FactoryA(){}
        SingleCore* CreateSingleCore();
        MultiCore* CreateMultiCore();
};
class FactoryB:public Factory
{
    public:
        FactoryB(){}
        SingleCore* CreateSingleCore();
        MultiCore* CreateMultiCore();
};

SingleCore* FactoryA::CreateSingleCore()
{
    return new SingleCoreA;
}
MultiCore* FactoryA::CreateMultiCore()
{
    return new MultiCoreA;
}
SingleCore* FactoryB::CreateSingleCore()
{
    return new SingleCoreB;
}
MultiCore* FactoryB::CreateMultiCore()
{
    return new MultiCoreB;
}

int main()
{
    int num;
    cout<<"what you want"<<endl;
    cin>>num;
    MultiCore *p2 =NULL;
    SingleCore *p1 =NULL;
    Factory *t1 = new FactoryA;
    Factory *t2 = new FactoryB;
    if(num == 0)
    {
       p1 = t1->CreateSingleCore();
       p2 = t1->CreateMultiCore(); 
    }
    else 
    {
        p1 = t2->CreateSingleCore();
        p2 = t2->CreateMultiCore();
    }
    p1->Show();
    p2->Show();
    
    return 0;
}
