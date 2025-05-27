#include <bits/stdc++.h>
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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;
vector <pll> arr;

using node = pair<ll, pll>;
priority_queue <node, vector<node>, greater<node>> num;

class _uf { 
public:
    ll n; vector <ll> p, si, l, r, arr;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
        l.resize(n + 1); r.resize(n + 1);
        arr.resize(n + 1);
        iota(all(l), 0); iota(all(r), 0);
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
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
        arr[a] = max(arr[a], arr[b]);
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll prv(ll num){ return find(l[find(num)] - 1); }
    ll nxt(ll num){ return find(r[find(num)] + 1); }
};

void run(){
    cin >> n; _uf uf(MAX);
    for(int i = 1;i <= n;i++){
        cin >> a[i], uf.arr[i] = a[i];
        arr.push_back({a[i], i});
    }
    sort(all(arr));
    
    for(auto& [num, idx] : arr){
        while(uf.prv(idx)){
            if(uf.arr[uf.prv(idx)] > uf.arr[uf.find(idx)]) break;
            result += num;
            uf.merge(idx, uf.prv(idx));
        }

        while(uf.nxt(idx) <= n){
            if(uf.arr[uf.nxt(idx)] > uf.arr[uf.find(idx)]) break;
            result += num;
            uf.merge(idx, uf.nxt(idx));
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}