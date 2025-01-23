/*
problem: https://dmoj.ca/problem/dpl
solution: https://dmoj.ca/submission/6399487
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> arr;
vector<vector<long long>> dp;

long long solve(long long left, long long right) {
    if (left > right) return 0; // Base case: no elements left
    if (dp[left][right] != INT64_MIN) return dp[left][right];

    long long takeLeft = arr[left] - solve(left + 1, right); 
    long long takeRight = arr[right] - solve(left, right - 1); 
    
    dp[left][right] = max(takeLeft, takeRight);
    return dp[left][right];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    arr.resize(n);
    dp.resize(n, vector<long long>(n, INT64_MIN));
    
    for (int i = 0; i < n; ++i) cin >> arr[i];

    long long result = solve(0, n - 1);
    cout << result << "\n";

    return 0;
}