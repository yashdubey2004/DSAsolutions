class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        ListNode* t1 = head;
        ListNode* prev = NULL;

        int cnt = 0;

        while(t1) {
            t1 = t1->next;
            cnt++;
        }

        int rem = cnt - n;

        // removing head
        if(rem == 0) {
            return head->next;
        }

        while(rem > 0) {
            prev = temp;
            temp = temp->next;
            rem--;
        }

        prev->next = temp->next;

        return head;
    }
};
