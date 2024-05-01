// function template & function template with parameters

#include<iostream>
#include<iomanip>
using namespace std; 

template<class t1, class t2>
float avgerage(t1 a,t2 b){
    float avg=(a+b)/2;
    return avg;
}
template <class T>
void swapp(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout<<avgerage(3.0,4)<<endl;
    int x=34,y=54;
    swapp(x,y);
    cout<<x<<endl<<y<<endl;

    
    return 0;
}