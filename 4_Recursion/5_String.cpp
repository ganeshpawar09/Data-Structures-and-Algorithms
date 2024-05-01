// #include<bits/stdc++.h>
// using namespace std; 

// void reverse(string &s,int length ,int start=0)
// {
//     if(start>length)
//         return;
//     swap(s[start],s[length-1]);
//     reverse(s, length-1,start+1);
// }

// bool chech_Palindrome(string s,int length, int start=0)
// {
//     if(start>length)
//         return 1;
//     if(s[start]!=s[length-1])
//         return 0;
//     else
//         return chech_Palindrome(s,length-1,start+1);
// }

// // long long int a_b(int a,int b)
// // {
// //     if(b==0)
// //         return 1;
// //     return a*(a_b(a,b-1));
// // }
// //***************   optimize
// long long int a_b(int a,int b)
// {
//     if(b==0)
//         return 1;
//     if(b==1)
//         return a;
//     int ans=a_b(a,b/2);
//     if(b%2==0)
//         return ans*ans;
//     else
//         return a*ans*ans;
// }

// int main()
// {
//     string s="aabbaa";
//     // reverse(s,s.length());
//     // cout<<s<<endl;
//     // cout<<chech_Palindrome(s,s.length())<<endl;
//     cout<<a_b(3,121);
//     return 0;
// }



