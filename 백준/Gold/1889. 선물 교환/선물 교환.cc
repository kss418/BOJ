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
ll ind[MAX], v[MAX];
deque <ll> q;
vector <ll> result, adj[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll a, b; cin >> a >> b;
        adj[i].push_back(a);
        adj[i].push_back(b);
        ind[a]++; ind[b]++;
    }

    for(int i = 1;i <= n;i++){
        if(ind[i] <= 1) q.push_back(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        if(v[cur]) continue; v[cur] = 1;
         
        for(auto& nxt : adj[cur]){
            ind[nxt]--;
            if(ind[nxt] == 1 || !ind[nxt]) q.push_back(nxt);
        }
    }

    for(int i = 1;i <= n;i++){
        if(ind[i] == 2) result.push_back(i);
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

