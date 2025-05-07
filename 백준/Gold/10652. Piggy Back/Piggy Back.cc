#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 40101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll c[3], d[MAX][3];
vector <ll> adj[MAX];

class node{
public:
    ll d, cur, cnt;
    bool operator > (const node& ot) const{
        return d > ot.d;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

void run(){
    for(int i = 0;i < 3;i++) cin >> c[i];
    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    memset(d, 0x3f, sizeof(d));
    pq.push({0, 1, 0});
    pq.push({0, 2, 1});

    while(!pq.empty()){
        auto[cd, cur, cnt] = pq.top(); pq.pop();
        if(d[cur][cnt] <= cd) continue;
        d[cur][cnt] = cd;

        for(auto& nxt : adj[cur]){
            if(!cnt){
                pq.push({cd + c[0], nxt, 0});
                pq.push({cd + d[cur][1] + c[2], nxt, 2});
            }
            else if(cnt == 1){
                pq.push({cd + c[1], nxt, 1});
                pq.push({cd + d[cur][0] + c[2], nxt, 2});
            }
            else pq.push({cd + c[2], nxt, 2});
        }
    }

    cout << min(d[n][0] + d[n][1], d[n][2]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}