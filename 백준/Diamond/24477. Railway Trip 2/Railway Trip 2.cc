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
ll q;
pll a[MAX];

template <typename T = ll> // query type
class _mx { // 구간 예외 처리하기
public:
    class node{
    public:
        int v;
        node() : node(0){}
        node(int v) : v(v){}
        
        node& operator += (node ot){ // add
            return *this;
        }

        operator T(){ // node -> query
            return v;
        }
    };

    class lazy_type{
    public:
        int v;
        lazy_type() : lazy_type(-1){}
        lazy_type(int v) : v(v){}

        lazy_type& operator += (lazy_type ot){ // add
            v = max(v, ot.v);
            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { max(l.v, r.v) };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return lazy.v == -1;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s = max(s.v, p.v);
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v = max(seg.v, lazy.v);
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = -1;
    }

    _mx() {}
    _mx(ll n) {
        this->n = n; seg.resize(4 * n + 1, node()); 
        lazy.resize(4 * n + 1, lazy_type());
        tmp.resize(4 * n + 1, node()); 
    }

    void propagate(int l, int r, int node) {
        if (empty(lazy[node])) return;
        if (l != r) {
            prop(lazy[node * 2], lazy[node]);
            prop(lazy[node * 2 + 1], lazy[node]);
        }
        cal(lazy[node], seg[node]);
        erase(lazy[node]);
    }

