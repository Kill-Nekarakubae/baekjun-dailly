#include<algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int even = ((nums1.size() + nums2.size())%2 == 0);
        int m1,m2;
        if (even) { // 짝수
            m1 = (nums1.size() + nums2.size()) / 2 - 1;
            m2 = m1+1;
        } else{ // 홀수
            m1 = (nums1.size() + nums2.size()) / 2 ;
            m2 = m1;
        }

        int i=0,j=0;
        int node1 ,node2;
        while (i+j <= m2) {
            int now;
            if (i>=nums1.size()) {
                now = nums2[j];
                j++;
            }
            else if (j>=nums2.size()) {
                now = nums1[i];
                i++;
            }
            else if (nums1[i] < nums2[j]) {
                now = nums1[i];
                i++;
            }
            else {
                now = nums2[j];
                j++;
            }
            // cout<<now<<endl;

            if (i+j-1 == m1) node1 = now;
            if (i+j-1 == m2) node2 = now;
        }

        return ((double)(node1 + node2))/2;
    }
};