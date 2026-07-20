class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0.0;
        // median = n is odd x (n+1)/2
        //.         n is even x n/2 + x (n/2) + 1
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i = 0, j = 0;
        int median1 = 0, median2 = 0;
        for (int count = 0; count < (size1 + size2) / 2 + 1; count++) {
            median2 = median1;
            if (i < size1 && j < size2) {
                if (nums1[i] < nums2[j]) {
                    median1 = nums1[i];
                    i++;
                } else {
                    median1 = nums2[j];
                    j++;
                }
            } else if (i < size1) { // j out of range
                median1 = nums1[i];
                i++;
            } else {
                median1 = nums2[j];
                j++;
            }
        }
        if ((size1 + size2) % 2 == 1 ) { // is odd
            return (double) median1;
        } else {
            return (double) (median1 + median2) / 2;
        }
    }
};
