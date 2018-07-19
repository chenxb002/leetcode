class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      set<vector<int>> res;
      if (nums.size() < 4) return vector<vector<int>>();
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size() - 3; ++i) {
          for (int j = i + 1; j < nums.size() - 2; ++j) {
              int m = j + 1, n = nums.size() - 1;
              while (m < n) {
                  int sum = nums[i] + nums[j] + nums[m] + nums[n];
                  if (sum == target) {
                      res.insert({nums[i], nums[j], nums[m], nums[n]});
                      if (m < n && nums[m] == nums[m + 1]) ++m;
                      if (m < n && nums[n] == nums[n - 1]) --n;
                      ++m, --n;
                  } else if (sum > target) {
                      --n;
                  } else {
                      ++m;
                  }   
              }   
          }   
      }   
      return vector<vector<int>>(res.begin(), res.end());
    }   
};
