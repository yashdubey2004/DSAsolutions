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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* odds = head;
        ListNode* even = head -> next;
        ListNode* temp2 = even;
        while(even && even -> next){
            odds -> next = even -> next;
            odds = odds -> next;
            even -> next = odds -> next;
            even = even -> next;
        }
        odds -> next = temp2;
        return head;
    }
};
