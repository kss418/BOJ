#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;
 
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401010;
constexpr ll MOD = 998244353;
vector <ll> xo, yo;
 
class _sseg {
public:
    ll n; vector <ll> seg, c;
    _sseg(ll n) {
        this->n = n;
        seg.resize(4 * n + 1); c.resize(4 * n + 1);
    }
 
    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }
 
    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        if (r < st || l > en) return;
 
        if(st <= l && r <= en) c[node] += val;
        else{
            ll mid = (l + r) >> 1;
            add(st, en, val, l, mid, node * 2);
            add(st, en, val, mid + 1, r, node * 2 + 1);
        }
 
        if(c[node]) seg[node] = yo[r] - yo[l - 1];
        else {
            if(l == r) seg[node] = 0;
            else seg[node] = seg[node * 2] + seg[node * 2 + 1]; 
        }
    }
};
 
class node{
public:
    ll x, y1, y2, num;
    bool operator<(node& ot){
        return x < ot.x;
    }
};
vector <node> query;
vector <ll> yv;
map <ll, ll> ym;

void comp(vector <ll>& v, map <ll, ll>& mp, vector <ll>& org){
    ll cnt = 0; sort(all(v)); org.resize(MAX);
    for(auto& i : v){
        if(!mp.count(i)) mp[i] = ++cnt;
        org[cnt] = i;
    }
}
 
int main() {
    fastio;
 
    cin >> n; _sseg seg(2 * n);
    for(int i = 1;i <= n;i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        yv.push_back(y1); yv.push_back(y2);
        query.push_back({x1, y1, y2, 1});
        query.push_back({x2, y1, y2, -1});
    }
    
    comp(yv, ym, yo); sort(all(query));
    for(auto& i : query){
        auto&[x1, y1, y2, num] = i;
        y1 = ym[y1]; y2 = ym[y2];
    }
 
    ll result = 0, la = 0;
    for(auto&i : query){
        auto&[x, y1, y2, num] = i;
        result += seg.query(0, MAX - 1) * (x - la);
        seg.add(y1 + 1, y2, num); la = x;
    }
 
    cout << result;
 
 
    return 0;
}
