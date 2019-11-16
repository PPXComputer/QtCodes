#include <iostream>
#include<string>
#include<algorithm>
using namespace std;



int main()
{
    string str;
    cin>>str;
    cout<<str.size()<<endl;
    for(auto &sd:str){
        cout<<sd;
    }
    reverse(str.begin(),str.end());
    for(auto &sd:str){
        cout<<sd;
    }

    return 0;
}
