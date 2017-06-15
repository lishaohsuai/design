#include <iostream>
using namespace std;
//智能指针
template<class T>
class auto_ptr
{
    public:
        explicit auto_ptr(T *p = 0):pointee(p){}
        auto_ptr(auto_ptr<T>& rhs):pointee(rhs.release()){}
        ~auto_ptr(){delete pointee;}
        auto_ptr<T> & operator=(auto_ptr<T>&rhs)
        {
            if(this != &rhs)reset(rhs.release());
            return *this;
        }
        T &operator*const(){return *pointee;}
        T* operator->() const{return pointee;}
        T*get() const {return pointee;}
        T* release()
        {
            T *oldPointee = pointee;
            pointee = 0;
            return oldPointee;
        }
        void reset(T *p = 0)
        {
            if(pointee != p)
            {
                delete pointee;
                pointee = p;
            }
        }
    private:
        T *pointee;
};
int main()
{
    
}
