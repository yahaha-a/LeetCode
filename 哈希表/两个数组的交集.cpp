#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersetion(vector<int> nums1, vector<int> nums2)
{
    unordered_set<int> result_set;
    unordered_set<int> nums1_set(nums1.begin(), nums1.end());

    for (int num2 : nums2)
    {
        if (nums1_set.find(num2) != nums1_set.end())
        {
            result_set.insert(num2);
        }
    }

    return vector<int>(result_set.begin(), result_set.end());
}

int main()
{
    vector<int> nums1{1, 2, 3, 4, 4};
    vector<int> nums2{1, 1, 3, 6, 7};

    vector<int> nums = intersetion(nums1, nums2);
    for (int num : nums)
    {
        cout << num << " ";
    }
}