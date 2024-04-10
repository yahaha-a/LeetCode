#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int value;
    ListNode* next;

    ListNode(int val)
    {
        value = val;
        next = NULL;
    }
};

class LinkedList
{

private:

    ListNode* head;
    ListNode* dummyHead = new ListNode(0);
    int size;

public:

    void InitLinkedList(vector<int> nums)
    {
        head = new ListNode(nums[0]);
        dummyHead->next = head;
        ListNode* current = head;
        for (int i = 1; i < nums.size(); i++)
        {
            ListNode* node = new ListNode(nums[i]);
            current->next = node;
            current = current->next;
        }
        size = nums.size();
    }

    void addAtTail(int value)
    {
        if (head == NULL)
        {
            head = new ListNode(value);
            dummyHead->next = head;
        }
        else
        {
            ListNode* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = new ListNode(value);
        }

        size++;
    }

    void addAtHead(int value)
    {
        if (head == NULL)
        {
            head = new ListNode(value);
            dummyHead->next = head;
        }
        else
        {
            dummyHead->next = new ListNode(value);
            dummyHead->next->next = head;
            head = dummyHead->next;
        }

        size++;
    }

    ListNode* get(int index)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else if (index < 0 || index > size - 1)
        {
            return NULL;
        }
        else
        {
            ListNode* current = head;
            while (index--)
            {
                current = current->next;
            }

            return current;
        }
    }

    void addAtIndex(int index, int value)
    {
        if (index < 0 || index > size - 1)
        {
            return;
        }
        else
        {
            ListNode* current = dummyHead;
            while (index--)
            {
                current = current->next;
            }
            ListNode* node = new ListNode(value);
            
            ListNode* temp = current->next;
            current->next = node;
            node->next = temp;

            head = dummyHead->next;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size - 1)
        {
            return;
        }
        else
        {
            ListNode* current = dummyHead;
            while (index--)
            {
                current = current->next;
            }
            ListNode* temp = current->next;
            current->next = temp->next;
            delete temp;

            head = dummyHead->next;
            size++;
        }
    }

    void printLinkedList()
    {
        ListNode* current = head;
        while (current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    LinkedList* linkedList = new LinkedList();
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