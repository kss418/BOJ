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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
class node{
public:
    ll d, s, e;
    bool operator < (const node& ot) const{
        return d < ot.d;
    }
};
vector <node> arr;
ll result;

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

void run(){
    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            ll dx = a[i].x - a[j].x;
            ll dy = a[i].y - a[j].y;
            ll dist = dx * dx + dy * dy;
            if(dist < m) continue;
            arr.push_back({dist, i, j});
        }
    }

    sort(all(arr));
    for(auto& [d, s, e] : arr){
        if(uf.same(s, e)) continue;
        uf.merge(s, e);
        result += d;
    }

    cout << (uf.size(1) == n ? result : -1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}