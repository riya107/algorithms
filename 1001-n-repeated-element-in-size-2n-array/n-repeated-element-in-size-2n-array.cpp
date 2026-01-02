class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> ump;

        for(auto it:nums){
            ump[it]++;
        }
        int n=nums.size();
        for(auto it:ump){
            if(it.second==n/2) return it.first;
        }
        return 0;
    }
};