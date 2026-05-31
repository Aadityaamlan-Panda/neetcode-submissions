class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int m = nums1.size(), n = nums2.size();
        int l=0, r=m;

        int totleft = (m+n+1)/2;

        while(l<=r){
            int i = (l+r)/2;
            int j = totleft-i;

            int l1 = (i==0)?INT_MIN:nums1[i-1];
            int r1 = (i==m)?INT_MAX:nums1[i];

            int l2 = (j==0)?INT_MIN:nums2[j-1];
            int r2 = (j==n)?INT_MAX:nums2[j];

            if (l1<=r2 && l2<=r1){
                if ((m+n)%2) return max(l1,l2);
                else return(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if (l1>r2) r = i-1;
            else l=i+1;
        }
        return 0;
    }
};
