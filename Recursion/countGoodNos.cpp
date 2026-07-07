class Solution {
public:
      const long long Mod = 1e9 + 7;
    long long solve(long long x, long long n){
        if(n==0) return 1;
        long long half = solve(x,n/2);
        if(n%2==0) 
        return (half*half)%Mod;
        else return (x*(half*half)%Mod)%Mod;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long evenAns=solve(5,even);
        long long oddAns=solve(4,odd);
        return (evenAns*oddAns)%Mod;
        
    }
};