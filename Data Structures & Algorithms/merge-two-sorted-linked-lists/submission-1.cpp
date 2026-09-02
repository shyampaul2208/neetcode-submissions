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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* merged=NULL;
        ListNode* tail=NULL;

        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val<ptr2->val){
                if(!tail){
                    merged=ptr1;
                    tail=ptr1;
                }else{
                    tail->next = ptr1;
                    tail=tail->next;
                }
                ptr1=ptr1->next;
            }else{
                if(!tail){
                    merged=ptr2;
                    tail=ptr2;
                }else{
                    tail->next = ptr2;
                    tail=tail->next;
                }
                ptr2=ptr2->next;

            }

        }

        tail->next = ptr1 ? ptr1 : ptr2;

        return merged;
        
    }
};
