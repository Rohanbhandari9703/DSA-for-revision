//good question checks the fundamental use of the and operator , was able to come up with the solution and a intuitive aproach as well

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxel = *max_element(nums.begin(), nums.end());
        int maxcount = 0, count = 0;

        for (int num : nums) {
            if (num == maxel) {
                count++;
                maxcount = max(maxcount, count);
            } else {
                count = 0;
            }
        }

        return maxcount;
    }
};
