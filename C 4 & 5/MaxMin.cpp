#include<bits/stdc++.h>
using namespace std;

struct MaxMinValues{
int max;
int min;
};

struct MaxMinValues MaxMin(int *A, int i, int j){
   if(i==j){
     struct MaxMinValues mnv;
     mnv.max=A[i];
     mnv.min=A[i];
     return mnv;
   }

   int mid=(i+j)/2;
   struct MaxMinValues mnv1= MaxMin(A,i,mid);
   struct MaxMinValues mnv2= MaxMin(A,mid+1,j);

   struct MaxMinValues fmnv;

   if(mnv1.max>=mnv2.max){
    fmnv.max=mnv1.max;
   }
   else fmnv.max=mnv2.max;

   if(mnv1.min<=mnv2.min){
    fmnv.min=mnv1.min;
   }
   else fmnv.min=mnv2.min;

   return fmnv;
}

int main(){
    int A[] = {-10786,20,30,-2,-100,56,12,989,1};
    int length =sizeof(A)/sizeof(A[0]);

    struct MaxMinValues resultmmv = MaxMin(&A[0],0,length-1);

    cout<<"max val in the array "<<resultmmv.max<<endl;
    cout<<"min val in the array "<<resultmmv.min<<endl;
}
