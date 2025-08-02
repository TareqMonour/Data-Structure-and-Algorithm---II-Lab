#include<bits/stdc++.h>
using namespace std;

bool firstCall=false;
int countDigit(int n)
{
    if(n==0)
    {
        if(firstCall==false)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(firstCall==false)
    {
        firstCall=true;
    }

    int remDigit=n/10;

    int count=1+countDigit(remDigit);
    return count;
}

int main()
{
    int x= countDigit(12350);
    cout<<"The Counted Digit is: "<<x;
}



