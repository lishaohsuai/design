#include <iostream>
using namespace std;
//模板
//一个操作中算法的框架，而将一些步骤延迟到子类中。
//模板方法模式使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
class Resume
{
    protected:
        virtual void SetPersonalInfo(){}
        virtual void SetEducation(){}
        virtual void SetWorkExp(){}
    public:
        void FillResume()
        {
            SetPersonalInfo();
            SetEducation();
            SetWorkExp();
        }
};
class ResumeA:public Resume
{
    protected:
        void SetPersonalInfo()
        {
            cout<<"A's PersonalInfo"<<endl;
        }
        void SetEducation()
        {
            cout<<"A's Education"<<endl;
        }
        void SetWorkExp()
        {
            cout<<"A's Work Experience"<<endl;
        }
};
class ResumeB:public Resume
{
    protected:
        void SetPersonalInfo()
        {
            cout<<"B's PersonalInfo"<<endl;
        }
        void SetEducation()
        {
            cout<<"B's Education"<<endl;
        }
        void SetWorkExp()
        {
            cout<<"B's Work Experience"<<endl;
        }
};
int main()
{
    Resume *r1;
    r1 = new ResumeA();
    r1->FillResume();
    delete r1;
    r1 = new ResumeB();
    r1->FillResume();
    delete r1;
    r1 = NULL;
    return 0;
}
