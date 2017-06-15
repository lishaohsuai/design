#include<cstring>
#include<cstdlib>
#include <iostream>
using namespace std;
//确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例，这个类称为单例类，
//它提供全局访问的方法。单例模式是一种对象创建型模式。
//Singleton
class Singleton
{
    public:
        static Singleton * GetInstance(const char *name);
        virtual void Show(){}
    private:
        static Singleton *singleton;
    protected:
        Singleton(){}
};
//Singleton A
class SingletonA:public Singleton
{
    friend class Singleton;//必须是有缘类否则弗雷无法访问子类的构造函数
                            // 自类是父类的有源
    public:
        void Show()
        {
            cout<<"SingletonA"<<endl;
        }
    private:
        SingletonA(){}
};
//Singleton B
class SingletonB:public Singleton
{
    friend class Singleton;//必须是友原类型
    public:
        void Show()
        {
            cout<<"SingletonB"<<endl;
        }
    private:
        SingletonB(){}
};

//Singleton.cpp
Singleton* Singleton::singleton = NULL;
Singleton*Singleton::GetInstance(const char *name)
{
    if(singleton == NULL)
    {
        if(strcmp(name, "SingletonA") == 0)
            singleton = new SingletonA();
        else if(strcmp(name,"SingletonB")==0)
        {
            singleton = new SingletonB();
        }
        else singleton =new Singleton();
    }
    return singleton;
}
int main()
{
    Singleton *st = Singleton::GetInstance("SingletonA");
    Singleton *ss = Singleton::GetInstance("SingletonB");
    ss->Show();
    st->Show();
    return 0;
}
