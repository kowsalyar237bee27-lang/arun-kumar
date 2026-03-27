
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    if(!(cin>>a>>b>>c))return 0;
    if(a>0 &&b>0 &&c>0&& (a+b+c==180))
    {
        if(a==60 &&b==60&& c==60){
            cout<<"prize 3"<<endl;
            }
            else if(a==90 || b==90 || c==90)
            {
                cout<<"prize 2"<<endl;
            }
                else
                {
                    cout<<"prize 1"<<endl;
                }
            }
                else
                {
                    cout<<"no prize"<<endl;
                }
                return 0;
    }
