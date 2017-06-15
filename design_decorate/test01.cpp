#include<iostream>
using namespace std;

class Phone
{
    public:
        Phone(){}
        virtual ~Phone(){}
        virtual void ShowDecorate(){}
};
//具体的手机
class iPhone:public Phone
{
    private:
        string m_name;
    public:
        iPhone(string name):m_name(name){}
        ~iPhone(){}
        void ShowDecorate()
        {
            cout<<m_name<<"的装饰"<<endl;
        }
};
class NokiaPhone:public Phone
{
    private:
        string m_name;
    public:
        NokiaPhone(string name):m_name(name){}
        ~NokiaPhone(){}
        void ShowDecorate()
        {
            cout<<m_name<<"的装饰"<<endl;
        }
};
class DecoratorPhone:public Phone
{
    private:
        Phone *m_phone;
    public:
        DecoratorPhone(Phone *phone):m_phone(phone){}
        virtual void ShowDecorate()
        {
            m_phone->ShowDecorate();
        }
};
class DecoratorPhoneA : public DecoratorPhone
{
    public:
        DecoratorPhoneA(Phone *phone):DecoratorPhone(phone){}
        void ShowDecorate()
        {
            DecoratorPhone::ShowDecorate();
            AddDecorate();
        }
    private:
        void AddDecorate()
        {
            cout<<"增加挂件"<<endl;
        }
};
class DecoratorPhoneB : public DecoratorPhone
{
    public:
        DecoratorPhoneB(Phone *phone):DecoratorPhone(phone){}
        void ShowDecorate()
        {
            DecoratorPhone::ShowDecorate();
            AddDecorate();
        }
    private:
        void AddDecorate()
        {
            cout<<"屏幕贴膜"<<endl;
        }
};//装饰模式
int main()
{
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone);
    Phone *dpb = new DecoratorPhoneB(dpa);
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete iphone;
    return 0;
}
