#include <iostream>
#include <vector>
#include "LinkedList.cpp"

using namespace std;
using namespace LinkedListNS;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    LinkedList *linkedList = new LinkedList();
    linkedList->InitLinkedList(nums);
    linkedList->printLinkedList();

    linkedList->addAtHead(9);
    linkedList->addAtTail(8);
    linkedList->printLinkedList();

    linkedList->addAtIndex(3, 3);
    linkedList->printLinkedList();

    linkedList->deleteAtIndex(3);
    linkedList->printLinkedList();

    cout << linkedList->get(5)->value;
}