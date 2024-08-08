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
class compare
{
    public:
    
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty())
        {
            return NULL;
        }

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;  // creating minheap

        // pushing first node of every linked list in the minheap
        for (int i=0; i<lists.size(); i++)
        {
            if (lists[i]!=NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        // making head and tail of new linked list
        ListNode* head=NULL;
        ListNode* tail=NULL;

        // loop till minheap is empty
        while(!minHeap.empty())
        {
            // taking top element i.e min element
            ListNode* temp=minHeap.top();
            minHeap.pop();

            // if the next node is present in the same linked list then pushing into minheap
            if (temp->next!=NULL)
            {
                minHeap.push(temp->next);
            }

            // if no node is present in merged linked list
            if (head==NULL)
            {
                head=temp;
                tail=temp;
            }

            // else inserting at tail
            else
            {
                tail->next=temp;
                tail=temp;
            }
        }

        return head;
    }
};
// time complexity: o((n*k) log(k))
// space complexity: o(n*k)