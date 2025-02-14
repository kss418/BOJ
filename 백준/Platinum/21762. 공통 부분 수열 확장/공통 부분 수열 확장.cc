#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> pq[26][2], sq[26][2];
ll pre[MAX][2], suf[MAX][2];

class _prop { 
public:
    vector<ll> seg, lazy; ll n;
    vector<bool> flag;

    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1);
        flag.resize(4 * n + 1, 0);
    }

    void propagate(ll l, ll r, ll node) {
        if (!flag[node]) return;
        if (l != r) {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
            flag[node * 2] = flag[node * 2 + 1] = 1;
        }
        seg[node] = lazy[node];
        flag[node] = 0;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] = val; flag[node] = 1;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret = max(ret, query(st, en, mid + 1, r, node * 2 + 1));

        return ret;
    }
} seg(MAX);

void init(string& s, string& c, ll num){
    ll idx = 0;
    for(int i = 0;i < s.size();i++){
        pre[i][num] = idx;
        if(idx < c.size() && c[idx] == s[i]) idx++;
    }

    idx = 0;
    for(int i = s.size() - 1;i >= 0;i--){
        suf[i][num] = idx;
        if(idx < c.size() && c[c.size() - idx - 1] == s[i]) idx++;
    }

    for(int i = 0;i < s.size();i++){
        if(pre[i][num] + suf[i][num] < c.size()) continue;
        ll pmn = c.size() - suf[i][num];
        ll smn = c.size() - pre[i][num];
        pq[s[i] - 'a'][num].push_back({pmn, pre[i][num]});
        sq[s[i] - 'a'][num].push_back({smn, suf[i][num]});
    }
}

bool ret(string& a, string& b){
    for(int i = 0;i < 26;i++){
        seg.add(0, MAX, 0);
        for(auto& j : pq[i][0]) {
            auto[l, r] = j;
            seg.add(l, r, 1);
        }

        for(auto& j : pq[i][1]){
            auto[l, r] = j;
            ll q = seg.query(l, r);
            if(q) return 1;
        }
    }

    for(int i = 0;i < 26;i++){
        seg.add(0, MAX, 0);
        for(auto& j : sq[i][0]) {
            auto[l, r] = j;
            seg.add(l, r, 1);
        }

        for(auto& j : sq[i][1]){
            auto[l, r] = j;
            ll q = seg.query(l, r);
            if(q) return 1;
        }
    }

    return 0;
}

void clear(){
    memset(pre, 0, sizeof(pre));
    memset(suf, 0, sizeof(suf));
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 2;j++){
            pq[i][j].clear();
            sq[i][j].clear();
        }
    }
}

void run(){
    string a, b, c; cin >> a >> b >> c;
    init(a, c, 0); init(b, c, 1);
    cout << ret(a, b) << "\n"; clear();
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}   