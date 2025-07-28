//recursive and backtracking solution very basic
//thing to keep in mind is that the bitwise or operator is forever increasing and won't decrease with anynumber so the 
//maximum answer would be the whole number itself
code 
{
    class Solution {
public:
    int recursion(vector<int>& nums, int index, int currsum, int maxi) {
        if(index == nums.size()){
            return currsum == maxi ? 1 : 0;
        }

        // Include nums[index]
        int include = recursion(nums, index + 1, currsum | nums[index], maxi);
        
        // Exclude nums[index]
        int exclude = recursion(nums, index + 1, currsum, maxi);

        return include + exclude;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maximum = 0;
        for(int i = 0; i < nums.size(); i++){
            maximum |= nums[i];
        }

        return recursion(nums, 0, 0, maximum);
    }
};

}