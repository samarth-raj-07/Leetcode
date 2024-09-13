class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> vec;
        for(auto & i: q){
            int ans=0;
            for(int j=i[0];j<= i[1];j++){
                ans^=arr[j];
            }
            vec.push_back(ans);
        }

        return vec;
    }
};