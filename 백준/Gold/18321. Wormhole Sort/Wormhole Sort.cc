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

class node{
public:
    ll s, e, c;
    bool operator < (const node& ot) const{
        return c > ot.c;
    }
}; node arr[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

ll a[MAX];
template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        _uf uf(n);
        for(int i = 1;i <= cur;i++){
            auto[s, e, c] = arr[i];
            uf.merge(s, e);
        }

        for(int i = 1;i <= n;i++){
            if(!uf.same(i, a[i])) return 0;
        }
        return 1;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m; 
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= m;i++){
        ll s, e, c; cin >> s >> e >> c;
        arr[i] = {s, e, c};
    }
    sort(arr + 1, arr + m + 1); arr[0].c = -1;

    _bs <ll> bs(0, m);
    cout << arr[bs.ret()].c;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

