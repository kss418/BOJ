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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

class node{
public:
    ll v, y, x;
    bool operator < (const node& ot) const{
        return v < ot.v;
    }
}; vector <node> vec;

ll num(ll cy, ll cx){
    return cy * m + cx;
}

class _uf { 
public:
    ll n; vector <ll> p, sz;
    
    _uf(){}
    _uf(ll n) {  
        this->n = n;
        p.resize(n + 1, -1); sz.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, sz[a] += sz[b];
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; _uf uf;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

class _pbs{
public:
    ll n;
    vector <ll> l, r;
    vector <pll> arr;

    _pbs(){}
    _pbs(ll n, ll a, ll b) : n(n){
        l.resize(n, a); r.resize(n, b);
    };

    class query{
    public:
        ll v, a, b;
    }; vector <query> q;
    void add(query a){ q.push_back(a); }

    void clear(){
        arr.clear(); uf.clear();
    }

    bool f(ll cur, ll idx){
        query& now = q[idx];
        if(now.a == now.b) return cur < now.v;
        return !uf.same(now.a, now.b);
    }

    void init(){
        while(1){
            clear();
            for(int i = 0;i < q.size();i++){
                if(l[i] >= r[i]) continue;
                ll mid = (l[i] + r[i]) >> 1ll;
                arr.push_back({mid, i});
            }
            if(arr.empty()) break;
            sort(all(arr));

            ll cnt = 0;
            for(auto& [mid, idx] : arr){
                while(cnt < vec.size() && vec[cnt].v <= mid){
                    auto& [v, cy, cx] = vec[cnt]; cnt++;
                    for(int j = 0;j < 4;j++){
                        ll ny = cy + dy[j], nx = cx + dx[j];
                        if(outrange(ny, nx)) continue;
                        if(a[ny][nx] > a[cy][cx]) continue;
                        uf.merge(num(cy, cx), num(ny, nx));
                    }
                }

                if(f(mid, idx)) l[idx] = mid + 1;
                else r[idx] = mid;
            }
        }
    }
};

void run(){
    cin >> n >> m >> k; uf = {n * m + 1};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
            vec.push_back({a[i][j], i, j});
        }
    }
    sort(all(vec));

    _pbs pbs(k, 1, 1010101);
    while(k--){
        ll y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        pbs.add({a[y1][x1], num(y1, x1), num(y2, x2)});
    }

    pbs.init();
    for(auto& i : pbs.l) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

