class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> vec,prefXOR;
        int temp=0;
        for(int i=0;i<arr.size();i++){
             temp^=arr[i];
             prefXOR.push_back(temp);
        }
        for(auto & i: q){
            int ans;
            if(i[0]!=0){
                ans=prefXOR[i[0]-1]^prefXOR[i[1]];
            }else{
                ans=prefXOR[i[1]];
            }
            
            vec.push_back(ans);
        }

        return vec;
    }
};