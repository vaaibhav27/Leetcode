class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> pos;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        
        int index = 2;
        
        while (next != NULL) {
            
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                pos.push_back(index);
            }
            
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }
        
        if (pos.size() < 2) {
            return {-1, -1};
        }
        
        int mini = INT_MAX;
        int maxi = pos.back() - pos.front();
        
        for (int i = 1; i < pos.size(); i++) {
            mini = min(mini, pos[i] - pos[i - 1]);
        }
        
        return {mini, maxi};
    }
};