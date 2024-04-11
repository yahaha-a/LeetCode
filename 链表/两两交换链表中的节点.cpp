#include <iostream>
#include <vector>
#include "LinkedList.cpp"

using namespace std;
using namespace LinkedListNS;

ListNode* swapPairs(ListNode* head)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;

    while (cur->next != NULL && cur->next->next != NULL)
    {
        ListNode* temp1 = cur->next;
        ListNode* temp2 = cur->next->next;

        cur->next = temp2;
        temp1->next = temp2->next;
        temp2->next = temp1;

        if (cur == dummyHead)
        {
            head = temp2;
        }

        cur = cur->next->next;
    }

    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    LinkedList* linkedList = new LinkedList();
    linkedList->InitLinkedList(nums);
    linkedList->printLinkedList();

    linkedList->SetHead(swapPairs(linkedList->get(0)));
    linkedList->printLinkedList();
}