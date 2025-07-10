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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
priority_queue <ll> pq[MAX];
ll h;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll mx, cnt;
        node() : node(MINF, 0){}
        node(ll mx, ll cnt) : mx(mx), cnt(cnt){}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return cnt;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    ll merge(ll l, ll r){
        return{
            l + r
        };
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node].cnt;
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    void update(ll st, ll en, ll val) { update(st, en, val, 0, n); }
    void update(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return;
        if(seg[node].mx + h <= val) return;

        if (l == r){
            while(!pq[l].empty()){
                if(pq[l].top() + h > val){
                    pq[l].pop();
                    seg[node].cnt--;
                }
                else break;
            } 
            seg[node].mx = pq[l].empty() ? MINF : pq[l].top();

            return;
        }
        
        ll mid = (l + r) >> 1;
        update(st, en, val, l, mid, node * 2); 
        update(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node].cnt = seg[node * 2].cnt + seg[node * 2 + 1].cnt;
        seg[node].mx = max(seg[node * 2].mx, seg[node * 2 + 1].mx);
    }

    void add(ll idx, ll val) { add(idx, val, 0, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;

        if (l == r){
            seg[node].cnt++;
            seg[node].mx = max<ll>(seg[node].mx, val - h);
            pq[l].push(val - h);
            return;
        }

        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);

        seg[node].cnt = seg[node * 2].cnt + seg[node * 2 + 1].cnt;
        seg[node].mx = max(seg[node * 2].mx, seg[node * 2 + 1].mx);
    }

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};

void run(){
    cin >> n >> m >> k; _seg seg(n + 1);
    ll pre = 0;

    while(m--){
        ll op, ti; cin >> op >> ti;
        h += (ti - pre) * k; pre = ti;
        if(op == 1){
            ll idx, v; cin >> idx >> v;
            seg.add(idx, v);
        }
        else if(op == 2){
            ll l, r, v; cin >> l >> r >> v;
            seg.update(l, r, v);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

