//leetcode -> 148. Sort List
//one of the best question on linklist

// merge sort on linklist
// 1.find middle 
// 2.sort with 2 different variable
// 3. then merge

//code 
class Solution {
public:

    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;   // important trick

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;  // returns node BEFORE middle split
    }

    ListNode* mergeLists(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        if(a) tail->next = a;
        if(b) tail->next = b;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        if(!head || !head->next)
            return head;

        // Step 1: split
        ListNode* mid = findmid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;  // VERY IMPORTANT

        // Step 2: sort both halves
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        // Step 3: merge
        return mergeLists(leftSorted, rightSorted);
    }
};