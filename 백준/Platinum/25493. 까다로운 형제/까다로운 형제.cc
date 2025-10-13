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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll x, y, c;
    bool operator < (const node& ot) const{
        if(y != ot.y) return y < ot.y;
        return x < ot.x;
    }
}; vector <node> arr;
map <ll, ll> oy, ox;
vector <ll> vy, vx;

class pq_node{
public:
    pll x; ll y;
    bool operator < (const pq_node& ot) const{
        if(x.x != ot.x.x) return x.x < ot.x.x;
        else if(x.y != ot.x.y) return x.y < ot.x.y;
        return y < ot.y;
    }
};
priority_queue <pq_node> pq[MAX];
deque <node> tmp;

pll mx(pll a, pll b){
    if(a.x == b.x) return (a.y > b.y ? a : b);
    return (a.x > b.x ? a : b);
}

template <typename T = pll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    class node{
    public:
        ll v, c;
        node() : node(MINF, MINF){} // identity
        node(ll v, ll c) : v(v), c(c) {}
        node(pll a) : v(a.x), c(a.y) {}
        
        node operator += (node ot){ // add
            v += ot.v;
            return *this;
        }

        operator T(){ // query
            return {v, c};
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) : n(n){ 
        sz = 1; while(sz < n) sz <<= 1ll;
        seg.assign(2 * sz, _seg::node());
    }

    node merge(node l, node r){
        return mx(l, r);
    }

    node query(ll st, ll en) {
        st = max(1ll, st); en = min(n, en);
        if(st > en) return _seg::node();

        node l = _seg::node(), r = _seg::node();
        st += sz - 1; en += sz - 1;
        while(st <= en){
            if(st & 1) l = merge(l, seg[st++]);
            if(!(en & 1)) r = merge(seg[en--], r);
            st >>= 1; en >>= 1; 
        }

        return merge(l, r);
    }

    void set(ll idx, node val){
        if(idx < 1 || idx > n) return;
        ll p = idx + sz - 1;
        seg[p] = val;
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void add(ll idx, node val){
        if(idx < 1 || idx > n) return;
        ll p = idx + sz - 1;
        seg[p] += val;
        for(p >>= 1; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
};

void run(){
    cin >> n >> m; _seg seg(n + 1);
    arr.push_back({0, 0, 0});
    vx.push_back(0); vy.push_back(0);
    for(int i = 1;i <= n;i++){
        ll x, y, c; cin >> x >> y >> c;
        arr.push_back({x - y, x + y, c});
        vx.push_back(x - y);
        vy.push_back(x + y);
    }

    sort(all(vx)); sort(all(vy));
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());

    for(int i = 0;i < vx.size();i++) ox[vx[i]] = i + 1;
    for(int i = 0;i < vy.size();i++) oy[vy[i]] = i + 1;
    for(auto& [x, y, c] : arr) x = ox[x], y = oy[y];
    sort(all(arr));

    ll la = -1; vector <pair<pll, pll>> lazy;
    lazy.push_back({{0, 0}, {arr[0].x, arr[0].y}});
    tmp.push_back(arr[0]);
    pll result = {0, 0};

    for(auto& [x, y, c] : arr){
        if(x == arr[0].x && y == arr[0].y) continue;
        if(la != y){
            for(auto& [num, p] : lazy){
                auto[x, y] = p;
                pq[x].push({num, y});
                seg.set(x, pq[x].top().x);
            }
            lazy.clear();
        }

        while(!tmp.empty()){
            auto& [tx, ty, tc] = tmp.front();
            if(vy[y - 1] - vy[ty - 1] <= m) break;
            while(!pq[tx].empty()){
                auto& [pc, py] = pq[tx].top();
                if(vy[y - 1] - vy[py - 1] <= m) break;
                pq[tx].pop();
            }

            seg.set(tx, pq[tx].empty() ? pll(MINF, MINF) : pq[tx].top().x);
            tmp.pop_front();
        }
        
        auto lb = lower_bound(all(vx), vx[x - 1] - m);
        auto ub = upper_bound(all(vx), vx[x - 1] + m) - 1;
        ll l = ox[*lb], r = ox[*ub];
        pll q = seg.query(l, r);

        result = mx(result, {q.x + c, q.y + 1});
        lazy.push_back({{q.x + c, q.y + 1}, {x, y}});
        tmp.push_back({x, y, c});

        la = y;
    }

    for(auto& [num, p] : lazy){
        auto[x, y] = p;
        pq[x].push({num, y});
        seg.set(x, pq[x].top().x);
    }

    cout << result.x << " " << result.y;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}