#include<iostream>
#include<map>
using namespace std; 

int main()
{
    map<int,string> dic;
    dic[1]="g";
    dic[2]="a";
    dic[3]="n";
    dic[4]="e";
    dic[5]="s";
    dic[6]="h";

    dic.insert({6,"j"});

    cout<<dic[1]<<endl;
    return 0;
}