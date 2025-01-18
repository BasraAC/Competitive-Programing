/*
problem: //https://dmoj.ca/problem/rootsolve
solution: https://dmoj.ca/submission/6630386
*/



#pragma GCC optimize("O3,branch-probabilities,unroll-loops,peel-loops,tracer,vpt,inline-functions,ipa-cp,ipa-cp-clone,ipa-bit-cp,predictive-commoning,split-loops,unswitch-loops,gcse-after-reload,tree-loop-vectorize,tree-slp-vectorize,vect-cost-model=dynamic,tree-loop-distribute-patterns")

#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"



#include <bits/stdc++.h>
#define FR(i,n) for(int i = 0; i < n; i++)
#define fast ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef complex<long double> dcomp;

vector<pair<long double, int>> co;
int x,p;
long double c;
int deg;

const int MN = 105;
dcomp pws[MN];

dcomp polynomial(dcomp e){
    dcomp res = 0;
    dcomp pw = 1;
    FR(i,deg+1){
        
        pws[i] = pw;
        pw *= e;
    }
    FR(i,x){
        
        res += co[i].first * pws[co[i].second];
        


    }
       return res;
}

inline dcomp solveRoot(dcomp z, int index, vector<dcomp> &roots){
    


    
    dcomp CPI = dcomp(1.0, 0);
    FR(i, deg){
        if (i == index) continue;
        CPI *= z - roots[i];


    }
     return (z - ( polynomial(z)/CPI));
}
   


 

int main(){
    
    fast
    cin >> x;

    cin >> c >> p;
    co.push_back(make_pair(c,p));
    
    FR(i,x-1){
        cin >> c >> p;
        co.push_back(make_pair(c/co[0].first,p));

      

    }
    
    co[0] = {1, co[0].second};
    
 
    
    deg = co[0].second;

    vector<dcomp> roots;
    FR(i,deg){
    roots.push_back(pow(dcomp(0.4,0.9),i));

    }
   
  
    

    if (co[0].second == 1){
        if(x == 2){
            cout << -co[1].first;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }

vector<dcomp> newRoots;
newRoots = roots;
   for (int iteration = 0; iteration < 4700; ++iteration) {
        
        // Use a new vector to store updated roots

        for (int i = 0; i < deg; ++i) {
            newRoots[i] = solveRoot(roots[i], i, roots);
            
        }

        // Check for convergence
        bool con = true;
       FR(i,deg){
            //cout << roots[i] << endl;
            if (abs(imag(newRoots[i])) >= 1e-6){
                
                con = false;
              
                break;

            }   
            
            

        }
   
     
        roots = newRoots; 

     if (con){
        //cout << "vo";
        break;
    }
        

        
        
    }
    
    vector<long double> myVec;
    bool hasRoot = false;
    
    FR(i, deg) {
    //cout << roots[i];
  
    if (abs(imag(roots[i])) <= 1e-6) { 
        bool CanAdd = true;

        for (auto j: myVec) {
            if (abs(real(roots[i]) - j) <= 1e-6) {
                CanAdd = false;
                break;
            }
        }

        if (CanAdd) {
            hasRoot = true;
            myVec.push_back(real(roots[i]));
        }
    }
}

    sort(myVec.begin(), myVec.end());

    if(!hasRoot){
        cout << "NO REAL ROOTS\n";
    }

    
    else{
        for(auto i: myVec){
            
            cout << setprecision(6) << i << "\n";
        }
    }


    return 0;
}