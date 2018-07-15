/*
* Reference: https://www.jianshu.com/p/9bd57fd52062
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  double findKth(vector<int>& nums1, vector<int>& nums2, int start1, int len1, int start2, int len2, int k) {
    if (len1 > len2) {
      return findKth(nums2, nums1, start2, len2, start1, len1, k);
    }
    if (len1 == 0) {
      return nums2[start2 + k - 1];
    }
    if (k == 1) {
      return min(nums1[start1], nums2[start2]);
    }

    int p1 = min(k / 2, len1);
    int p2 = k - p1;
    if (nums1[start1 + p1 - 1] > nums2[start2 + p2 - 1]) {
      return findKth(nums1, nums2, start1, len1, start2 + p2, len2 - p2, k - p2);
    } else if (nums1[start1 + p1 - 1] < nums2[start2 + p2 - 1]) {
      return findKth(nums1, nums2, start1 + p1, len1 - p1, start2, len2, k - p1);
    } else {
      return nums1[start1 + p1 - 1];
    }
  }

public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    if (!(len & 1)) {
      return (findKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), len / 2)
              + findKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), len / 2 + 1)) / 2.;
    } else {
      return findKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), len / 2 + 1);
    }
  }
};

int main() {
  return 0;
}
