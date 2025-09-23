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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
set <ll> adj[MAX];
vector <ll> tmp;
vector <vector <ll>> result;
ll d[MAX];

ll sz(ll cur, ll pre = -1){
    ll mx = 0;
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        mx = max(mx, sz(nxt, cur));
    }

    return d[cur] = mx + 1;
}

void er(ll s, ll e){
    adj[s].erase(e);
    adj[e].erase(s);
}

void in(ll s, ll e){
    adj[s].insert(e);
    adj[e].insert(s);
}

void sw(){
    vector <ll>& now = result.back();
    er(now[0], now[1]);
    er(now[1], now[2]);
    er(now[2], now[3]);

    in(now[0], now[2]);
    in(now[0], now[3]);
    in(now[1], now[3]);
}

void op(ll cur, ll cnt = 2, ll pre = 1){
    tmp.push_back(cur);
    if(tmp.size() == 4){
        result.push_back(tmp);
        tmp.clear(); sw();
        return;
    }

    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        if(d[nxt] < cnt) continue;
        op(nxt, cnt - 1, cur); 
        break;
    }
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].insert(e);
        adj[e].insert(s);
    }

    while(sz(1) > 3){
        for(auto& nxt : adj[1]){
            if(d[nxt] <= 2) continue;
            tmp.push_back(1); op(nxt); break;
        }
    }

    cout << result.size() << "\n";
    for(auto& i : result){
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}