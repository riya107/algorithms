class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> ump1, ump2;
        int n=nums.size();

        for(auto it:nums){
            ump2[it]++;
        }

        long long ans=0;

        for(auto it:nums){
            ump2[it]--;
            ans+=(ump1[2*it]*1LL*ump2[2*it]);
            ump1[it]++;
        }
        return ans%int(1e9+7);
    }
};