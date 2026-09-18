class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL)
            return head;

        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        if (k == 0)
            return head;

        temp = head;

        for (int i = 1; i < n - k; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;

        temp->next = NULL;

        temp = newHead;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;

        return newHead;
    }
};