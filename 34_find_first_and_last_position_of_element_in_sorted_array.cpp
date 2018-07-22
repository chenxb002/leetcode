#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int i = 0, j = nums.size() - 1;
        int left = -1, right = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (target == nums[mid] && (mid == 0 || target > nums[mid - 1])) {
                left = mid;
                break;
            }
            if (target > nums[mid]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (target == nums[mid] && (mid == nums.size() - 1 || target < nums[mid + 1])) {
                right = mid;
                break;
            }
            if (target >= nums[mid]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        res[0] = left, res[1] = right;
        return res;
    }
};

int main() {
  int a[] = {5, 7, 7, 8, 8, 10};
  vector<int> nums(a, a + 6);
  Solution s;
  vector<int> res = s.searchRange(nums, 8);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
