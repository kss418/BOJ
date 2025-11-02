#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using namespace __gnu_cxx;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE

class _uf { 
public:
    ll n; vector <ll> p, si, l, r;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
        l.resize(n + 1); r.resize(n + 1);
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
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll prv(ll num){ return max(find(l[find(num)] - 1), 0ll); }
    ll nxt(ll num){ return find(r[find(num)] + 1); }
};

void run(){
    cin >> n >> m; rope <ll> r; _uf uf(n + m + 1);
    while(m--) r.push_back(0);

    for(int i = 1;i <= n;i++){
        ll idx; cin >> idx; idx--;
        if(r[idx]){
            rope <ll> pre = r.substr(0, idx);
            rope <ll> mid = rope<ll>(1, i) + r.substr(idx, uf.nxt(idx) - idx);
            rope <ll> nxt = r.substr(uf.nxt(idx) + (uf.nxt(idx) != r.size()), r.size() - uf.nxt(idx) - (uf.nxt(idx) != r.size()));
            
            if(idx && r[idx - 1]) uf.merge(idx, idx - 1);
            uf.merge(idx, uf.nxt(idx));

            ll num = uf.find(idx);
            if(uf.r[num] + 1 < r.size() && r[uf.r[num] + 1]) uf.merge(idx, uf.r[num] + 1);
            r = pre + mid + nxt;
        }
        else{
            if(idx < r.size() - 1 && r[idx + 1]) uf.merge(idx, idx + 1);
            if(idx && r[idx - 1]) uf.merge(idx, idx - 1);

            rope <ll> pre = r.substr(0, idx);
            rope <ll> nxt = r.substr(idx + 1, r.size() - idx - 1);
            r = pre + rope<ll>(1, i) + nxt;
        }
    }

    ll mx = 0;
    for(int i = 0;i < r.size();i++){
        if(r[i]) mx = i;
    }

    cout << mx + 1 << "\n";
    for(int i = 0;i <= mx;i++) cout << r[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}