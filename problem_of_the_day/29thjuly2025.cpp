//very good bit manipulation question , not so intuative but very good for revision and trying again
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        
        vector<int> setBitIndex(32, -1);
  

        for(int i = n-1; i >= 0; i--) {

            int endIndex = i;
            for(int j = 0; j < 32; j++) {
                if(!(nums[i] & (1 << j))) { 
                    if(setBitIndex[j] != -1) {
                        endIndex = max(endIndex, setBitIndex[j]);
                    }
                } else {
                    setBitIndex[j] = i;
                }
            }

            result[i] = endIndex - i + 1;
        }

        return result;

    }
};
//code ,
//main point was storing the value in 32 size bit where the index occurs the last