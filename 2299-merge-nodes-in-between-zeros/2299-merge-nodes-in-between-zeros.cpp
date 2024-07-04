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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* newHead=NULL;
        ListNode* tail=NULL;

        int sum=0;
        while(head!=NULL){
            if(head->val!=0){
                sum+=head->val;
            } else {
                ListNode* newnode=new ListNode(sum);
                if(newHead==NULL){
                    newHead=newnode;
                    tail=newnode;
                } else {
                    tail->next=newnode;
                    tail=newnode;
                }
                sum=0;
            }
            head=head->next;
        }
        return newHead->next;

    }
};