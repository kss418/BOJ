#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
typedef pair<int, int> pi; typedef pair<ll, ll> pll; 
typedef unsigned long long ull; ll n, m, k, t; string s;
        
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 1010101;
const ll MOD = 1e9 + 9;
ll dp[MAX];


int main() { 
    fastio;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4;i < MAX;i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= MOD;   
    }
    
    
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] % MOD << "\n";
    }
    

    return 0;
}

