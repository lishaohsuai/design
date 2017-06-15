#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
class Resume
{
    protected:
        char *name;
    public:
            Resume(){}
            virtual ~Resume(){}
            virtual Resume*Clone()
            {
                return NULL;
            }
            virtual void Set(char *n){}
            virtual void Show(){}
};
    class ResumeA : public Resume
    {
        public:
            ResumeA(const char*str);
            ResumeA(const ResumeA &r);
            ~ResumeA();
            ResumeA*Clone();
            void Show();
    };
    ResumeA::ResumeA(const char *str)
    {
        if(str == NULL)
        {
            name = new char[1];
            name[0] = '\0';
        }
        else
        {
            name = new char[strlen(str)+1];
            strcpy(name, str);
        }
    }
    ResumeA::~ResumeA()
    {
        delete[]name;
    }
    ResumeA::ResumeA(const ResumeA &r)
    {
        name = new char[strlen(r.name)+1];
        strcpy(name, r.name);
    }
    ResumeA* ResumeA::Clone()
    {
        return new ResumeA(*this);
    }
    void ResumeA::Show()
    {
        cout<<"ResumeA name :"<<name<<endl;
    }
    // B
    class ResumeB : public Resume
    {
        public:
            ResumeB(const char*str);
            ResumeB(const ResumeB &r);
            ~ResumeB();
            ResumeB*Clone();
            void Show();
    };
    ResumeB::ResumeB(const char *str)
    {
        if(str == NULL)
        {
            name = new char[1];
            name[0] = '\0';
        }
        else
        {
            name = new char[strlen(str)+1];
            strcpy(name, str);
        }
    }
    ResumeB::~ResumeB()
    {
        delete[]name;
    }
    ResumeB::ResumeB(const ResumeB &r)
    {
        name = new char[strlen(r.name)+1];
        strcpy(name, r.name);
    }
ResumeB* ResumeB::Clone()
{
    return new ResumeB(*this);
}
void ResumeB::Show()
{
    cout<<"ResumeA name :"<<name<<endl;
}
int main()
{
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->Clone();
    Resume *r4 = r2->Clone();
    r1->Show();
    r2->Show();
    delete r1;
    delete r2;
    r1 = r2 = NULL;
    r3-> Show();
    r4->Show();
    delete r3;
    delete r4;
    r3 = r4 = NULL;
}
