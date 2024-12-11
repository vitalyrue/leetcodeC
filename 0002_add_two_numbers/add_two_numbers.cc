#include <bits/stdc++.h>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        struct ListNode dummy;
        struct ListNode *p = l1, *prev = &dummy;

        dummy.next = p;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                if (p == nullptr) {
                    /* l2 longer than l1 */
                    prev->next = l2;
                    p = l2;
                }
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            p->val = sum % 10;
            prev = p;
            p = p->next;
        }

        if (carry) {
            p = new ListNode(carry);
            prev->next = p;
        }

        return dummy.next;
    }
};


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input: l1 = [2 -> 4 -> 3], l2 = [5 -> 6 -> 4]
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Output: [7 -> 0 -> 8]
    printList(result);

    return 0;
}
