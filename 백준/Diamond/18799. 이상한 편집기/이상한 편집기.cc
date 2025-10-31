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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX], result = INF, cnt, len[MAX][MAX];

set <pll> st;
ll f(ll x){
    ll ret = INF;
    auto lb = st.lower_bound({x, MINF});
    if(lb != st.end()) ret = min(ret, lb->x - x + lb->y);
    if(lb != st.begin()){
        --lb;
        ret = min(ret, x - lb->x + lb->y);
    }

    return ret;
}

void run(){
    cin >> s; n = s.size();
    for(int d = 0;d < n;d++){
        for(int i = n - d;i >= 1;i--){
            if(s[i - 1] == s[i + d - 1]) len[i][i + d] = len[i + 1][i + d + 1] + 1;
            else len[i][i + d] = 0; 
        }
    }

    for(int i = 1;i <= n;i++) dp[1][i] = i + 1; 
    for(int i = 2;i <= n;i++){
        vector <pll> vec;
        for(int j = 1;j < i;j++){
            ll pre = min<ll>(len[j][i], i - j);
            vec.push_back({i + pre - 1, dp[j][i - 1] + i - j - pre + 1});
        }
        
        sort(all(vec), [](pll a, pll b){
            return a.y < b.y;
        });

        st.clear();
        for(auto& [x, y] : vec){
            if(st.empty() || f(x) > y) st.insert({x, y});
        }

        for(int j = i;j <= n;j++) dp[i][j] = f(j);
    }

    for(int i = 1;i <= n;i++) result = min(result, dp[i][n]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}