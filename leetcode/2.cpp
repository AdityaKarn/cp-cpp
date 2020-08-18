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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *res = new ListNode(0, NULL);

        ListNode *temp = res;
        int carry = 0;
        while (l1 || l2)
        {

            if (l1 && l2)
            {
                temp->next = new ListNode((l1->val + l2->val + carry) % 10, NULL);

                carry = (l1->val + l2->val + carry) / 10;

                l1 = l1->next;
                l2 = l2->next;
            }

            else if (l1)
            {
                temp->next = new ListNode((l1->val + carry) % 10, NULL);

                carry = (l1->val + carry) / 10;

                l1 = l1->next;
            }
            else if (l2)
            {
                temp->next = new ListNode((l2->val + carry) % 10, NULL);

                carry = (l2->val + carry) / 10;

                l2 = l2->next;
            }
            temp = temp->next;
        }

        if (carry == 1)
        {
            temp->next = new ListNode(1, NULL);
        }

        return res->next;
    }
};