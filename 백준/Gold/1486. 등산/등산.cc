#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 31; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll a[MAX][MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

ll tf(const char& c){
    if(c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

class _dij {
public:
    class node{
    public:
        ll d;
        ll num() const{ return d; }
        bool operator<(const node& ot) const{ return num() < ot.num(); }
        bool operator>(const node& ot) const{ return num() > ot.num(); }
        bool operator==(const node& ot) const{ return num() == ot.num(); }
        bool operator<=(const node& ot) const{ return num() <= ot.num(); }
        node operator+(const node& ot) const{
            return {d + ot.d};
        }
    };
    node mx(){ return {INF}; }
    node mn(){ return {0}; }

    using ptl = pair <node, ll>;
    ll n; vector <node> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, mx());
        pre.resize(n + 1, -1); adj.resize(n + 1);
    }

    void add(ll st, ll en, node c) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }
    void addsol(ll st, ll en, node c) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st) {
        pq.push({ mn(), st });

        while (!pq.empty()) {
            auto [cn, cur] = pq.top(); pq.pop();
            if (d[cur] <= cn) continue;
            d[cur] = cn;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
        
                if (d[nxt] <= pl) continue;
                pre[nxt] = cur; pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) { return d[n]; }
};

ll num(ll cy, ll cx, ll cnt){
    return cy * m + cx + cnt * (n * m);
}

bool outrange(ll cy, ll cx){
    return (cy < 0 || cx < 0 || cy >= n || cx >= m);
}

int main() {
    fastio;

    cin >> n >> m >> k >> t; _dij dij(2 * n * m + 2);
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < st[i].size();j++) a[i][j] = tf(st[i][j]);
    }

    for(int cy = 0;cy < n;cy++){
        for(int cx = 0;cx < m;cx++){
            ll cur = a[cy][cx];
            for(int i = 0;i < 4;i++){
                ll ny = cy + dy[i], nx = cx + dx[i];
                if(outrange(ny, nx)) continue;
                ll nxt = a[ny][nx], diff = abs(nxt - cur);

                if(diff > k) continue;
                if(nxt > cur) {
                    dij.addsol(num(cy, cx, 0), num(ny, nx, 0), {diff * diff});
                    dij.addsol(num(cy, cx, 1), num(ny, nx, 1), {1});
                }
                else if(nxt < cur){
                    dij.addsol(num(cy, cx, 0), num(ny, nx, 0), {1});
                    dij.addsol(num(cy, cx, 1), num(ny, nx, 1), {diff * diff});
                }
                else{
                    dij.addsol(num(cy, cx, 0), num(ny, nx, 0), {1});
                    dij.addsol(num(cy, cx, 1), num(ny, nx, 1), {1});
                }
            }
        }
    }
    dij.init(num(0, 0, 0));
    dij.init(num(0, 0, 1));

    ll result = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ll now = dij.ret(num(i, j, 0)).d + dij.ret(num(i, j, 1)).d;
            if(now > t) continue;
            result = max(result, a[i][j]);
        }
    }

    cout << result;

     
    return 0;
}