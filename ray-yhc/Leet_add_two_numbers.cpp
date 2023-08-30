/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* node = nullptr;

        int c= 0;
        while(l1 != nullptr || l2 != nullptr || c != 0) {
            int val = c;
            if (l1 != nullptr) val += l1->val;
            if (l2 != nullptr) val += l2->val;

            c= 0;
            if (val >= 10){
                val = val - 10;
                c++;
            }

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

            if (ans == nullptr) {
                ans = new ListNode(val);
                node = ans;
            } else {
                node->next = new ListNode(val);
                node = node->next;
            }
        }
        return ans;
    }
};