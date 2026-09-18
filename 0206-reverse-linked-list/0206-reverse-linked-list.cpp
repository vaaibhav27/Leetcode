class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        stack<ListNode*> st;

        ListNode* temp = head;

        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }

        head = st.top();
        st.pop();

        temp = head;

        while (!st.empty()) {

            temp->next = st.top();
            st.pop();

            temp = temp->next;
        }

        temp->next = NULL;

        return head;
    }
};