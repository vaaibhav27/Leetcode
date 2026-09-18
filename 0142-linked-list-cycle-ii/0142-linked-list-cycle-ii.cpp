class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        unordered_set<ListNode*> st;

        ListNode* temp = head;

        while (temp != NULL) {

            if (st.find(temp) != st.end()) {
                return temp;
            }

            st.insert(temp);

            temp = temp->next;
        }

        return NULL;
    }
};