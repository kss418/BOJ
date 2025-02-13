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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result;
map <ll, bool> xm, ym;
vector <ll> xv[2], yv[2];
vector <ll> xp[2], yp[2];
vector <ll> sx[2], sy[2];
vector <ll> xl, yl;

void diff(const vector <ll>& v1, const vector <ll>& v2, const vector <ll>& sv){
    if(!v2.empty()) for(int i = 0;i < v1.size();i++){
        ll l = lower_bound(all(v2), v1[i]) - v2.begin() - 1;
        ll r = upper_bound(all(v2), v1[i]) - v2.begin();
        
        ll pre = (l >= 0 ? sv[l] : 0);
        ll nxt = sv.back() - (r ? sv[r - 1] : 0);
        result += v1[i] * l - pre;
        result += nxt - v1[i] * (sv.size() - r - 1);
    }
}

void sum(const vector <ll>& v, const vector <ll>& sv){
    if(v.empty()) return;
    for(int i = 1;i < v.size();i++) result += v[i] * i - sv[i - 1];
}

class node{
public:
    ll v, l, r;
};

void cal(deque <node>& arr){
    if(arr.empty()) return;
    auto[v, l, r] = arr[0];
    while(!arr.empty()){
        ll cnt = arr.size();
        ll ld = arr.front().v - l;
        ll rd = r - arr.back().v;

        if(rd > ld){
            result += 2 * ld * (cnt - 1);
            arr.pop_front();
        }
        else{
            result += 2 * rd * (cnt - 1);
            arr.pop_back();
        }
    }
}

void same(const vector <ll>& v, const vector <ll>& ot, const vector <ll>& sv){
    deque <node> arr;
    for(int i = 0;i < v.size();i++){
        ll l = upper_bound(all(ot), v[i]) - ot.begin() - 1;
        ll r = upper_bound(all(ot), v[i]) - ot.begin();
        ll lv = (l == -1 ? MINF : ot[l]);
        ll rv = (r >= ot.size() ? INF : ot[r]);

        if(!arr.empty() && arr.back().l != lv){
            cal(arr); arr.clear();
        }
        arr.push_back({v[i], lv, rv});
    }
    cal(arr);
}

void run(){
    cin >> n >> m >> k; 
    for(int i = 1;i <= n;i++) {
        ll num; cin >> num;
        xl.push_back(num); xm[num] = 1;
    }

    for(int i = 1;i <= m;i++) {
        ll num; cin >> num;
        yl.push_back(num); ym[num] = 1;
    }
    sort(all(xl)); sort(all(yl));

    while(k--){
        ll cx, cy; cin >> cx >> cy;
        if(xm.count(cx)) xp[0].push_back(cx), yp[0].push_back(cy);
        else xp[1].push_back(cx), yp[1].push_back(cy);
    }
    
    for(int i = 0;i < 2;i++) sort(all(xp[i])), sort(all(yp[i]));
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < xp[i].size();j++){
            ll now = xp[i][j] + (j ? sx[i][j - 1] : 0);
            sx[i].push_back(now);
        }

        for(int j = 0;j < yp[i].size();j++){
            ll now = yp[i][j] + (j ? sy[i][j - 1] : 0);
            sy[i].push_back(now);
        }
    }

    diff(xp[0], xp[1], sx[1]); diff(yp[0], yp[1], sy[1]);
    sum(xp[0], sx[0]); sum(yp[1], sy[1]); 
    sum(yp[0], sy[0]); sum(xp[1], sx[1]);
    same(yp[0], yl, sy[0]); same(xp[1], xl, sx[1]);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

