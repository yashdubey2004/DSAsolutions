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
    ListNode* reverse(ListNode* temp){
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while(curr != NULL){
            ListNode* nextcurr = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextcurr;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* right = reverse(slow -> next);
        ListNode* left = head;
        int res = INT_MIN;
        while(right != NULL){
            int sum = left -> val + right -> val;
            left = left -> next;
            right = right -> next;
            res = max(sum, res);
        }
        return res;
    }
};
