class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        while(n != 0) {
            int num = n % 10;
            sum += num;
            prod *= num;
            n /= 10;
        }
        if(temp % (sum + prod) == 0) return true;
        else return false;
    }
};