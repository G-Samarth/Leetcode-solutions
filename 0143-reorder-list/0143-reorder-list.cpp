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
    ListNode* reverseLL(ListNode *head){
        ListNode *curr = head, *prev = NULL, *nex = NULL;

        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *rev = reverseLL(slow->next);
        slow->next = NULL;

        ListNode *temp = head;
        while(rev){
            ListNode *nex = temp->next;
            temp->next = rev;
            rev = rev->next;
            temp->next->next = nex;
            temp = temp->next->next;
        }
    }
};