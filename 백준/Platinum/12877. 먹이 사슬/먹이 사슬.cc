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
ll nxt[MAX], pre[MAX], result;

class _uf { 
public:
    ll n; vector <ll> p, d, dis;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n; dis.resize(n + 1);
        p.resize(n + 1, -1); d.resize(n + 1); 
    }

    pll find(ll num) { 
        if (p[num] == -1) return { num, 0ll };
        auto [pa, diff] = find(p[num]);
        p[num] = pa; d[num] += diff; 
        d[num] = (d[num] % 3 + 3) % 3;
        return { p[num], d[num] };
    }

    void merge(ll a, ll b, ll c) {
        auto [pa, da] = find(a);
        auto [pb, db] = find(b);
        if (pa == pb) { 
            bool f = (db - da - c) % 3 != 0;
            if(f) result++;
            return; 
        }
        p[pa] = pb; dis[pb] |= dis[pa];
        d[pa] = ((db - da - c) % 3 + 3) % 3; 
    }

    pll diff(ll a, ll b){
        auto [pa, da] = find(a);
        auto [pb, db] = find(b);
        if(pa == pb && !dis[pa]) return { 1, db - da };
        else if(pa == pb && dis[pa]) return { 0, -1 };
        else return { 0, 0 };
    }

    bool same(ll a, ll b) { return find(a).x == find(b).x; }
};

void run(){
    cin >> n >> m; _uf uf(n);
    while(m--){
        ll op, s ,e; cin >> op >> s >> e;
        if(s <= 0 || e <= 0 || s > n || e > n){
            result++; continue;
        }
        uf.merge(s, e, (op == 1 ? 0 : 2));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}