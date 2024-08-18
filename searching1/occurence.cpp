#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findFirstOccurrence(vector<int>& arr, int n, int target, int& ansIndex) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (arr[mid] == target) {
                // ans found -> may or may not be first occurrence
                // store and compute
                ansIndex = mid;
                // left me jao
                e = mid - 1;
            } else if (target > arr[mid]) {
                // right me jao
                s = mid + 1;
            } else {
                // left me jao
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
    }

    void findLastOccurrence(vector<int>& arr, int n, int target, int& ansIndex) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (arr[mid] == target) {
                // target k equal toh hai but may or may not be last occurrence
                // store and compute
                ansIndex = mid;
                // right me jao
                s = mid + 1;
            } else if (target > arr[mid]) {
                // right me jao
                s = mid + 1;
            } else {
                // left me jao
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int firstOccIndex = -1;
        findFirstOccurrence(arr, n, target, firstOccIndex);

        int lastOccIndex = -1;
        findLastOccurrence(arr, n, target, lastOccIndex);

        vector<int> temp(2);
        temp[0] = firstOccIndex;
        temp[1] = lastOccIndex;
        return temp;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(arr, target);
    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}
