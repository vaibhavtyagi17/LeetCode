class Solution {
public:
    int first(vector<int>&nums,int target){
        int s=0;
        int e=nums.size()-1;
        int m=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[m]==target){
                ans=m;
                e=m-1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
            m=s+(e-s)/2;
        }
        return ans;
    }
    int last(vector<int>&nums,int target){
        int s=0;
        int e=nums.size()-1;
        int m=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[m]==target){
                ans=m;
                s=m+1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                s=m+1;
            }
            m=s+(e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firsto=first(nums,target);
        int lasto=last(nums,target);
        vector<int>finala;
        finala.push_back(firsto);
        finala.push_back(lasto);
        return finala;
    }
};