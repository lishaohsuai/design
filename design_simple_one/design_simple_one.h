#ifndef _DESIGN_SIMPLE_ONE_
#define _DESIGN_SIMPLE_ONE_
#include <iostream>
#include <string>
using namespace std;
// this file is about how to 
// realize the simple design mode
class Chart{
private: 
    string type;

public:
    Chart(string cc="line"):type(cc){}
    void establish_chart(void);
    void display(void);
};

#endif