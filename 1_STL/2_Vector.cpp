// vector

#include<iostream>
#include<vector>
using namespace std; 

template <class t>
void display(vector<t> &v)
{
    cout<<"D"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    // ways to creat vector
    vector<int> vec1;           //zero length integer vector
    vector<char> vec2(4);       //4-element character vector
    vector<char> vec3(vec2);    //4-element character vector from vec2
    vector<int> vec4(6,3);      //6-element vector of 3s


    display(vec1);
    display(vec2);
    display(vec3);
    display(vec4);
    

    
    






    // int element, size;
    // cin>>size;
    // for(int i=0; i<size; i++)
    // {
    //     cout<<"Enter an element to add to this vector :";
    //     cin>>element;
    //     vec1.push_back(element);
    // }
    // display(vec1);
    
    // vec1.pop_back();
    // display(vec1);

    // vector<int>:: iterator iter =vec1.begin();
    // vec1.insert(iter,10000);

    // vec1.insert(iter+4,6,10000);

    // vector<int>::iterator ls= vec1.end();
    // vec1.insert(ls,500);

    // display(vec1);

    
    return 0;
}