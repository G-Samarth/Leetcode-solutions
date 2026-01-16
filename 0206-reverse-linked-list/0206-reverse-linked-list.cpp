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
    // Thing to remember:
    //     prev = head of reversed part of linked list
    //     curr = head of normal linked list
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head, *prev = NULL, *nex;

        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        return prev;
    }
};