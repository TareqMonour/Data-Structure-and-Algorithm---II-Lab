#include<bits/stdc++.h>
using namespace std;
bool p[101];

void printThePrimeNumbersArray(int n)
{
    cout<<"*********************"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl<<"********************"<<endl;
}

void sieveOfEratosthenes(int n)
{
    for(int i=2; i<=n; i++)
    {
        p[i]=true;
    }
    for(int i=2; i<=sqrt(n); i++)
    {
        if(p[i]==true)
        {
            int j=2;
            int index= i*j;
            while(index<=n)
            {
                p[index]=false;
                j++;
                index=i*j;
            }
        }
    }
}
int countPrimeNumbers(int A[], int start, int end)
{
    if(start==end)
    {
        int number=A[start];
        if(p[number]==true)
        {
            return 1;
        }
        else return 0;
    }

    int mid=(start+end)/2;
    int C1=countPrimeNumbers(A, start, mid);
    int C2=countPrimeNumbers(A, mid+1, end);
    return C1+C2;
}

int main()
{
    int A[]= {2,1,3,5,2,2,8,7};
    int start=0;
    int size=sizeof(A)/sizeof(A[0]);
    sieveOfEratosthenes(50);
    int result=countPrimeNumbers(A, start, size-1);
    cout<<"No of Prime Number is : "<<result<<endl;

    return 0;
}
