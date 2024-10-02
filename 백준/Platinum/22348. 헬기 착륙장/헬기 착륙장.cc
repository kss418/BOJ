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
constexpr ll MAX = 50101;
constexpr ll MOD = 1e9 + 7;
ll dp[401][MAX], sum[401][MAX];
 
int main() {
    fastio;
    
    dp[0][0] = 1;
    for(int i = 1;i <= sqrt(2 * MAX) + 1;i++){
        dp[i][0] = 1;
        for(int j = 1;j < MAX;j++){
            dp[i][j] += dp[i - 1][j] % MOD;
            dp[i][j] %= MOD;

            if(j - i >= 0) {
                dp[i][j] += dp[i - 1][j - i] % MOD;
                dp[i][j] %= MOD;
            }
        }
    }

    for(int i = 1;i <= sqrt(2 * MAX) + 1;i++){
        sum[i][0] = 1;
        for(int j = 1;j < MAX;j++) sum[i][j] = sum[i][j - 1] + dp[i][j];
    }


    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n > m) swap(n, m);
        ll cur = 0, c = 1;
        while(cur <= n + m){
            cur += c++;
        }

        ll result = 0;
        for(int i = 1;i < c - 1;i++){
            ll mx = min<ll>(i * (i + 1) / 2, n);
            ll mn = max(i * (i + 1) / 2 - m, 0ll);
            if(mn) result += sum[i][mx] - sum[i][mn - 1];
            else result += sum[i][mx];
        }

        cout << result << "\n";
    }


    return 0;
}