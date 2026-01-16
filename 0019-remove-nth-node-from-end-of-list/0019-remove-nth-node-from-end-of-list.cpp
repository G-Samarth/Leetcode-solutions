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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;

        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }

        int del = len - n - 1;

        if(del == -1){
            return head->next;
        }

        temp = head;
        while(del--){
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};