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
ll a[MAX], c[MAX], cnt;
vector <ll> num[MAX];

class _dij {
public:
    class node{
    public:
        ll d, cnt;
        node() : node(0, 0){}
        node(ll d, ll cnt) : d(d), cnt(cnt){}
        ll num() const{ return d; }
        bool operator<(const node& ot) const{ return num() < ot.num(); }
        bool operator>(const node& ot) const{ return num() > ot.num(); }
        bool operator==(const node& ot) const{ return num() == ot.num() && cnt == ot.cnt; }
        bool operator<=(const node& ot) const{ 
            if(num() < ot.num()) return num() < ot.num();
            if(num() == ot.num()) return cnt <= ot.cnt;
            return 0;
        }
        node operator+(const node& ot) const{
            return {d + ot.d, cnt + ot.cnt};
        }
        operator pll(){ return {d, cnt}; }
    };
    node mx(){ return {INF, INF}; }
    node mn(){ return {0, 0}; }

    using ptl = pair <node, ll>;
    ll n; vector <node> d;
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
        d.clear();
        d.resize(n + 1, mx()); 
        pq.push({ mn(), st });
        d[st] = mn();

        while (!pq.empty()) {
            auto [cn, cur] = pq.top(); pq.pop();
            if(cn > d[cur]) continue;
            
            for (auto& i : adj[cur]) {
                auto [nn, nxt] = i;
                node pl = nn + cn;
                
                if (d[nxt] <= pl) continue;
                d[nxt] = pl; pq.push({ pl, nxt });
            }
        }
    }

    node ret(ll n) { return d[n]; }
};

void run(){
    cin >> n >> m >> k; _dij dij(MAX);
    for(int i = 1;i <= k;i++){
        ll sz; cin >> c[i] >> sz;
        for(int j = 1;j <= sz;j++){
            cin >> a[j];
        }

        for(int j = 1;j <= sz;j++){
            for(int k = j + 1;k <= sz;k++) dij.addsol(a[j], a[k], {c[i], k - j});
        }
    }

    dij.init(n);
    pll ret = dij.ret(m);
    if(ret.x >= INF){ cout << -1 << " " << -1; return; }

    cout << ret.x << " " << ret.y << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

