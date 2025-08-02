
#include<iostream>
#include<math.h>
using namespace std;

bool P[101];

void printThePrimeNumberArray(int n){
    cout<<"*************************"<<endl;
    for(int i=1;i<=n;i++){
        cout<<P[i]<<" ";
    }
    cout<<endl<<"*************************"<<endl;
}

void sieveOfEratosthenes(int n){
    // mark all the numbers as prime except 1
    for(int i=2;i<=n;i++){
        P[i]=true;
    }
    // for i =2 to sqrt (n)
    for(int i=2;i<=sqrt(n);i++){
        // checking if the number is true
        if(P[i]==true){
            // setting all the multiples of P[i] as False
            int j=2;
            int index= i*j;
            while(index<=n){
                P[index]=false;
                j++;
                index=i*j;
            }
        }
    }

    //printThePrimeNumberArray(n);
}

int countPrimeNumbers(int A[], int start, int end){
    if(start==end){
        int number=A[start];
        if(P[number]==true){
            return 1;
        }else{
            return 0;
        }
    }
    int mid = (start+end)/2;

    int count1 = countPrimeNumbers(A, start,mid);
    int count2 = countPrimeNumbers(A, mid+1,end);

    return count1+count2;
}

int findMax(int arr[], int n) {
    if (n <= 0) {
        // Handle edge case of empty array or negative size
        return INT_MIN; // Return smallest possible integer
    }

    int maxElement = arr[0]; // Assume first element is the maximum

    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Update maxElement if a larger element is found
        }
    }

    return maxElement;
}

int main(){
    int A [] = {2,5,4,10,2,2,1,2,7,9,3};
    int start = 0;
    int end = 10;
    //int size=sizeof(A)/sizeof(A[0]);
    int maxElement = findMax(A, 10);
    sieveOfEratosthenes(maxElement);
    int result = countPrimeNumbers(A,start,10);
    cout<<"Total number of prime numbers = "<<result<<endl;
    return 0;
}

