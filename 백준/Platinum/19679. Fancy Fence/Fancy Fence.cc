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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
pll a[MAX];

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
        si[a] %= MOD; 
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

ll result;
ll num(ll a){
    ll ret = a * (a + 1) / 2;
    return ret %= MOD;
}

vector <pll> arr;
void run(){
    cin >> n; _uf uf(n);
    for(int i = 1;i <= n;i++) cin >> a[i].x;
    for(int i = 1;i <= n;i++) cin >> a[i].y, uf.si[i] = a[i].y;

    for(int i = 1;i <= n;i++) arr.push_back({a[i].x, i});
    sort(all(arr)); reverse(all(arr));
    for(auto& [v, idx] : arr){
        ll now = uf.size(idx);
        ll cnt = num(now); cnt %= MOD;
        ll d = num(v); v %= MOD;
        result += d * cnt; result %= MOD;
    }

    for(auto& [v, idx] : arr){
        ll cnt = MOD - num(uf.size(idx));
        if(idx != 1 && a[idx - 1].x >= v){
            if(!uf.same(idx, idx - 1)) cnt -= num(uf.size(idx - 1));
            uf.merge(idx, idx - 1);
        }

        if(idx != n && a[idx + 1].x >= v){
            if(!uf.same(idx, idx + 1)) cnt -= num(uf.size(idx + 1));
            uf.merge(idx, idx + 1);
        }

        ll nxt = uf.size(idx); cnt += num(nxt);
        ll d = num(v); cnt %= MOD; 
        cnt += MOD; cnt %= MOD;
        result += cnt * d; result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}