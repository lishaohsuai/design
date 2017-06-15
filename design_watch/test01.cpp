#include<iostream>
#include<list>
using namespace std;
//观察者
class Observer
{
    public:
    Observer(){}
    virtual ~Observer(){}
    virtual void Update(){}
};
//博客
class Blog
{
    private:
        list<Observer*> m_observers;
    public:
        Blog(){}
        virtual ~Blog(){}
        void Attach(Observer *observer)//添加观察者
        {
            m_observers.push_back(observer);
        }
        void Remove(Observer *observer)//删除观察者
        {
            m_observers.remove(observer);
        }
        void Notify()   //通知观察者
        {
            list<Observer *>::iterator iter = m_observers.begin();
            for(; iter != m_observers.end();iter++)
            {
                (*iter)->Update();
            }
        }
        virtual void SetStatus(string s)//设置状态
        {
            m_status = s;
        }
        virtual string GetStatus()
        {
            return m_status;
        }
    protected:
        string m_status;
};
//具体博客类
class BlogCSDN:public Blog
{
    private:
        string m_name; //博主名字
    public:
        BlogCSDN(string name):m_name(name){}
        ~BlogCSDN(){}
        void SetStatus(string s)
        {
            m_status = "CSDN通知:"+ m_name + s;//具体设置状态信息
        }
        string GetStatus()
        {
            return m_status;
        }
};
//具体观察者
class ObserverBlog:public Observer
{
    private:
        string m_name;//观察者名称
        Blog *m_blog;
    public:
        ObserverBlog(string name, Blog *blog):
            m_name(name),m_blog(blog){}
        ~ObserverBlog(){}
        void Update()//获取更新状态
        {
            string status = m_blog->GetStatus();
            cout<<m_name<<"--------------"<<status<<endl;
        }
};
int main()
{
    Blog *blog = new BlogCSDN("wuzhekai1985");
    Observer *observer1 = new ObserverBlog("tutupig",blog);
    blog->Attach(observer1);
    blog->SetStatus("发表设计模式");
    blog->Notify();
    delete blog; delete observer1;
    return 0;
}
