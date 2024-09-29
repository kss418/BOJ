#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX], dp[MAX], sum[MAX];

int main() {
    fastio;

    cin >> n;
    
    ll cur = 1; dp[0] = 1; sum[0] = 1;
    for(int i = 1;i <= 10;i++){
        cur *= 10;
        dp[i] = cur - sum[i - 1];
        sum[i] = sum[i - 1] + dp[i];
    }
    
    ll result = 0;
    for(int i = 1;i <= 10;i++){
        result += i * min(n, dp[i]);
        n -= min(n, dp[i]);
    }

    cout << result;
    
  
    return 0;
}