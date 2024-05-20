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
private:
    ListNode* reverse(ListNode* head)
    {
        if ((head==NULL)||(head->next==NULL))
        {
            return head;
        }
        ListNode* curr_ptr=head;
        ListNode* prev_ptr=NULL;
        ListNode* next_ptr=NULL;
        while(curr_ptr!=NULL)
        {
            next_ptr=curr_ptr->next;
            curr_ptr->next=prev_ptr;
            prev_ptr=curr_ptr;
            curr_ptr=next_ptr;
        }
        return prev_ptr;
    }

    void insert_at_tail(ListNode* &head, ListNode* &tail, int val)
    {
        ListNode* temp=new ListNode(val);
        if (head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    ListNode* add(ListNode* first, ListNode* second)
    {
        // checking if first linked list is NULL
        if (first==NULL)
        {
            return second;
        }

        // checking if second linked list is NULL
        if (second==NULL)
        {
            return first;
        }

        // checking if both are NULL
        if ((first==NULL)&&(second==NULL))
        {  
            return second;
        }

        // creating variables for sum
        int sum, digit, carry=0;

        // creating head and tail of resultant linked list
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;

        // loop till both are not NULL
        while ((first!=NULL)&&(second!=NULL))
        {
            sum=carry+first->val+second->val;
            digit=sum%10;
            insert_at_tail(anshead, anstail, digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }

        // loop till first is not NULL where second is NULL
        while (first!=NULL)
        {
            sum=carry+first->val;
            digit=sum%10;
            insert_at_tail(anshead, anstail, digit);
            carry=sum/10;
            first=first->next;
        }

        // loop till second is not NULL where first is NULL
        while (second!=NULL)
        {
            sum=carry+second->val;
            digit=sum%10;
            insert_at_tail(anshead, anstail, digit);
            carry=sum/10;
            second=second->next;
        }

        // loop when both first and second are NULL and we have to move carry
        while (carry!=0)
        {
            sum=carry;
            digit=sum%10;
            insert_at_tail(anshead, anstail, digit);
            carry=sum/10;
        }

        return anshead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // displaying linked list 1
        ListNode* ans=add(l1, l2);
        return ans;
    }
};