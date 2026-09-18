class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;

        ListNode* temp = head;

        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        if (n == len) {
            return head->next;
        }

        int pos = len - n;

        temp = head;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};