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
    while (head != NULL && head->value == value)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* current = head;

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

    return head;
}

int main()
{
    vector<int> nums = {1, 2, 1, 4, 5};
    ListNode* head = InitLinkList(nums);
    int value = 5;

    head = RemoveElements(head, value);
    PrintLinkList(head);
}