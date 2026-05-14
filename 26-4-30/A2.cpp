#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums,int k){
    int n = nums.size();
    k %= n;
    vector<int> ans;
    for(int i=n-k;i<n;++i){
        ans.push_back(nums[i]);
    }
    for(int i=0;i<n-k;++i){
        ans.push_back(nums[i]);
    }
    nums = ans;
}

signed main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    solve(nums,k);
    for(int x:nums){
        cout<<x<<" ";
    }cout<<endl;
}