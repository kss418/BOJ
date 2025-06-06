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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll ind[MAX], cnt[MAX];
map <pll, bool> adj;

void chk(){
    if(cnt[0] == 1 && cnt[1] == n - 1) cout << "DA\n";
    else cout << "NE\n";
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        ind[e]++;

        if(s > e){
            swap(s, e);
            adj[{s, e}] = 1;
        }
    }

    for(int i = 1;i <= n;i++) cnt[ind[i]]++;
    
    chk();
    cin >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        if(s > e) swap(s, e);
        if(adj[{s, e}]) swap(s, e);

        cnt[ind[s]]--; cnt[ind[e]]--;
        ind[s]++; ind[e]--;
        cnt[ind[s]]++; cnt[ind[e]]++;

        if(s > e) swap(s, e);
        adj[{s, e}] ^= 1;
        chk();
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

