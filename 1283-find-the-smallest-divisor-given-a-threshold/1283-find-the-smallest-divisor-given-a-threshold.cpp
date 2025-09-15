class Solution {
public:
    int func(int m,vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+ceil((double)nums[i]/(double)m);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=0;
        for(auto&i:nums){
            h=max(h,i);
        }
        while(l<=h){
            int m=(l+h)/2;
            if(func(m,nums)<=threshold){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};