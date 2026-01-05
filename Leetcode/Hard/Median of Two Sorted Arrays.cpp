class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int start = 0;
        int end = size1;
        while (start <= end) {
            int part1 = (start + end) / 2;
            int part2 = (size1 + size2 + 1) / 2 - part1;
            
            int left1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int right1 = (part1 == size1) ? INT_MAX : nums1[part1];
            
            int left2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int right2 = (part2 == size2) ? INT_MAX : nums2[part2];
            
            if (left1 <= right2 && left2 <= right1) {
                if ((size1 + size2) % 2 == 0) {
                    return ((double)max(left1, left2) + min(right1, right2)) / 2;
                } else {
                    return (double)max(left1, left2);
                }
            } else if (left1 > right2) {
                end = part1 - 1;
            } else {
                start = part1 + 1;
            }
        }
        return -1;
    }
};
