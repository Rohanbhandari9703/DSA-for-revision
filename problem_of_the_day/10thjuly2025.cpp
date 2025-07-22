// Reschedule Meetings for Maximum Free Time II
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; 

        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);
        for(int i = n-2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }


        int result = 0;

        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1];
            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])) {
                result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
            }

      
            result = max(result, freeArray[i-1] + freeArray[i]);
        }

        return result;


    }
};
//revision notes:-(chatgpt generated)
Build Free Time Array:

freeArray[0] = startTime[0] → time before the first meeting.

freeArray[i] = startTime[i] - endTime[i-1] → gap between consecutive meetings.

freeArray[n] = eventTime - endTime[n-1] → time after the last meeting.

Initialize Two Arrays:

maxLeftFree[i]: max free time block on the left of index i.

maxRightFree[i]: max free time block on the right of index i.

Fill maxRightFree[] from right to left:

cpp
Copy code
for i = n-2 to 0:
    maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1])
Fill maxLeftFree[] from left to right:

cpp
Copy code
for i = 1 to n-1:
    maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1])
Check Each Meeting (indexed as i-1):

Compute currEventTime = endTime[i-1] - startTime[i-1].

If this meeting duration fits in max of maxLeftFree[i-1] or maxRightFree[i], consider this triplet:

cpp
Copy code
total = freeArray[i-1] + currEventTime + freeArray[i]
Also check combination of just two adjacent free blocks:

cpp
Copy code
total = freeArray[i-1] + freeArray[i]
Update result = max(result, total)

Return the final result.

⏱️ Time Complexity:
O(n) – One pass for freeArray, and one each for left/right max computation.

📦 Space Complexity:
O(n) – For freeArray, maxLeftFree, maxRightFree.