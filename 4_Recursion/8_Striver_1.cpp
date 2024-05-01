#include<iostream>
using namespace std; 
// Print name n times;

void printname(int n, int index=0)
{
    if(index==n)
        return;
    
    cout<<"ganesh"<<endl;
    printname( n,index+1);
}
// ***********************Normal way
// void print_1toN(int i,int n)
// {
//     if(i>n)
//         return;
//     cout<<i<<endl;
//     print_1toN(i+1,n);
// }
// void print_Nto1(int i,int n)
// {
//     if(i<1)
//         return;
//     cout<<i<<endl;
//     print_Nto1(i-1,n);
// }
void print_1toN(int i,int n)
{
    if(i<1)
        return;
    print_1toN(i-1,n);
    cout<<i<<endl;

}


void print_Nto1(int i,int n)
{
    if(i>n)
        return;
    print_Nto1(i+1,n);
    cout<<i<<endl;

}

int main()
{
    printname(4);
    print_1toN(4,4);
    print_Nto1(1,4);
    return 0;
}