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
    ListNode* swapPairs(ListNode* head) 
    {
        if (head==NULL)
        {
            return NULL;
        }
        if (head->next==NULL)
        {
            return head;
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* temp=NULL;
        head=head->next;
        while ((prev!=NULL)&&(curr!=NULL))
        {
            prev->next=curr->next;
            curr->next=prev;
            if (temp != NULL)
            {
                temp->next = curr;
            }
            temp=prev;
            prev=prev->next;
            if (prev!=NULL)
            {
                curr=prev->next;
            }
        }
        return head;
    }
};