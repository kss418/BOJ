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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], result[2];
ll pos[MAX];

bool solve(){
    bool ret = 0;
    for(int i = 1;i <= n;i++){
        if(pos[i]) continue;
        ll now = 0;
        for(auto& nxt : adj[i]) now += (!pos[nxt]);
        if(now > 1) pos[i] ^= 1, ret = 1;
    }

    for(int i = 1;i <= n;i++){
        if(!pos[i]) continue;
        ll now = 0;
        for(auto& nxt : adj[i]) now += (pos[nxt] == 1);
        if(now > 1) pos[i] ^= 1, ret = 1;
    }

    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll sz; cin >> sz;
        for(int j = 1;j <= sz;j++){
            ll num; cin >> num;
            adj[i].push_back(num);
        }
    }

    while(1){
        if(!solve()) break;
    }

    for(int i = 1;i <= n;i++) result[pos[i]].push_back(i);
    for(int i = 0;i <= 1;i++){
        if(!result[i].empty()) continue;
        result[i].push_back(result[i ^ 1].back());
        result[i ^ 1].pop_back();
    }

    for(int i = 0;i <= 1;i++){
        cout << result[i].size() << " ";
        for(auto& j : result[i]) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}