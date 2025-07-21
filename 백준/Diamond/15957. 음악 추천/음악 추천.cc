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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], sz[MAX], c[MAX];
ll in[MAX], out[MAX];
vector <ll> adj[MAX], num[MAX];

class node{
public:
    ll ti, idx, v;
    bool operator < (const node& ot) const{
        return ti < ot.ti;
    }
}; vector <node> vec;

template <typename T = ll> // query type
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ll v, len;
        node() : node(0, 0){}
        node(ll v, ll len) : v(v), len(len){}
        
        node& operator += (node ot){ // add
            return *this;
        }

        operator T(){ // node -> query
            return v;
        }
    };

    class lazy_type{
    public:
        ll v;
        lazy_type() : lazy_type(0){}
        lazy_type(ll v) : v(v){}

        lazy_type& operator += (lazy_type ot){ // add
            v += ot.v;
            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { l.v + r.v, l.len + r.len };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return !lazy.v;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s += p;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v += seg.len * lazy.v;
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy.v = 0;
    }

    _prop() {}
    _prop(ll n) {
        this->n = n; seg.resize(4 * n + 1, node()); 
        lazy.resize(4 * n + 1, lazy_type());
        tmp.resize(4 * n + 1, node()); 
    }

    void propagate(ll l, ll r, ll node) {
        if (empty(lazy[node])) return;
        if (l != r) {
            prop(lazy[node * 2], lazy[node]);
            prop(lazy[node * 2 + 1], lazy[node]);
        }
        cal(lazy[node], seg[node]);
        erase(lazy[node]);
    }

    void add(ll st, ll en, lazy_type val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, lazy_type val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return _prop::node();
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }
    
    void set(ll idx, node val){
        tmp[idx] = val;
    }

    void init(){ init(0, n); }
    void init(ll l, ll r, ll node = 1){
        if(l == r){
            seg[node] = tmp[l];
            return;
        }

        ll mid = (l + r) >> 1ll;
        init(l, mid, node * 2);
        init(mid + 1, r, node * 2 + 1);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void clear(){
        for(int i = 1;i <= n;i++) set(i, {0, 1}); init();
        lazy.assign(4 * n + 1, lazy_type());
    }
}; _prop seg;

vector <ll> arr[MAX];
ll result[MAX];
class _pbs{
public:
    ll n, a, b;
    vector <ll> l, r;

    _pbs(){}
    _pbs(ll n, ll a, ll b) : n(n), a(a), b(b){
        l.resize(n, a); r.resize(n, b);
    };

    class query{ 
    public:
        ll singer;
    }; vector <query> q;
    void add(query a){ q.push_back(a); }

    void clear(){ 
        for(int i = a;i <= b;i++) arr[i].clear();
        seg.clear();
    }

    bool f(ll cur, ll idx){ // 결정 함수
        ll& now = q[idx].singer;
        if(!c[now]) return 0;

        ll cnt = 0;
        for(auto& i : num[now]) cnt += seg.query(in[i], in[i]);
        return cnt > c[now] * k;
    }

    void init(){
        while(1){
            clear(); bool flag = 0;
            for(int i = 0;i < q.size();i++){
                if(l[i] >= r[i]) continue;
                ll mid = (l[i] + r[i]) >> 1ll;
                arr[mid].push_back(i); flag = 1;
            }
            if(!flag) break;

            ll num = 0;
            for(ll mid = a;mid <= b;mid++){
                while(num < vec.size() && num < mid){
                    auto[ti, idx, v] = vec[num]; num++;
                    seg.add(in[idx], out[idx], v);
                }

                for(auto& idx : arr[mid]){
                    if(f(mid, idx)){
                        r[idx] = mid;
                        result[idx] = vec[mid - 1].ti;
                    }
                    else l[idx] = mid + 1;
                }
            }
        }
    }
};

ll solve(ll cur, ll pre = -1){
    ll& ret = sz[cur];
    if(ret != -1) return ret; ret = 1;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += solve(nxt, cur);
    }
    return ret;
}

ll ord;
void dfs(ll cur, ll pre = -1){
    in[cur] = ++ord;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
    }

    out[cur] = ord;
}

void run(){
    cin >> n >> m >> k; seg = {n};
    for(int i = 2;i <= n;i++) cin >> p[i], adj[p[i]].push_back(i);
    for(int i = 1;i <= n;i++) seg.set(i, {0, 1}); seg.init();

    _pbs pbs(n, 1, m); dfs(1);
    for(int i = 1;i <= n;i++){
        cin >> a[i]; pbs.add({i});
        num[a[i]].push_back(i); c[a[i]]++;
    }
    memset(sz, -1, sizeof(sz)); solve(1);

    while(m--){
        ll ti, idx, v; cin >> ti >> idx >> v;
        v /= sz[idx]; vec.push_back({ti, idx, v});
    }
    sort(all(vec));

    pbs.init();
    for(int i = 1;i <= n;i++){
        ll now = result[a[i] - 1];
        cout << (now ? now : -1) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}