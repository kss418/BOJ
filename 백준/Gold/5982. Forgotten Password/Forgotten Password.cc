#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
map <ll, string> dp;

string solve(ll cur){
    if(dp.count(cur)) return dp[cur];
    if(!cur) return dp[cur] = "";
    for(int i = 0;i < 1010;i++) dp[cur].push_back('z');

    for(int i = 0;i < m;i++){
        ll sz = st[i].size();
        if(cur - sz < 0) continue;

        bool flag = 1;
        for(int j = 0;j < sz;j++){
            if(s[cur - sz + j] != '?' && s[cur - sz + j] != st[i][j]) flag = 0;
        }
        if(!flag) continue;

        string nxt = solve(cur - sz);
        if(nxt == "-1") continue;

        dp[cur] = min(dp[cur], nxt + st[i]);
    }

    if(dp[cur].size() == 1010) dp[cur] = "-1";
    return dp[cur];
}

void run(){
    cin >> n >> m >> s; 
    for(int i = 0;i < m;i++) cin >> st[i];
    sort(st, st + m);

    cout << solve(n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}