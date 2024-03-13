class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        const int n = nums.size();
        std::unordered_map<unsigned int, bool> numsSpotted;
        unsigned int missing = 1;
        size_t i = 0;
        while (i < n) {
            int number = nums[i++];
            if (number > 0) numsSpotted[number] = true;
        }
        while(numsSpotted.count(missing++) != 0);
        return --missing;
    }
};
