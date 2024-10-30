class Solution {
public:
    // string func(string &word){
    //     // if(word.size()==1){
    //     //     word+=
    //     // }
    //     for(int i=0;i<word.size();i++){
    //         string c=
    //         word+=c;
    //     }
    // }
    char kthCharacter(int k) {
        string word="a";
        // while(word.size()<k){
            // word=func(word);
        // }
        return 'a' + __builtin_popcount(k-1);
    }
};