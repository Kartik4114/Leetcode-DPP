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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        unordered_set<int> st(nums.begin(),nums.end());

        while(curr!=NULL){
            
            if(st.find(curr->val)!=st.end()){
                if(prev==NULL){
                    head=curr->next;
                } else prev->next=curr->next;

                curr=curr->next;
            }

            else {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;

    }
};