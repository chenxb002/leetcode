#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }

    int binary_search(vector<int>& nums, int lower, int upper, int target) {
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            cout << lower << " " << mid << " " << upper << endl;
            if (target == nums[mid]) { return mid; }
            else if (nums[lower] <= nums[mid]) {
                if (target >= nums[lower] && target < nums[mid]) {
                   upper = mid - 1;
                } else {
                   lower = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[upper]) {
                   lower = mid + 1;
                } else {
                   upper = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
   int a[] = {3, 1};
   vector<int> vc (a, a + 2);
   Solution s;
   s.search(vc, 1);
   return 0;
}
