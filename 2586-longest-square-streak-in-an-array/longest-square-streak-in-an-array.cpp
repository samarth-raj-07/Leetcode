class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int>mp;
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int num: nums) {
            int anss = sqrt(num);
            
            if(anss*anss == num && mp.find(anss)!=mp.end()) {
                mp[num] = mp[anss]+1;

                res = max(res, mp[num]);

            }else mp[num] = 1;
        }
        return res;
    }
};