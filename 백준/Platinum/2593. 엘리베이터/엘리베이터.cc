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
pll a[MAX];

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

class _crt{
public:
    _crt(){} vector <pll> arr;
    tll gcd(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto[g, x, y] = gcd(b, a % b);
        return { g, y, x - a / b * y };
    }

    void clear(){ arr.clear(); }
    void add(ll a, ll m){ arr.push_back({a, m}); }

    ll mod(ll a, ll m){
        a %= m; if(a >= 0) return a;
        return a + m;
    }

    pll crt(pll a, pll b){
        auto[g, cx, cy] = gcd(a.y, b.y);
        ll lcd = a.y / g * b.y;
        if((b.x - a.x) % g) return {-1, -1};
        ll r = mod((b.x - a.x) / g, b.y); 
        ll l = mod(cx * r, b.y); 
        ll ret = mod(a.x + l * a.y, lcd);

        return { ret, lcd };
    }

    pll ret(){
        pll cur = arr[0];
        for(int i = 1;i < arr.size();i++){
            cur = crt(cur, arr[i]);
            if(cur.x == -1) return {-1, -1};
        }
        return cur;
    }
};

void run(){
    cin >> n >> m; _dij dij(m + 1); _crt crt;
    for(int i = 1;i <= m;i++) cin >> a[i].x >> a[i].y;
    ll s, e; cin >> s >> e;
    for(int i = 1;i <= m;i++){
        if(s - a[i].x >= 0 && (s - a[i].x) % a[i].y == 0) dij.add(0, i, 0);
        if(e - a[i].x >= 0 && (e - a[i].x) % a[i].y == 0) dij.add(m + 1, i, 0);
    }

    for(int i = 1;i <= m;i++){
        for(int j = i + 1;j <= m;j++){
            crt.clear();
            crt.add(a[i].x % a[i].y, a[i].y);
            crt.add(a[j].x % a[j].y, a[j].y);
            pll c = crt.ret();
            if(c.y == -1) continue;

            ll mul = n / c.y;
            ll now = mul * c.y + c.x;

            if(now > n) now -= c.y;
            if(now < a[i].x || now < a[j].x) continue;
            dij.add(i, j, 1);
        }
    }

    dij.init(0); ll result = dij.ret(m + 1);
    cout << (result >= INF ? -1 : result + 1) << "\n";
    if(result >= INF) return;
    
    vector <ll> tr; ll now = m + 1;
    while(1){
        tr.push_back(now);
        if(!now) break;
        now = dij.pre[now];
    }

    reverse(all(tr));
    for(auto& i : tr){
        if(!i || i == m + 1) continue;
        cout << i << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

