// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n==0)return false;
//         if(n==3 || n==1)return true;
//         if(n%3!=0){
//             return false;
//         }
//         return isPowerOfThree(n/3);
//     }
// };

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        return (1162261467 % n == 0);              //doesnt work for n==4 as 4294967296 ye 2 se bhi divisible h
    }
};