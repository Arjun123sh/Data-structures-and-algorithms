#include <vector> 
using namespace std;

class Solution {
public:
    int getPivotIndex(vector<int>& arr) {
        int s = 0;  
        int n = arr.size();  
        int e = n - 1;  
        int mid = s + (e - s) / 2;  

        while(s <= e) {
            if(s == e) {
                return s;  // Pivot found when start equals end
            }
            if(mid + 1 < n && arr[mid] > arr[mid + 1]) {
                return mid;  // Pivot found when current element is greater than next element
            }
            // Deciding whether to search in the left half or right half
            if(arr[s] > arr[mid]) {
                e = mid - 1;  // Search in the left half
            }
            else {
                s = mid + 1;  // Search in the right half
            }
            mid = s + (e - s) / 2;  
        }
        return -1;  
    }

    int binarySearch(int s, int e, int target, vector<int>& arr) {
        int mid = s + (e - s) / 2; 
        while(s <= e) {
            if(arr[mid] == target) {
                return mid;  
            }
            if(target > arr[mid]) {
                s = mid + 1;  // Search in the right half
            }
            else {
                e = mid - 1;  // Search in the left half
            }
            mid = s + (e - s) / 2;  
        }
        return -1;  
    }

    // Main function to search the target in the rotated sorted array
    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);

        int n = nums.size();
        if(target >= nums[0] && target <= nums[pivotIndex]) {

            int ans = binarySearch(0, pivotIndex, target, nums);
            return ans;
        }
        else {
            // Target lies in the second part of the array (line B)
            int ans = binarySearch(pivotIndex + 1, n - 1, target, nums);
            return ans;
        }
        return -1;  // Return -1 if target is not found
    }
};
