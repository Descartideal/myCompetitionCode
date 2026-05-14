#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums){
    sort(nums.begin(),nums.end(),[&](int& A,int& B){
        if(A==0)return 0;
        if(B==0)return 1;
        return (A<B?1:0);
    });
}

signed main(){
    vector<int> nums = {0,1,0,3,12};
    solve(nums);
    for(int x:nums){
        cout<<x<<" ";
    }cout<<endl;
}