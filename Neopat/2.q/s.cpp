
#include<iostream>
using namespace std;
int main()
{
    int coins;
    char red;
    if(!(cin>>coins>>red))return 0;
    if(coins<1 || coins>9)
    {
        cout<<"invalid input";
    }
    else
    {
        int score=coins;
        if(red=='y')
        {
            score +=5;
        }
        cout<<score;
    }
    return 0;
}
