#include "function.h"


void twoSum()
{
    Solution sol;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);

    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
}

void groupAnagrams()
{
    Solution solution;
    vector<string> strs1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);

    cout << "Test case 1:" << endl;
    for (const auto& group : result1) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}