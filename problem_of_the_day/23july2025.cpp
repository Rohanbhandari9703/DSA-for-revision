//problem statement
//Maximum Score From Removing Substrings
//link to the problem
https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

code 
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first = (x >= y) ? "ab" : "ba";
        int firstPoints = max(x, y);
        string second = (x < y) ? "ab" : "ba";
        int secondPoints = min(x, y);

        int totalPoints = 0;
        stack<char> st;
        string temp = "";
        for (char ch : s) {
            if (!st.empty() && st.top() == first[0] && ch == first[1]) {
                st.pop();
                totalPoints += firstPoints;
            } else {
                st.push(ch);
            }
        }

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for (char ch : temp) {
            if (!st.empty() && st.top() == second[0] && ch == second[1]) {
                st.pop();
                totalPoints += secondPoints;
            } else {
                st.push(ch);
            }
        }

        return totalPoints;
    }
};
//using stack
// Greedy Strategy:
// // Always remove the higher-point pair ("ab" or "ba") first to maximize gain.

// // Stack-based String Traversal:
// // Use a stack to efficiently simulate removing pairs in order (like balancing parentheses).

// // Order Matters:
// // Removing "ab" first might block some "ba" and vice versa. So remove the one that gives more points first.
// Time: O(n) — Single pass for each removal.

// Space: O(n) — For stack and temporary string.



