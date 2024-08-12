#include<iostream>
#include<vector>

using namespace std;

// negative marking method

// nums[i] belongs [1,4]

// nums[nums[i]] -> mark visited (-ve)

// take absolute value 

int findDuplicate(vector<int>&nums){
    int ans=-1;
    for(int i=0;i<nums.size();i++){
        int index = abs(nums[i]);
        if(nums[index]<0){
            return index;
        }
        nums[index] = -nums[index];
    }
    return ans;
}