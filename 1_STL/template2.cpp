//class template with multiple parameters(class one,class two,...)
#include<iostream>
using namespace std; 

template<class T1, class T2>

class myclass{
    public: 
    T1 data;
    T2 data1;
    myclass(T1 a, T2 b)
    {
        data =a;
        data1=b;
    }
    void display(){
        cout<<data<<endl<<data1<<endl;
    }
};
int main()
{
    myclass<int,float>a(34,544.322);
    a.display();
    myclass<char,int>b('c',3452);
    b.display();
    
    return 0;
}