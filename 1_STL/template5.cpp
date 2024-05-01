// member function template and overloading template

#include<iostream>
using namespace std; 

template <class t>
class g{
    public:
    t data;
    g(t a){
        data =a;
    }
    void display();
};

template <class t>
void g<t>::display(){
    cout<<data<<endl;
};

template <class t>
void func(t n){
    cout<<"This is template :"<<n<<endl;
};

void func(int n){
    cout<<"This is fun1 :"<<n<<endl;
};


int main()
{
    g<int> ganesh(544);
    ganesh.display();
    func(332);
    func(560.34);
    
    return 0;
}