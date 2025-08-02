#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    int fact=n*factorial(n-1);
       return fact;
}

int main(){
int x= factorial(5);
cout<<"The Factorial is: "<<x;
}

