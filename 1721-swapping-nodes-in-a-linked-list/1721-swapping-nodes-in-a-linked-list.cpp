class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        int n = 0;

        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        ListNode* first = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* second = head;

        int pos = n - k + 1;

        for (int i = 1; i < pos; i++) {
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};