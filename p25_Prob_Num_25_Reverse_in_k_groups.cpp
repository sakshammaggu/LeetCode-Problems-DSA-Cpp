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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (head==NULL)
        {
            return NULL;
        }

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        int cnt=0;
        while ((curr!=NULL)&&(cnt<k))
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            cnt++;
        }

        if (cnt < k) 
        {
            ListNode* temp = NULL;
            while (cnt > 0) 
            {
                temp = prev->next;
                prev->next = curr;
                curr = prev;
                prev = temp;
                cnt--;
            }
            return curr;
        }

        if (forward!=NULL)
        {
            head->next=reverseKGroup(forward, k);
        }

        return prev;
    }
};