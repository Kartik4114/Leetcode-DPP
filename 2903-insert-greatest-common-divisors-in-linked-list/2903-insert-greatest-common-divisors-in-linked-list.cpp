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
    int gcd(int a,int b){
        int gcd=1;
        int j=min(a,b);
        for(int i=1;i<=j;i++){
            if(a%i==0 && b%i==0){
                gcd=i;
            }
        }
        return gcd;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        
        if(head==NULL){
            return NULL;
        }
        ListNode*temp=head;
        
        while(temp!=NULL && temp->next!=NULL){
        ListNode*current=temp;
        ListNode*nextnode=temp->next;
            
            int ans=gcd(current->val,nextnode->val);
            ListNode*newnode=new ListNode(ans);
            newnode->next=nextnode;
            current->next=newnode;
            
            temp=temp->next->next;
           
        }
        return head;
    }
};