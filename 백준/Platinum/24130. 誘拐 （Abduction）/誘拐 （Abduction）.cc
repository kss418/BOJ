#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 1e7;
ll dp[MAX][1010], dir[MAX], sum[1010];

void init(ll cur){
    dir[0] = cur;
    for(int i = 1;i <= k;i++) {
        cur += (s[i - 1] == 'L' ? -1 : 1);
        cur = (cur + 4) % 4; dir[i] = cur;
    }
}

void solve(ll cur, ll sz, ll d){
    for(int i = cur + 2;i <= k;i += 2){
        memset(sum, 0, sizeof(sum));
        if(dir[i] == d){
            sum[0] = dp[i - 2][0];
            for(int j = 1;j <= sz;j++) sum[j] = (sum[j - 1] + dp[i - 2][j]) % MOD;
        }
        else{
            sum[sz] = dp[i - 2][sz];
            for(int j = sz - 1;j >= 0;j--) sum[j] = (sum[j + 1] + dp[i - 2][j]) % MOD;
        }

        for(int j = 0;j <= sz;j++) {
            if(d == dir[i]) dp[i][j] = (!j ? 0 : sum[j - 1]);
            else dp[i][j] = sum[j + 1];
        }
    }
}

void run(){
    cin >> n >> m >> k >> s; ll ry, rx; 

    if(s[0] == 'L'){
        init(0);
        for(int i = 1;i <= n;i++) dp[0][i] = 1; solve(0, n, 0);
        for(int i = 1;i <= m;i++) dp[1][i] = 1; solve(1, m, 3);
        ry = (k % 2 ? dp[k][m] : dp[k][n]) % MOD;
        rx = (k % 2 ? dp[k - 1][n] : dp[k - 1][m]) % MOD;
    }
    else{
        init(3);
        for(int i = 1;i <= m;i++) dp[0][i] = 1; solve(0, m, 3);
        for(int i = 1;i <= n;i++) dp[1][i] = 1; solve(1, n, 0);
        ry = (k % 2 ? dp[k][n] : dp[k][m]) % MOD;
        rx = (k % 2 ? dp[k - 1][m] : dp[k - 1][n]) % MOD;
    }

    cout << (rx * ry) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}