// 🔑 What “canonical form” means here

// A canonical form is:

// A unique, normalized representation such that
// all equivalent strings map to the same form.

// In your problem:

// Strings are equivalent if all characters have the same cyclic difference

// So we want a representation independent of the starting letter

// ✅ Your method (Shift first character to 'a')
// Technique used
// sh = s[0] - 'a';
// ch = (ch - 'a' - sh + 26) % 26 + 'a';
question:- https://leetcode.com/problems/count-caesar-cipher-pairs/description/

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> mpp;
        for(string s : words){
            int sh = s[0] - 'a'; // for example fusion:-
            //f-a = 5
            //u-a = 20 
            //s-a = 18
            //i-a = 8
            //o-a = 14
            //n-a = 19

            for(char& ch : s){
                ch = (ch - 'a' - sh + 26) % 26 + 'a'; //
            }
            // (ch - 'a' - sh + 26) % 26 + 'a'

            mpp[s]++;
        }

        long long result = 0;
        for(auto it : mpp){
            long long cnt = it.second;
            result += ((cnt * (cnt-1))/2);
        }

        return result;
    }
};