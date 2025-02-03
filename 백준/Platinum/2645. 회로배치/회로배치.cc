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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll co[MAX][MAX];
pll a[MAX], st, en;
ll dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};
vector <pll> tr, result;


class _dij {
public:
    class node{
    public:
        ll d;
        node() : node(0){}
        node(ll d) : d(d){}
        ll num() const{ return d; }
        bool operator<(const node& ot) const{ return num() < ot.num(); }
        bool operator>(const node& ot) const{ return num() > ot.num(); }
        bool operator==(const node& ot) const{ return num() == ot.num(); }
        bool operator<=(const node& ot) const{ return num() <= ot.num(); }
        node operator+(const node& ot) const{
            return {d + ot.d};
        }
        operator ll(){ return d; }
    };
    node mx(){ return {INF}; }
    node mn(){ return {0}; }

    using ptl = pair <node, ll>;
    ll n; vector <node> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(){}
    _dij(ll n) { this->n = n; adj.resize(n + 1); }

    void add(ll st, ll en, node c) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }
    void addsol(ll st, ll en, node c) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st) {
        d.clear(); pre.clear();
        d.resize(n + 1, mx()); pre.resize(n + 1, -1); 
        pq.push({ mn(), st });
        d[st] = mn();

        while (!pq.empty()) {
            auto [cn, cur] = pq.top(); pq.pop();
            if(cn > d[cur]) continue;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
        
                if (d[nxt] <= pl) continue;
                d[nxt] = pl; pre[nxt] = cur; 
                pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) { return d[n]; }
};

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > n;
}

ll num(ll cy, ll cx){
    return (cy - 1) * n + cx - 1;
}

pll cal(ll num){
    ll cy = num / n, cx = num % n;
    return {cy + 1, cx + 1};
}

void run(){
    cin >> n; _dij dij(n * n);
    cin >> st.y >> st.x >> en.y >> en.x;  
    cin >> m >> k;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) co[i][j] = 1;
    }

    while(k--){
        ll cnt; cin >> cnt;
        for(int i = 1;i <= cnt;i++) cin >> a[i].y >> a[i].x;
        for(int i = 2;i <= cnt;i++){
            if(a[i].y == a[i - 1].y){
                ll mn = min(a[i].x, a[i - 1].x);
                ll mx = max(a[i].x, a[i - 1].x);
                for(int j = mn;j <= mx;j++) co[a[i].y][j] = m;
            }
            else{
                ll mn = min(a[i].y, a[i - 1].y);
                ll mx = max(a[i].y, a[i - 1].y);
                for(int j = mn;j <= mx;j++) co[j][a[i].x] = m;
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 0;k < 4;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                dij.addsol(num(i, j), num(ny, nx), co[ny][nx]);
            }
        }
    }
    dij.init(num(st.y, st.x));

    cout << dij.ret(num(en.y, en.x)).d + 1 << "\n";
    ll cur = num(en.y, en.x), sn = num(st.y, st.x);
    while(cur != sn){
        tr.push_back(cal(cur));
        cur = dij.pre[cur];
    }
    tr.push_back(cal(sn));
    reverse(all(tr)); result.push_back(tr[0]);

    for(int i = 1;i < tr.size() - 1;i++){
        if(tr[i].x == tr[i - 1].x && tr[i].x == tr[i + 1].x) continue;
        if(tr[i].y == tr[i - 1].y && tr[i].y == tr[i + 1].y) continue;
        result.push_back(tr[i]);
    }
    result.push_back(tr.back());

    cout << result.size() << " ";
    for(auto& i : result) cout << i.x << " " << i.y << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

