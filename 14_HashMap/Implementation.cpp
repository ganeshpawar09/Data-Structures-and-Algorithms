// hashmap use in unordered map to get log(1) time complexity
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // unordered_map<string, int> m;
    // pair<string, int> s("Ganesh", 5);
    // pair<string, int> k("atharva", 6);
    // m.insert(s);
    // m.insert(k);

    // cout << m["Ganesh"] << endl;
    // cout << m.at("Ganesh") << endl;

    // // cout << m.at("Gaesh") << endl; //this line will give error if key is not present
    // cout << m["Gaesh"] << endl; // but this line will creat an new entry at 0th index
    // cout << m["Gaesh"] << endl;

    // cout << m.size() << endl;
    // cout << m.count("Ganesh") << endl;
    // cout << m.bucket_count() << endl;

    // for (auto i : m)
    // {
    //     cout << i.first << "  " << i.second << endl;
    // }

    // unordered_map<string, int>::iterator it = m.begin();
    // while (it != m.end())
    // {
    //     cout << it->first << "  " << it->second << endl;
    //     it++;
    // }
    unordered_map<int,int>m;
    m[20]=1;
    cout<<m[20]<<endl;
    cout<<m[2]<<endl;
    return 0;
}