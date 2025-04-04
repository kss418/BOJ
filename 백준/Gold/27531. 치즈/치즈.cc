#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], c[MAX];
ll dp[MAX][2][2], result;
pll nxt[MAX];
bool v[MAX];

vector <pll> vec;
void dfs(pll cur){
    if(v[cur.x]) return;
    v[cur.x] = 1;
    vec.push_back(cur);

    dfs(nxt[cur.x]);
}

vector <vector <pll>> cycle;
void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i] >> c[i];
        nxt[a[i]] = {b[i], c[i]};
    }

    for(int i = 1;i <= n;i++){
        if(v[a[i]]) continue;
        vec.clear(); dfs(nxt[a[i]]);
        cycle.push_back(vec);
    }

    for(auto& i : cycle){
        if(i.empty()) continue;
        if(i.size() == 1){
            result += i[0].y;
            continue;
        }

        dp[0][1][0] = dp[0][0][1] = INF;
        dp[0][1][1] = i[0].y;
        dp[0][0][0] = 0; 
        
        for(int j = 1;j < i.size();j++){
            for(int k = 0;k <= 1;k++){
                dp[j][0][k] = dp[j - 1][1][k];
                dp[j][1][k] = min(dp[j - 1][0][k], dp[j - 1][1][k]) + i[j].y;
            }
        }

        result += min({dp[i.size() - 2][1][1], dp[i.size() - 1][1][0], dp[i.size() - 1][1][1]});
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

