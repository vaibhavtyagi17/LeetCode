class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(make_pair(nums[i],i));
        }
        sort(ans.begin(),ans.end());
        int i=0;
        int j=ans.size()-1;
        while(i<j && i<ans.size() && j>=0){
            if((ans[i].first+ans[j].first)>target){
                j--;
            }
            else if((ans[i].first+ans[j].first)<target){
                i++;
            }
            else{
                break;
            }
        }
        return {ans[i].second,ans[j].second};
    }
};