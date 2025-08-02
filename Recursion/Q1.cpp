#include<bits/stdc++.h>
using namespace std;

void printNumber(int n)
{
    if(n==1)
    {
        cout<<1<<" ";
        return;
    }
    //cout<<n<<" ";//Printing in the rev order
    printNumber(n-1);
    cout<<n<<" ";
}

int main(){
printNumber(10);
}
