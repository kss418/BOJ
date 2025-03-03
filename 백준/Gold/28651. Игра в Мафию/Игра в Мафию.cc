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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result = INF;
bool ctz[MAX], chk[MAX];
vector <ll> maf;
vector <ll> adj[MAX];
vector <vector<ll>> tr;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n - i + 1;j++){
            ll num, sz; cin >> num >> sz;
            adj[num].clear();
            for(int k = 1;k <= sz;k++){
                ll nxt; cin >> nxt;
                adj[num].push_back(nxt);
            }
        }
        
        ll cur; cin >> cur; ctz[cur] = 1;
        tr.push_back(adj[cur]);
    }

    for(int i = 1;i <= n;i++){
        if(ctz[i]) continue;
        maf.push_back(i);
    }

    for(int i = 0;i < (1ll << maf.size());i++){
        ll now = 0, cnt = 0;
        for(int j = 0;j < maf.size();j++){
            if(i & (1ll << j)) now++;
            chk[maf[j]] = (i & (1ll << j) ? 1 : 0);
        }

        for(auto& j : tr){
            for(auto& k : j){
                if(!chk[k]) continue;
                cnt++; break;
            }
        }

        if(cnt == m) result = min(result, now);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}