class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge;
        unordered_map<int,int>next;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()) next[nums2[i]]=-1;
            else next[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(auto num:nums1){
            nge.push_back(next[num]);
        }
        return nge;

    }
};