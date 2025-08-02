#include<bits/stdc++.h>
using namespace std;

int sumDigit(int n)
{
    if(n==0)
    {
        return 0;
    }
    int lastDigit=n%10;
    int remDigit=n/10;

    int sum=lastDigit+sumDigit(remDigit);
       return sum;
}

int main(){
int x= sumDigit(112435);
cout<<"The sum of Digit is: "<<x;
}


