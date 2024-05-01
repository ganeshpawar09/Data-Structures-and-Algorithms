// list

#include<iostream>
#include<list>
using namespace std; 

template <class t>
void display(list<t> &l)
{
    list<int>::iterator it;
    for (it=l.begin();it!=l.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    
};

int main()
{
    list<int>l1;        //list of 0 length
    l1.push_back(100000);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(10000);
    l1.push_back(10);
    l1.push_back(5);
    l1.push_back(6);
    int a=5;
    l1.push_back(a);

    
    // display(l1);
    // l1.pop_back();
    // display(l1);

    // l1.pop_front();
    // display(l1);

    // l1.remove(5);
    // display(l1);


    // sort the list
    // l1.sort();
    // display(l1);

    // list<int>l2(3);
    // l2.push_back(233);
    // l2.push_back(323);
    // l2.push_back(412);    
    // l2.sort();
    
    list<int>::iterator it=l1.begin();
    advance(it,0);
    cout<<*it<<endl;
    


    // l1.merge(l2);
    // display(l1);



    // // reverse
    // l1.reverse();
    // display(l1);


    



    



    
     
    return 0;
}