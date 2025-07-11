#include<iostream>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n=nums.size();
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1])continue;
        for(int j=i+1;j<nums.size();j++){
            if(j>i+1&&nums[j]==nums[j-1])continue;
            int k = j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);

                    while(k<l&&nums[k]==nums[k+1])k++;
                    while(k<l&&nums[l]==nums[l-1])l--;
                    k++;
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }

            }

        }
        
       }
       return ans;
    }

    int main(){
        vector<int>num={1,0,-1,0,-2,2};
        int target=0;
        vector<vector<int>>ans=fourSum(num,target);
        for(int i=0;i<ans.size();i++){
        for(int j=0;j<4;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}