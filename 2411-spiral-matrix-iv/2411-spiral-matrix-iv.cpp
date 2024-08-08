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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));  // Initialize matrix with size m x n
        
        int top = 0;
        int left = 0;
        int right = n - 1;
        int down = m - 1;

        int dir = 0;
        while (head != NULL) {  // Check if head is not NULL
            if (dir == 0) {
                for (int i = left; i <= right && head != NULL; i++) {
                    result[top][i] = head->val;
                    head = head->next;
                }
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= down && head != NULL; i++) {
                    result[i][right] = head->val;
                    head = head->next;
                }
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left && head != NULL; i--) {
                    result[down][i] = head->val;
                    head = head->next;
                }
                down--;
            } else if (dir == 3) {
                for (int i = down; i >= top && head != NULL; i--) {
                    result[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            dir = (dir + 1) % 4;  // Change direction
        }

        return result;
    }
};
