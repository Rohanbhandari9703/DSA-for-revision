leetcode 560. Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
//solved using prefix sum and hashmap, prefix sum to find the sum till that point 
//then used hashmap to convert this to a 2 sum approach smthing ..
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>prefix(n);
           int ans = 0;
        prefix[0]= nums[0];
        if(prefix[0] == k){
            ans++;
        }
     
        for(int i =1 ; i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
           if(prefix[i] == k) ans++;
        }
        for(int i = 0 ; i<n;i++){
            int key = prefix[i];
            int tofind = key - k;
            if(mp.find(tofind)!=mp.end()){
                ans+= mp[tofind];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};