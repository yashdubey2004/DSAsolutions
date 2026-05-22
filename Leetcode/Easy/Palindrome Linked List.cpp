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
    ListNode* reverse(ListNode* h){
        ListNode* temp = h;
        ListNode* prev = NULL;
        while(temp){
            ListNode* agla = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = agla;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* high = head;
        ListNode* t1 = head;
        while(high && high -> next){
            slow = slow -> next;
            high = high -> next -> next;
        }
        ListNode* newLink = reverse(slow);

        while(newLink && t1){
            if(newLink -> val == t1 -> val){
                newLink = newLink -> next;
                t1 = t1 -> next;
            }
            else return false;
        }
        return true;
    }
};
