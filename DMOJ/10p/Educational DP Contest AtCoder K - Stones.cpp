/*
problem: https://dmoj.ca/problem/dpk
solution: https://dmoj.ca/submission/6393069
*/

#include <stdio.h>
#include <stdbool.h>


const int MN = 1e5;
bool arrStates[100000];

#define FR(i, n) for(int i = 0; i < (n); i++)


int main(){
    arrStates[0] = false;
    int n,k;
    scanf("%d %d", &n, &k);

    int A[n];
    FR(i,n) scanf("%d", &A[i]);

    FR(i,k+1) FR(j, n) {
        if(i - A[j] < 0) { arrStates[i] = false; break;}
        else if (!arrStates[i-A[j]]) { arrStates[i] = true; break; }
    }
    
    if (arrStates[k]) printf("First");
    else { printf("Second"); }

    return 0;
}