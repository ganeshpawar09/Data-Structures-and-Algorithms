// class with default parameters

#include<iostream>
using namespace std; 

template<class t1=int  ,class t2=float>
class g{
    public:
    t1 a;
    t2 b;
    g(t1 x, t2 y)
    {
        a=x;
        b=y;
    }
    void display(){
        cout<<a<<endl;
        cout<<b<<endl;
    }
};
int main()
{
    g<> ganesh(545.24,544);
    ganesh.display();
    cout<<endl<<endl;
    g<float ,float>atharva(433.24,3.24);
    atharva.display();
    
    return 0;
}