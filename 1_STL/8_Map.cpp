// map

#include<iostream>
#include<map>
#include<string.h>
using namespace std; 

int main()
{
    map<string, int>marksmap;
    marksmap["ganesh"] =99;
    marksmap["yash"]=50;

    marksmap.insert({{"Atharva",54},{"Om",66}});


    map<string,int>::iterator itr;
    for (itr=marksmap.begin(); itr!=marksmap.end(); itr++)
    {
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }

    cout<<marksmap.size();
    
    
    return 0;
}