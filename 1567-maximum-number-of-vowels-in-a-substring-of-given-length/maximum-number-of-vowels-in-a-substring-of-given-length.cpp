class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> v={'a','e','i','o','u'};
        int maxm=-1,ans=0;
        for(int i=0;i<k;i++){
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                ans++;
            }
        }
        if(ans>maxm){
                maxm=ans;
            }
        int curr=0;
        for(int i=k;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'  ){
                ans++;
            }
            if(s[curr]=='a' || s[curr]=='e' || s[curr]=='i' || s[curr]=='o' || s[curr]=='u' ){
                ans--;
            }

            curr++;

            if(ans>maxm){
                maxm=ans;
            }

        }

        return maxm;
    }
};