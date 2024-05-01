// #include<bits/stdc++.h>
// using namespace std; 
// void reachhome(int s, int d)
// {
//     if (s==d)
//     {
//         cout<<"Pohach gya"<<endl;
//         return ;
//     }
//     cout<<s<<" "<<d<<endl;
//     reachhome(++s,d);
// }

// int main()
// {
//     int dest =10;
//     int src=1;
//     reachhome(src,dest);
//     return 0;
// }


// ******************Fibonacci series

// #include<bits/stdc++.h>
// using namespace std; 

// int fibonacci(int n)
// {
//     if (n==0)
//         return 0;
//     if (n==1)
//         return 1;
//     return fibonacci(n-1)+fibonacci(n-2);
// }

// int main()
// {
//     cout<<fibonacci(6);
//     return 0;
// } 

// ***************************print number 123=> 1 2 3
// #include<bits/stdc++.h>
// using namespace std; 
// void num(int n)
// {
//     if(n==0)
//         return ;
//     int digit=n%10;
//     n/=10;
//     num(n);
//     cout<<digit<<endl;
 
// }

// int main()
// {
//     num(123);
//     return 0;
// }