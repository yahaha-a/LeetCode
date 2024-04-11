#include <iostream>
#include <vector>
#include "LinkedList.cpp"

using namespace std;
using namespace LinkedListNS;

ListNode* removeNodeFromEnd(ListNode* head, int index)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* fast = head;
    ListNode* slow = dummyHead;
    while (index--)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = temp->next;

    if (temp == head)
    {
        head = temp->next;
    }

    delete temp;

    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    LinkedList* linkedList = new LinkedList();
    linkedList->InitLinkedList(nums);
    linkedList->printLinkedList();

    linkedList->SetHead(removeNodeFromEnd(linkedList->get(0), 5));
    linkedList->printLinkedList();
}