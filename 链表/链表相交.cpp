#include <iostream>
#include <vector>
#include "LinkedList.cpp"

using namespace std;
using namespace LinkedListNS;

ListNode* getIntersectNode(ListNode* headA, ListNode* headB)
{
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lenA = 0;
    int lenB = 0;

    while (curA != NULL)
    {
        lenA++;
        curA = curA->next;
    }

    while (curB != NULL)
    {
        lenB++;
        curB = curB->next;
    }

    curA = headA;
    curB = headB;

    if (lenA < lenB)
    {
        swap(lenA, lenB);
        swap(curA, curB);
    }

    int gap = lenA - lenB;

    while (gap--)
    {
        curA = curA->next;
    }

    while (curA != NULL)
    {
        if (curA == curB)
        {
            return curA;
        }

        curA = curA->next;
        curB = curB->next;
    }

    return NULL;
}

int main()
{
    vector<int> numsA = {1, 2, 3};
    vector<int> numsB = {3, 1, 3, 3};
    vector<int> nums = {5, 2, 1, 4};

    LinkedList* linkedListA = new LinkedList();
    LinkedList* linkedListB = new LinkedList();
    LinkedList* linkedList = new LinkedList();

    linkedListA->InitLinkedList(numsA);
    linkedListB->InitLinkedList(numsB);
    linkedList->InitLinkedList(nums);

    linkedListA->addAtTail(linkedList->get(0));
    linkedListB->addAtTail(linkedList->get(0));

    linkedListA->printLinkedList();
    linkedListB->printLinkedList();

    ListNode* node = getIntersectNode(linkedListA->get(0), linkedListB->get(0));

    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
}