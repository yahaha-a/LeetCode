#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int> A, vector<int> B, vector<int> C, vector<int> D)
{
    unordered_map<int, int> nums_map;

    for (int a : A)
    {
        for (int b : B)
        {
            nums_map[a + b]++;
        }
    }

    int count = 0;

    for (int c : C)
    {
        for (int d : D)
        {
            if (nums_map.find(-(c + d)) != nums_map.end())
            {
                count += nums_map[-(c + d)];
            }
        }
    }

    return count;
}

int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    cout << fourSumCount(A, B, C, D);
}