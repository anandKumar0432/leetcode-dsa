class Solution {
public:
    const int M = 1e9 + 7;
    long long myPow(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long half = myPow(x, n/2);
        long long res = half * half % M;
        
        if(n%2 == 1){
            res = res * x;
        }
        return res % M;
    }

    int countGoodNumbers(long long n) {
        long long count = (myPow(5, (n+1)/2) * myPow(4, n/2));
        return count % M;
    }
};