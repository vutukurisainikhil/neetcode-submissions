class Solution {
public:
    /*
        If n is even we can write x^n -> x^(n/2) * x^(n/2)
            eg: 2^6 -> 2^(6/2)  2^(6/2)
        If n is odd we can write x^n -> x * x^(n/2) * x^(n/2)
            eg: 2^7 -> 2   2^(6/2)  2^(6/2)
    */
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / solve(x, n);
        } else {
            return solve(x, n);
        }
    }

    double solve(double x, int n) {
        // Base Case
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        // Recursive Call
        double ans = solve(x, n / 2);

        // Even
        if (n % 2 == 0) {
            return ans * ans;
        }
        // Odd
        else {
            return x * ans * ans;
        }
    }
};
