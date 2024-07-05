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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        
        vector<int> result(2);
        int firstIndex=-1;
        int lastIndex=-1;
        int currMin=INT_MAX;
        int currMax=-1;

        if(head->next->next==NULL){
            result={-1,-1};
            return result;
        }

        // head=head->next;

        int cnt=0;
        while(head!=NULL && head->next!=NULL && head->next->next!=NULL){

            cnt++;
            if((head->val < head->next->val && head->next->next->val < head->next->val) ||
                (head->val > head->next->val && head->next->next->val > head->next->val)){
                
                if(firstIndex!=-1 && lastIndex!=-1){
                    currMin=min(currMin,cnt-lastIndex);
                    currMax=max(currMax,cnt-firstIndex);
                }
                if(firstIndex==-1) firstIndex=cnt;
                lastIndex=cnt;
            }
            head=head->next;
        }


        if(currMax==-1){
            currMin=-1;
        }
        result={currMin,currMax};
        return result;
    }

};