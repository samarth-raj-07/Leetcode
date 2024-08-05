class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>m;
        for(auto &i: arr){
            m[i]++;
        }
        int curr=0;
        string ans="";
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]==1){
                curr++;
            }
            if(curr==k){
                ans=arr[i];
                break;
            }
        }

        return ans;
    }
};