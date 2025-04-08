#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);//1. 两数之和
    vector<vector<string>> groupAnagrams(vector<string>& strs);//49. 字母异位词分组
  
    void moveZeroes(vector<int>& nums);
    int maxArea(vector<int>& height);
};