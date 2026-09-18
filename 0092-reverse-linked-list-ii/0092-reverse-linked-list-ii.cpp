class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* temp = head;

        for (int i = 1; i < left; i++) {
            temp = temp->next;
        }

        vector<int> arr;

        ListNode* curr = temp;

        for (int i = left; i <= right; i++) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        reverse(arr.begin(), arr.end());

        curr = temp;

        for (int x : arr) {
            curr->val = x;
            curr = curr->next;
        }

        return head;
    }
};