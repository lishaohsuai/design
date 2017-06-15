#include <iostream>
using namespace std;
//桥接模式
class OS
{
    public:
        virtual void InstallOS_Imp(){}
};
class WindowOS:public OS
{
    public:
        void InstallOS_Imp()
        {
            cout<<"安装Window操作系统"<<endl;
        }
};
class LinuxOS:public OS
{
    public:
        void InstallOS_Imp()
        {
            cout<<"安装Linux操作系统"<<endl;
        }
};
class UnixOS:public OS
{
    public:
        void InstallOS_Imp()
        {
            cout<<"安装Unix操作系统"<<endl;
        }
};
//计算机
class Computer
{
    public:
        virtual void InstallOS(OS *os){}
};
class DellCom:public Computer
{
    void InstallOS(OS *os)
    {
        os->InstallOS_Imp();
    }
};
class AppleCom:public Computer
{
    public:
        void InstallOS(OS *os)
        {
            os->InstallOS_Imp();
        }
};
class HPCom:public Computer
{
    public:
        void InstallOS(OS *os)
        {
            os->InstallOS_Imp();
        }
};
int main()
{
    OS *os1 = new WindowOS();
    OS *os2 = new LinuxOS();
    Computer *computer1 = new AppleCom();
    computer1->InstallOS(os1);
    computer1->InstallOS(os2);
}
