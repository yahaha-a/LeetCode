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

ListNode* InitLinkList(vector<int> nums)
{
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode* node = new ListNode(nums[i]);
        current->next = node;
        current = current->next;
    }
    
    return head;
}

void PrintLinkList(ListNode* head)
{
    ListNode* current = head;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
}

ListNode* RemoveElements(ListNode* head, int value)
{
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* current = dummyhead;

    while (current->next != NULL)
    {
        if (current->next->value == value)
        {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }

    return dummyhead->next;
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 4};
    ListNode* head = InitLinkList(nums);
    int value = 1;
    head = RemoveElements(head, value);
    PrintLinkList(head);
}