class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i=0, j=0, k=-1;
        vector<int> v;
        while(i<n1 && j<n2){
                if(nums1[i]<=nums2[j]) v.push_back(nums1[i++]);
                else v.push_back(nums2[j++]);
        }
        while(i<n1) v.push_back(nums1[i++]);
        while(j<n2) v.push_back(nums2[j++]);
        int n = n1+n2;
        if(n%2 ==1) return v[n/2];
        else return (v[n/2]+v[n/2 -1])/2.0;

    }
};