#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


int findLeftmost(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int first_pos = -1; 

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (nums[mid] == target) {
            first_pos = mid;     
            right = mid - 1;      
        } else if (nums[mid] < target) {
            left = mid + 1;       
        } else { 
            right = mid - 1;   
        }
    }
    return first_pos;
}


int findRightmost(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int last_pos = -1; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            last_pos = mid;      
            left = mid + 1;      
        } else if (nums[mid] < target) {
            left = mid + 1;      
        } else { 
            right = mid - 1;      
        }
    }
    return last_pos;
}


vector<int> searchRange(const vector<int>& nums, int target) {
    int first = findLeftmost(nums, target);
    int last = findRightmost(nums, target);
    return {first, last};
}

int main() {
    cout << "--- Problem 1: Find First and Last Position ---" << endl;

    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = searchRange(nums1, target1);
    cout << "nums = [5,7,7,8,8,10], target = 8 -> [" << result1[0] << ", " << result1[1] << "]" << endl; 

    

    return 0;
}