#include<iostream>
using namespace std;
//外观模式应该是用的很多的一种模式，特别是当一个系统很复杂时，系统提供给客户的是一个简单的对外接口，
//而把里面复杂的结构都封装了起来。客户只需使用这些简单接口就能使用这个系统，而不需要关注内部复杂的结构。
class Scanner
{
    public:
        void Scan()
        {
            cout<<"词法分析"<<endl;
        }
};
class Parser
{
    public:
        void Parse()
        {
            cout<<"语法分析"<<endl;
        }
};
class GenMidCode
{
    public:
        void GenCode()
        {
            cout<<"产生中间代码"<<endl;
        }
};
class GenMachineCode
{
    public:
        void GenCode()
        {
            cout<<"产生机器码"<<endl;
        }
};
class Compiler
{
    public:
        void Run()
        {
            Scanner scanner;
            Parser parser;
            GenMidCode genMidCode;
            GenMachineCode genMacCode;
            scanner.Scan();
            parser.Parse();
            genMidCode.GenCode();
            genMidCode.GenCode();
        }
};

int main()
{
    Compiler compiler;
    compiler.Run();
    return 0;
}
