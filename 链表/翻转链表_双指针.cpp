#include <iostream>
#include <vector>
#include "LinkedList.cpp"

using namespace std;
using namespace LinkedListNS;

ListNode* reverseList(ListNode* head)
{
    ListNode* cur = head;
    ListNode* pre = NULL;
    while (cur != NULL)
    {
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    LinkedList* linkedList = new LinkedList();

    linkedList->InitLinkedList(nums);
    linkedList->printLinkedList();

    linkedList->SetHead(reverseList(linkedList->get(0)));
    linkedList->printLinkedList();
}