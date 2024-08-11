#include<iostream>

#include<algorithm>
using namespace std;
bool keypair(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i] + arr[j])==target){
                return true;
            }
        }
    }

    return false;
}

int twoSumWith2pointerapproach(int arr[],int n,int x){
    int i=0;
    int j=n-1;
    while(i<j){
        int csum= arr[i]+arr[j];
        if(csum==x){
            return true;
        }
        else if(csum>x){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}





