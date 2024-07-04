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
    ListNode* a1(ListNode* head){
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

    ListNode* a2(ListNode* head){
        
        ListNode* p1=head->next;
        ListNode* p2=head->next;

        while(p2!=NULL){

            int sum=0;
            while(p2!=NULL && p2->val!=0){
                sum+=p2->val;
                p2=p2->next;
            }
            p1->val=sum;
            p2=p2->next;
            p1->next=p2;
            p1=p1->next;
        }

        return head->next;

    }
    ListNode* mergeNodes(ListNode* head) {

        // APPROACH 1:- HERE NEW NODE IS MADE 
        return a1(head);

        // APPROACH 2:-  TWO POINTERS
        return a2(head);
    }
};