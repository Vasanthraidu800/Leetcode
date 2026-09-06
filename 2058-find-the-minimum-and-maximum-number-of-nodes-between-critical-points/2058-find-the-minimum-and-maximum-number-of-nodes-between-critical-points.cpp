class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (!head || !head->next || !head->next->next)
            return ans;

        ListNode* prev = head;
        ListNode* cur = head->next;

        int pos = 1;
        int first = -1, last = -1;
        int mn = INT_MAX;

        while (cur->next) {
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {

                if (first == -1) {
                    first = pos;
                } else {
                    mn = min(mn, pos - last);
                }

                last = pos;
            }

            prev = cur;
            cur = cur->next;
            pos++;
        }

        if (first == last)
            return ans;

        ans[0] = mn;
        ans[1] = last - first;

        return ans;
    }
};