#include<iostream>
#include<vector>

using namespace std;

// find all subarray sum of length k

// brute force
// double findMaxAverage(vector<int>&nums,int &k){
//     int maxSum=INT_MIN;
//     int i=0,j=k-1;
//     while(j<nums.size()){
//         int sum=0;
//         for(int p=i;p<=j;p++){
//             sum+=nums[p];
//         }
//         maxSum=max(maxSum,sum);
//         i++;
//         j++;
//     }
//     return (double)maxSum/k;
// }


// sliding window

double findMaxAverage(vector<int>&nums,int k){
    int i=0;
    int j=k-1;
    int sum=0;
    for(int y=i;y<=j;y++){
        sum+=nums[y];
    }
    int maxSum=sum;
    j++;
    while(j<nums.size()){
        sum-=nums[i++];
        sum+=nums[j++];
        maxSum=max(maxSum,sum);
    }
    return (double)maxSum/k;
}

