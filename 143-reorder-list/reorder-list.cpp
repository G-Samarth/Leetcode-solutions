/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL;

        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = reverse(slow);
        ListNode *start = head;

        while(mid && start){
            ListNode *tempStart = start->next;
            ListNode *tempMid = mid->next;
            
            start->next = mid;
            mid->next = tempStart;

            start = tempStart;
            mid = tempMid;
        }
    }
};