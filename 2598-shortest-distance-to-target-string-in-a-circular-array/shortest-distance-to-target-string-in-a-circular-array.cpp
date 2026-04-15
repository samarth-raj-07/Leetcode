class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {
        // string curr="";
        int ans1=0,ans2=0,n=words.size(),st1=st,st2=st, rep = 0;
        while(true){
            if(words[st1]==target){
                break;
            }else{
                st1=(st1+1)%n;
                ans1++;
            }
            rep ++;
            if (rep>=2*n){
                return -1;
            }
        }
        // rep=0;
        while(true){
            if(words[st2]==target){
                break;
            }else{
                st2=(st2-1+n)%n;
                ans2++;
            }
        }
        return min(ans1,ans2);
    }
};