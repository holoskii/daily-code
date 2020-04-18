#include <iostream>
#include <vector>
using namespace std;

/*
vector<vector<int>> subsets(vector<int>& nums) {
    unsigned long long int key = 1 << nums.size();
    unsigned long long int t;
    vector<vector<int>> res;
    while(key--) {
        t = key;
        int i = 0;
        vector<int> v;
        while(t) {
            if (t & 1) v.push_back(nums[i]);
            t >>= 1;
            i++;
        }
        res.push_back(v);
    }
    return res;
}
*/

void backtrack(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int i) {
    if (i == nums.size()) {
        res.push_back(cur);
    }
    else {
        cur.push_back(nums.at(i));
        backtrack(res, cur, nums, i + 1);
        cur.pop_back();
        backtrack(res, cur, nums, i + 1);
    }
}

vector<vector<int>> subsets(vector<int> nums) {
    vector<vector<int>> res;
    vector<int> cur;
    backtrack(res, cur, nums, 0);
    return res;
}

int main(){
    auto res = subsets(vector<int>{1,2,3});
    for(auto v : res){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
