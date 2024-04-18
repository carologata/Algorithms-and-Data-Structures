#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *listNew(int val)
{
    struct ListNode *new;

    new = calloc(sizeof(struct ListNode), 1);
    new->val = val;
    new->next = NULL;

    return (new);
}

void addListBack(struct ListNode **head, struct ListNode *new)
{
    struct ListNode *tmp;

    tmp = *head;
    if (*head == NULL)
        *head = new;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *listSum;
    int carry;
    int sum;
    int num1;
    int num2;

    listSum = NULL;

    sum = 0;
    carry = 0;
    while (l1 || l2 || carry)
    {
        num1 = 0;
        num2 = 0;
        if (l1)
        {
            num1 = l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            num2 = l2->val;
            l2 = l2->next;
        }
        sum = num1 + num2 + carry;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
            carry = 0;
        addListBack(&listSum, listNew(sum));
    }
    return (listSum);
}