    void add(ll st, ll en, lazy_type val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, lazy_type val, ll l, ll r, int node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        int mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(int st, int en) { return query(st, en, 0, n); }
    node query(int st, int en, int l, int r, int node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return _mx::node();
        if (l >= st && r <= en) return seg[node];

        int mid = (l + r) >> 1;
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
};

template <typename T = ll> // query type
class _mn { // 구간 예외 처리하기
public:
    class node{
    public:
        int v;
        node() : node(0x3f3f3f3f){}
        node(int v) : v(v){}
        
        node& operator += (node ot){ // add
            return *this;
        }

        operator T(){ // node -> query
            return v;
        }
    };

    class lazy_type{
    public:
        int v;
        lazy_type() : lazy_type(0x3f3f3f3f){}
        lazy_type(int v) : v(v){}

        lazy_type& operator += (lazy_type ot){ // add
            v = min(v, ot.v);
            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { min(l.v, r.v) };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return lazy.v == 0x3f3f3f3f;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s = min(s.v, p.v);
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v = min(seg.v, lazy.v);
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = 0x3f3f3f3f;
    }

    _mn() {}
    _mn(int n) {
        this->n = n; seg.resize(4 * n + 1, node()); 
        lazy.resize(4 * n + 1, lazy_type());
        tmp.resize(4 * n + 1, node()); 
    }

    void propagate(int l, int r, int node) {
        if (empty(lazy[node])) return;
        if (l != r) {
            prop(lazy[node * 2], lazy[node]);
            prop(lazy[node * 2 + 1], lazy[node]);
        }
        cal(lazy[node], seg[node]);
        erase(lazy[node]);
    }

    void add(int st, int en, lazy_type val) { add(st, en, val, 0, n); }
    void add(int st, int en, lazy_type val, int l, int r, int node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        int mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(int st, int en) { return query(st, en, 0, n); }
    node query(int st, int en, int l, int r, int node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return _mn::node();
        if (l >= st && r <= en) return seg[node];

        int mid = (l + r) >> 1;
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
};

_mx <int> mxp; _mn <int> mnp;
template <typename T = ll> // query type
class _mxseg { // 구간 예외 처리하기
public:
    int n, sz;
    class node{
    public:
        int v;
        node() : node(0){} // identity
        node(int v) : v(v) {}
        
        node operator += (node ot){ // add
            v += ot.v;
            return *this;
        }

        operator T(){ // query
            return v;
        }
    };
    vector <node> seg;

    _mxseg(){}
    _mxseg(int n) : n(n){ 
        sz = 1; while(sz < n) sz <<= 1ll;
        seg.assign(2 * sz, _mxseg::node());
    }

    node merge(node l, node r){
        return{
            max(l.v, r.v)
        };
    }

    node query(int st, int en) {
        st = max(1, st); en = min(n, en);
        if(st > en) return _mxseg::node();

        node l = _mxseg::node(), r = _mxseg::node();
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

template <typename T = ll> // query type
class _mnseg { // 구간 예외 처리하기
public:
    int n, sz;
    class node{
    public:
        int v;
        node() : node(0x3f3f3f3f){} // identity
        node(int v) : v(v) {}
        
        node operator += (node ot){ // add
            v += ot.v;
            return *this;
        }

        operator T(){ // query
            return v;
        }
    };
    vector <node> seg;

    _mnseg(){}
    _mnseg(ll n) : n(n){ 
        sz = 1; while(sz < n) sz <<= 1ll;
        seg.assign(2 * sz, _mnseg::node());
    }

    node merge(node l, node r){
        return{
            min(l.v, r.v)
        };
    }

    node query(int st, int en) {
        st = max(1, st); en = min(n, en);
        if(st > en) return _mnseg::node();

        node l = _mnseg::node(), r = _mnseg::node();
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

_mxseg <ll> seg1[18]; _mnseg <ll> seg2[18];
class _st { // 1-base index
public:
    int n, m, lg; vector <vector<int>> num1, num2;
    _st(){}
    _st(int n, int m) { //n 개수 m 깊이
        this->n = n; this->m = m; this->lg = log2(m + 1);
        num1.resize(log2(m + 1) + 1, vector<int>(n + 1, 0));
        num2.resize(log2(m + 1) + 1, vector<int>(n + 1, 0x3f3f3f3f));
    }

    void add1(ll st, ll en) {
        num1[0][st] = en;
        seg1[0].set(st, en);
    }

    void add2(ll st, ll en) {
        num2[0][st] = en;
        seg2[0].set(st, en);
    }

    void init() {
        for (int i = 1; i <= lg; i++) {
            for (int j = 1; j <= n; j++){
                int nxt = seg1[i - 1].query(j, j);
                int pre = seg2[i - 1].query(j, j);
                
                num1[i][j] = seg1[i - 1].query(pre, nxt);
                num2[i][j] = seg2[i - 1].query(pre, nxt);
                
                seg1[i].set(j, num1[i][j]);
                seg2[i].set(j, num2[i][j]);
            }
        }
    }

    pair<int, int> ret(ll n, ll d) { //n 노드 d 깊이
        int n1 = n, n2 = n;
        for (int i = lg; i >= 0; i--) {
            if (d & (1ll << i)){
                int nn1 = seg1[i].query(n2, n1);
                int nn2 = seg2[i].query(n2, n1);
                n1 = nn1; n2 = nn2;
            }
        }

        return {n1, n2};
    }
}; _st st;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r, s, e;
    _bs(T l, T r, T s, T e) {
        this->l = l; this->r = r;
        this->s = s; this->e = e;
    }

    bool f(T cur) {
        pair <int, int> now = st.ret(s, cur);
        return e >= now.y && e <= now.x;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) >> 1;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m >> k; 
    for(int i = 0;i <= log2(n + 1);i++){
        seg1[i] = {n}; seg2[i] = {n}; 
    }
    st = {n, n}; mxp = {n}; mnp = {n};

    for(int i = 1;i <= k;i++){
        cin >> a[i].x >> a[i].y;
        if(a[i].x < a[i].y){
            mxp.add(a[i].x, min(a[i].y - 1, a[i].x + m - 1), a[i].y);
        }
        else{
            mnp.add(max(a[i].y + 1, a[i].x - m + 1), a[i].x, a[i].y);
        }
    }

    for(int i = 1;i <= n;i++){
        mxp.add(i, i, i); mnp.add(i, i, i);
        st.add1(i, mxp.query(i, i));
        st.add2(i, mnp.query(i, i));
    }
    st.init();

    cin >> q;
    while(q--){
        int s, e; cin >> s >> e;
        _bs <int> bs(1, n + 1, s, e);
        int ret = bs.ret();
        
        cout << (ret == n + 1 ? -1 : ret) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}