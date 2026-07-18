class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        vector<int> node1;
        vector<int> node2;

        ListNode* temp1 = l1;
        while (temp1) {
            node1.push_back(temp1->val);
            temp1 = temp1->next;
        }

        ListNode* temp2 = l2;
        while (temp2) {
            node2.push_back(temp2->val);
            temp2 = temp2->next;
        }

        int n = max(node1.size(), node2.size());

        // Make both vectors the same size
        while (node1.size() < n) node1.push_back(0);
        while (node2.size() < n) node2.push_back(0);

        int carry = 0;

        for (int i = 0; i < n; i++) {
            int sum = node1[i] + node2[i] + carry;
            node1[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry)
            node1.push_back(carry);

        ListNode* head = new ListNode(node1[0]);
        ListNode* tail = head;

        for (int i = 1; i < node1.size(); i++) {
            tail->next = new ListNode(node1[i]);
            tail = tail->next;
        }

        return head;
    }
};