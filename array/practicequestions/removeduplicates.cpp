#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>&nums){
    if(nums.size() == 0) return 0;
    int i=1,j=0;
    while(i<nums.size()){
        if(nums[i] == nums[j]){
            ++i;
        }
        else{
            nums[++j]=nums[i++];
        }
    }
    return j+1;
}