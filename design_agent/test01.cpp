#include<iostream>
#include<string>
using namespace std;
//agent 模式
class Image
{
    protected:
        string m_imageName;
    public:
        Image(string name):
            m_imageName(name){}
        virtual ~Image(){}
        virtual void Show(){}
};
class BigImage:public Image
{
    public:
        BigImage(string name):
            Image(name){}
        ~BigImage(){}
        void Show()
        {
            cout<<"Show bog image:"<<m_imageName<<endl;
        }
};
class BigImageProxy:public Image
{
    private:
        BigImage *m_bigImage;
    public:
        BigImageProxy(string name):Image(name),m_bigImage(0){}
        ~BigImageProxy(){delete m_bigImage;}
        void Show()
        {
            if(m_bigImage == NULL)
            {
                m_bigImage = new BigImage(m_imageName);
            }
            m_bigImage->Show();
        }
};
int main()
{
    Image * image = new BigImageProxy("proxy.jpg");
    image->Show();
    delete image;
    return 0;
}
