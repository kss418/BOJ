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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll ind[MAX], result[MAX];
bool leap[MAX];
deque <ll> q;

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        ind[s]++; ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(ind[i] != 1) continue;
        leap[i] = 1;
    }

    for(int i = 1;i <= n;i++){
        if(!leap[i]) continue;
        for(auto& nxt : adj[i]) ind[nxt]--;
    }

    for(int i = 1;i <= n;i++){
        if(leap[i]) continue;
        if(ind[i] && ind[i] != 1) continue;
        q.push_back(i); break;
    }
    
    ll l = 1, r = n, f = 0;
    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(result[cur]) continue;
        result[cur] = (f ? r-- : l++);

        for(auto& nxt : adj[cur]){
            if(result[nxt]) continue;
            if(leap[nxt]) result[nxt] = (f ? l++ : r--);

            if(leap[nxt]) continue; ind[nxt]--;
            if(ind[nxt] == 1 || !ind[nxt]) q.push_back(nxt);
        }

        f ^= 1;
    }
    
    for(int i = 1;i <= n;i++) cout << result[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}