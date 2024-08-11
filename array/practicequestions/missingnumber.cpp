#include<iostream>
#include<vector>

using namespace std;

int ans(vector<int>nums1){
    int n = nums1.size();
    int sum = 0;
    int sum1 = 0;
    vector<int>arr;
    for(int i = 0; i <= n; i++){
        sum+=i;
    }
    for(int i = 0; i < n; i++){
        sum1+=nums1[i];
    }
    
    return sum-sum1;
}