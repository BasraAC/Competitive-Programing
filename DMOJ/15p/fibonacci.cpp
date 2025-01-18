/*
problem: https://dmoj.ca/problem/fibonacci
solution: https://dmoj.ca/submission/6393273
*/


#include <utility>
#include <stdio.h>
using namespace std;
#define MOD 1000000007
pair<long long,long long>fastDoubling(unsigned long long n){
    if (n == 0){
        return make_pair(0, 1);
    }
    pair<long long,long long> ab = fastDoubling(n/2);
    long long a = ab.first;
    long long b = ab.second;
    
    long long c = 2 * b - a;
 
    if (c < 0)
        c += MOD;
    c = (c* a) % MOD;
    long long d = (b * b + a * a) % MOD;
    if (n % 2 == 0 ){
        return make_pair(c,d);
    }
    else {
        return make_pair(d,c+d);
   

    }
  
}
int main(){

    pair<long long ,long long> nums;
    unsigned long long n;
    scanf("%llu", &n);
    
    nums = fastDoubling(n);
    printf("%lld", nums.first);
    return 0;
}