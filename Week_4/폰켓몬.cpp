#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> u_s;
    for(auto n : nums) { //unordered_set<int> u_s(nums.begin(), nums.end());로 쉽게 nums의 원소들을 u_s에 담기.
        u_s.insert(n);
    }
    return min(nums.size()/2, u_s.size());
}