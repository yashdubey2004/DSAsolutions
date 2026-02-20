class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        vector<int> one, two;

        ListNode* temp = head;
        while(temp){
            if(temp->val < x)
                one.push_back(temp->val);
            else
                two.push_back(temp->val);

            temp = temp->next;
        }

        // create new list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int i = 0; i < one.size(); i++){
            curr->next = new ListNode(one[i]);
            curr = curr->next;
        }

        for(int i = 0; i < two.size(); i++){
            curr->next = new ListNode(two[i]);
            curr = curr->next;
        }

        return dummy->next;
    }
};
