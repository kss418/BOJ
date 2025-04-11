#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll a[MAX], ind[MAX];
vector <ll> adj[MAX];
deque <ll> q;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        adj[i].push_back(a[i]);
        ind[a[i]]++;
    }

    for(int i = 1;i<= n;i++){
        if(ind[i]) continue;
        q.push_back(i);
    }

    ll result = n;
    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        result--;
        for(auto& nxt : adj[cur]){
            if(!--ind[nxt]) q.push_back(nxt);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}