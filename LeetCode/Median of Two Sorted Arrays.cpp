class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t totalSize = (nums1.size() + nums2.size())/2 + 1;
        size_t curr1Index = 0, curr2Index = 0;
        int currNum = 0, lastNum = 0;
        for(size_t i = 0; i < totalSize; i++){
            lastNum = currNum;
            if((curr1Index < nums1.size())){
                if(curr2Index < nums2.size()){
                    currNum = (nums1[curr1Index] < nums2[curr2Index]) ? nums1[curr1Index++] : nums2[curr2Index++];
                }else{
                    currNum = nums1[curr1Index++];
                }
            }else{
                currNum = nums2[curr2Index++];
            }
        }
        return ((nums1.size() + nums2.size()) % 2 == 1) ? currNum : static_cast<double>(lastNum + currNum)/2.0;
    }
};