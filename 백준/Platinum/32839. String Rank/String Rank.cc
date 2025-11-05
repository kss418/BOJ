#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 3010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pre[MAX][26], dp[MAX], result;
bool v[26];

void run(){
    cin >> s; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= s.size() + 1;i++){
        for(int j = 0;j < 26;j++) pre[i][j] = pre[i - 1][j];
        if(i == s.size() + 1) break;
        pre[i][s[i - 1] - 'a'] = i;
    }

    dp[s.size() + 1] = 0;
    for(int i = s.size() + 1;i >= 2;i--){
        for(int j = 0;j < 26;j++){
            ll nxt = pre[i - 1][j];
            if(!nxt) continue;
            dp[nxt] = min(dp[nxt], dp[i] + 1);
        }
    }

    for(int i = 1;i <= s.size() + 1;i++) result = max(result, dp[i]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
