class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* head = new ListNode(
            (curr1->val <= curr2->val) ? curr1->val : curr2->val
        );
        ListNode* final = head;

        if (curr1->val <= curr2->val)
            curr1 = curr1->next;
        else
            curr2 = curr2->next;

        while (curr1 != nullptr && curr2 != nullptr) {

            if (curr1->val < curr2->val) {
                ListNode* node = new ListNode(curr1->val);
                final->next = node;
                final = final->next;
                curr1 = curr1->next;
            }
            else {
                ListNode* node = new ListNode(curr2->val);
                final->next = node;
                final = final->next;
                curr2 = curr2->next;
            }
        }

        while (curr1 != nullptr) {
            ListNode* node = new ListNode(curr1->val);
            final->next = node;
            final = final->next;
            curr1 = curr1->next;
        }

        while (curr2 != nullptr) {
            ListNode* node = new ListNode(curr2->val);
            final->next = node;
            final = final->next;
            curr2 = curr2->next;
        }

        return head;
    }
};