class Solution {
public:
    int reverse(int x) {
        int rev = 0, rem;
        while(x!=0){
            //this while loop manage both positive and negative numbers.
            rem = x % 10;
            /*this condition manage signed integer overflow error
            if(rev > (INT_MAX / 10) || rev < (INT_MIN) / 10){     
                return 0;
            } */
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && rem > 7)) 
                return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && rem < -8)) 
                return 0;
            rev = (rev * 10) + rem;
            x = x / 10;
        }
        return rev;
    }
};

