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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MX = INF;

ll a[MAX], b[MAX];
vector <ll> org[MAX];
class node{
public:
    ll l, r, v;
}; vector <node> vec;

i128 pl(i128 a, i128 b){
    i128 tmp = a + b;
    if (tmp > MX) tmp = MX;
    else if (tmp < -MX) tmp = -MX;

    return tmp;
}

class _ft {
public:
    vector <i128> tree;
    ll size;

    _ft(){}
    _ft(ll sz) {
        size = sz;
        tree.assign(size + 1, 0);
    }

    void add(int idx, int val) {
        while(idx <= size){
            ll tmp = pl(tree[idx], val);
            tree[idx] = tmp;
            idx += (idx & -idx);
        }
    }

    i128 query(int idx) {
        i128 sum = 0;
        while (idx > 0) {
            sum = pl(sum, tree[idx]);
            idx -= (idx & -idx);
        }
        
        return sum;
    }

    void clear() {
        tree.assign(size + 1, 0);
    }
}; _ft seg;

void seg_add(ll l, ll r, ll v){
    seg.add(l, v);
    seg.add(r + 1, -v);
}

class _pbs{
public:
    ll lo, hi;
    vector <ll> l, r;
    vector <vector <ll>> arr;

    _pbs(){}
    _pbs(ll lo, ll hi) : lo(lo), hi(hi){}

    class query{ 
    public:
        ll idx, v;
    }; vector <query> q;
    void add(query a){ q.push_back(a); }

    void clear(){
        for(ll i = lo;i <= hi;i++) arr[i].clear();
        seg.clear();
    }

    bool f(ll cur, ll idx){ // 결정 함수
        query& now = q[idx];
        auto& [num, v] = now;
        i128 sum = 0;
        for(auto& i : org[num]){
            sum = pl(sum, seg.query(i));
            if(sum >= v) return 1;
        }

        return 0;
    }

    void init(){
        arr.resize(hi + 1);
        l.resize(q.size(), lo); r.resize(q.size(), hi);

        while(1){
            clear(); bool flag = 0;
            for(int i = 0;i < q.size();i++){
                if(l[i] >= r[i]) continue;
                ll mid = (l[i] + r[i]) >> 1ll;
                arr[mid].push_back(i); flag = 1;
            }
            if(!flag) break;

            ll num = 0;
            for(ll mid = lo;mid <= hi;mid++){
                while(num < vec.size() && num < mid){
                    auto& [l, r, v] = vec[num]; num++;
                    if(l <= r) seg_add(l, r, v);
                    else{
                        seg_add(l, m, v);
                        seg_add(1, r, v);
                    }
                }

                for(auto& idx : arr[mid]){
                    if(f(mid, idx)) r[idx] = mid;
                    else l[idx] = mid + 1;
                }
            }
        }
    }
};

void run(){
    cin >> n >> m; seg = {m + 1};
    for(int i = 1;i <= m;i++) cin >> a[i], org[a[i]].push_back(i);
    for(int i = 1;i <= n;i++) cin >> b[i];

    cin >> k; _pbs pbs(0, k + 1);
    for(int i = 1;i <= n;i++) pbs.add({i, b[i]});
    for(int i = 1;i <= k;i++){
        ll l, r, v; cin >> l >> r >> v;
        vec.push_back({l, r, v});
    }

    pbs.init();
    for(auto& i : pbs.l){
        if(i == k + 1) cout << "NIE\n";
        else cout << i << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

