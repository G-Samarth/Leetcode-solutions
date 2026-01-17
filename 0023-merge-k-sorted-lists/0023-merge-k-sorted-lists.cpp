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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode *head1 = list1, *head2 = list2;
        ListNode* temp = new ListNode(-1);
        ListNode* tempHead = temp;

        while(head1 && head2){
            if(head1->val < head2->val){
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }else{
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }

        while(head1){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }

        while(head2){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }

        return tempHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        ListNode* ans = new ListNode(-1);
        ListNode* ansHead = ans;

        while(lists.size() > 1){
            vector<ListNode*> newList;

            for(int i=0;i<lists.size();i+=2){
                if(i+1 < lists.size()){
                    ListNode* merged = merge(lists[i], lists[i+1]);
                    newList.push_back(merged);
                }else{
                    newList.push_back(lists[i]);
                }
            }

            lists = newList;
        }

        return lists[0];
    }
};