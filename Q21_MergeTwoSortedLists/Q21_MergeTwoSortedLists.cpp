#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 1, 2, 4
        // 1, 3, 4
        // Copy the second list to the returning list
        // Loop through each node in the first list, then loop through each node in the second list.
        // If the node's value in the first list is between the values of the first node and second node in the 
        // second list, then insert the node between these two nodes in the second list
        // If the node's value in the first list is less than or equal to the value of the first node in the second list,
        // then insert the node right before the first node in the second list
        // If the node's value in the first list is greater than or equal to the value of the second node in the second
        // list, then insert the node right after the second node in the second list.
        // Return the returning list.

        // First attempt
        /*

        ListNode *lOne, *lResult;
        lResult = l2;

        ListNode *tmp1, *tmp2, *prev;

        
        for (tmp1 = l1, lOne = l1; lOne != nullptr; lOne = lOne->next, tmp1 = lOne) {
            for (prev = lResult, tmp2 = lResult->next; tmp2 != nullptr; prev = prev->next, tmp2 = tmp2->next) {
                if (prev == lResult && (tmp1->val) < (prev->val)) {
                    // Insert tmp1 right before prev (which is the current head)

                    tmp1->next = prev;
                }
                else if ((prev->val) >= (tmp1->val)) {
                    prev->next = tmp1;
                    tmp1->next = tmp2;
                }
                
                if (tmp2->next == nullptr && (tmp1->val) > (tmp2->val)) {
                    tmp2->next = tmp1;
                    tmp1->next = nullptr;
                }
            }
        }
        
        
        for (ListNode* tmpN = lResult; tmpN != nullptr; tmpN = tmpN->next) {
            cout << tmpN->val << endl;
        }

        return lResult;
        */

        // Second attempt
        ListNode fake(-1);
        ListNode* last = &fake;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                last->next = l1;
                last = l1;
                l1 = l1->next;
            }
            else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) {
            last->next = l1;
        }
        if (l2 != nullptr) {
            last->next = l2;
        }

        for (ListNode* tmpN = fake.next; tmpN != nullptr; tmpN = tmpN->next) {
            cout << tmpN->val << endl;
        }

        return fake.next;
    }
};

int main()
{
    ListNode l1_2(4);
    ListNode l1_1(2, &l1_2);
    ListNode l1(1, &l1_1);

    ListNode l2_2(4);
    ListNode l2_1(3, &l2_2);
    ListNode l2(1, &l2_1);

    cout << l1.val << l1_1.val << l1_2.val << endl;
    cout << l2.val << l2_1.val << l2_2.val << endl;

    Solution sol;
    sol.mergeTwoLists(&l1, &l2);

    return 0;
}