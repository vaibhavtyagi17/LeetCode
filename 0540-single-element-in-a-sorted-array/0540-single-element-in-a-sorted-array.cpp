class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]){
                return nums[m];
            }
            if((m%2==0 && nums[m]==nums[m+1]) || (m%2==1 && nums[m]==nums[m-1])){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return -1;
    }
};