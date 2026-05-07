class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1;
        int i=0, j=0, count=0, x=0, y=0, n1=nums1.size(), n2=nums2.size();
        while(count<=(n1+n2)/2)
        {
            count++;
            y=x;
            if(j==nums2.size() || (i<nums1.size() && (nums1[i]<nums2[j])))
            {
                x=nums1[i];
                i++;
            }
            else
            {
                x=nums2[j];
                j++;
            }
        }
        if((n1+n2)%2==0)
            return double(x+y)/2;
        return double(x);
    }
};