#include<bits/stdc++.h>>
using namespace std;

int countEven(int A[], int i, int j)
{
    if(i==j)
    {
        if(A[i]%2==0)
        {
            return 1;
        }
            else return 0;
    }else
    {
        int mid=(i+j)/2;

        int Count1=countEven(A, i, mid);
        int Count2=countEven(A, mid+1, j);

        return Count1+Count2;

    }
}

int main()
{
//    int A[] = {6, 11, 4, 5, 8, 2};
//    int N = sizeof(A)/sizeof(A[0]);
//    cout << countEven(A, 0, N-1);

    int A[]={4,5,2,4,8,6,9,3};
    int N=sizeof(A)/sizeof(A[0]);
    cout<<"Counted Even Numbers: "<<countEven(A, 0, N-1)<<endl;

}
