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
    int get_length(ListNode* &head)
    {
        ListNode* temp=head;
        int len=0;
        while (temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int length=get_length(head);
        int position=length-n;
        if (position == 0) 
        {
            ListNode* new_head = head->next;
            head->next = NULL;
            delete head;
            return new_head;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while (cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};