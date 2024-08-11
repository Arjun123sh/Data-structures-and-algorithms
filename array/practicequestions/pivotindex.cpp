#include<iostream>
#include<vector>
using namespace std;

int pivotIndex1(vector<int>&nums){
    int sum = 0, leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int left=0;
        int right=0;
        for(int j=0;j<i;j++){
            left+=nums[j];
        }
        for(int k=i+1;k<nums.size();k++){
            right+=nums[k];
        }
        if(left==right){
            return i;
        }
    }
    return -1;
}

int pivotIndex2(vector<int>&nums,int size){
    vector<int>left(size,0);
    vector<int>right(size,0);
    for(int i=1;i<size;i++){
        left[i]=left[i-1]+nums[i-1];
    }
    for(int j=size-2;j>=0;j--){
        right[j]=right[j+1]+nums[j+1];
    }

    for(int k=0;k<size;k++){
        if(left[k]==right[k]){
            return k;
        }
    }
    return -1;
}