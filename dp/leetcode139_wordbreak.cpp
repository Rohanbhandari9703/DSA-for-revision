https://leetcode.com/problems/word-break/?envType=study-plan-v2&envId=dynamic-programming

//solution 
🧠 Word Break — Revision Notes
🔹 Problem Summary

Given:

A string s

A dictionary wordDict

Return true if s can be segmented into one or more dictionary words.

🔹 Key Insight

This is a DP on string index problem.

At every index, we ask:

“Can the remaining suffix be broken into valid words?”

🔹 State Definition (MOST IMPORTANT)
Common State
State represents: can substring starting at index i be segmented?

🟦 Bottom-Up DP (Iterative)
🔹 DP Definition
dp[i] = true if s[0 ... i-1] can be segmented


dp[0] = true → empty string is valid

🔹 Transition

For each i:

dp[i] = true if ∃ j < i such that:
    dp[j] == true
    AND s[j ... i-1] ∈ dictionary

🔹 Algorithm Steps

Convert wordDict → unordered_set (O(1) lookup)

Initialize dp[0] = true

Loop i = 1 → n

Try all j < i

If condition matches → break early

🔹 Code (Bottom-Up)
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

🔹 Complexity

Time: O(n²)

Space: O(n)

🔹 When to Use Bottom-Up?

✔ Easy to visualize
✔ No recursion stack
✔ Preferred when interviewer wants tabulation

🟩 Top-Down DP (Recursion + Memo)
🔹 Recursive Definition
solve(i) = true if s[i ... n-1] can be segmented

🔹 Base Case
if i == n → true

🔹 Recursive Case

Try all substrings starting at i:

if s[i ... j] ∈ dict AND solve(j+1) == true

🔹 Memoization
memo[i] = -1 → unvisited
memo[i] = 0  → false
memo[i] = 1  → true

🔹 Code (Top-Down)
class Solution {
public:
    unordered_set<string> dict;
    vector<int> memo;

    bool solve(int idx, string &s) {
        if (idx == s.size()) return true;
        if (memo[idx] != -1) return memo[idx];

        for (int end = idx + 1; end <= s.size(); end++) {
            if (dict.count(s.substr(idx, end - idx)) &&
                solve(end, s)) {
                return memo[idx] = 1;
            }
        }
        return memo[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.assign(s.size(), -1);
        return solve(0, s);
    }
};

🔹 Complexity

Time: O(n²)

Space: O(n) (memo + recursion stack)

🔹 When to Use Top-Down?

✔ Natural recursion thinking
✔ Easy to explain DFS logic
✔ Good when interviewer asks for recursion