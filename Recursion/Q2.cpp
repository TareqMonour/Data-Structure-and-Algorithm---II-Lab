#include<bits/stdc++.h>
using namespace std;

int sumNumber(int n)
{
    if(n==0)
    {
        return 0;
    }
    int sum=n+sumNumber(n-1);
       return sum;
}

int main(){
int x= sumNumber(10);
cout<<"The sum of Numbers is: "<<x;
}

