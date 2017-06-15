#include "design_simple_one.h"
void Chart::establish_chart(void){
    if (this->type == "histogram") {  
            //初始化柱状图 
            cout<<"init histogram"<<endl;
        }  
        else if (this->type == "pie") {  
            //初始化饼状图 
            cout<<"init pip"<<endl; 
        }  
        else if (this->type == "line") {  
            //初始化折线图  
            cout<<"init line"<<endl; 
        }  
}
void Chart::display(void){
    if(this->type == "histogram"){
        cout<<"display histogram"<<endl;
    }
    if(this->type == "pip"){
        cout<<"display pip"<<endl;
    }
    if(this->type == "histogram"){
        cout<<"display histogram"<<endl;
    }
    
}