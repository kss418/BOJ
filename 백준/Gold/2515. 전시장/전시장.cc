#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
typedef pair<int, int> pi; typedef pair<ll, ll> pll; 
typedef unsigned long long ull; ll n, m, k, t; string s;
        
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 301010;
pll arr[MAX];
ll dp[MAX], pre[MAX];


int main() { 
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr + 1, arr + n + 1);
    
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1];
        while(arr[i].first - arr[pre[i]].first >= m) pre[i]++;
        pre[i]--;
        dp[i] = max(dp[pre[i]] + arr[i].second, dp[i - 1]);
    }
    ll result = 0;
    
    cout << dp[n];
    

    return 0;
}