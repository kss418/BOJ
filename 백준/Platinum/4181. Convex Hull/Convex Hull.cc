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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

class _ch{
public:
    _ch() {}
    vector <ll> num;
    vector <pll> point;
    ll cnt = 0;

    class node{
    public:
        ll x, y, dx, dy, idx;
        node(pll a, ll idx) : node(a.x, a.y, 1, 0, idx) {};
        node(ll x, ll y, ll dx, ll dy, ll idx){
            this->x = x; this->y = y;
            this->dx = dx; this->dy = dy;
            this->idx = idx;
        }

        bool operator <(node& ot){
            if(dy * ot.dx != dx * ot.dy) return dy * ot.dx < dx * ot.dy;
            if(x != ot.x) return x < ot.x;
            return y < ot.y;
        }
        operator pll(){ return { x, y }; }
    };
    vector <node> arr;

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1;
        else if(num < 0) return -1;
        return 0;
    }
    
    void add(ll a, ll b) { add({a, b}); }
    void add(pll a){ arr.push_back({a, cnt++}); }

    void init(){
        sort(all(arr));
        for(int i = 1;i < arr.size();i++){
            arr[i].dx = arr[i].x - arr[0].x;
            arr[i].dy = arr[i].y - arr[0].y;
        }
        sort(arr.begin() + 1, arr.end());

        num.push_back(0);
        if(arr.size() == 1) {
            point.push_back(arr[0]); return;
        }
        num.push_back(1);
        ll nxt = 2;

        while(nxt < arr.size()){
            while(num.size() >= 2){
                ll fi = num.back(); num.pop_back();
                ll se = num.back();
                ll chk = ccw(arr[se], arr[fi], arr[nxt]);
                if(chk > 0){ num.push_back(fi); break; }
            }
            num.push_back(nxt++);
        }

        for(auto& i : num) point.push_back(arr[i]);
        ll idx = point.size() - 1;
        while(ccw(point[0], point[idx], point[idx - 1]) == 0 && idx > 0) idx--;
        reverse(point.begin() + idx, point.end());
    }

    vector <pll> ret(){ return point; } // 좌표 반환
};


int main() {
    fastio;

    cin >> n; _ch ch;
    for(int i = 1;i <= n;i++){
        char c; cin >> a[i].x >> a[i].y >> c;
        if(c != 'N') ch.add(a[i]);
    }

    sort(all(ch.arr), [](_ch::node a, _ch::node b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
     
    for(int i = 1;i < ch.arr.size();i++){
        ch.arr[i].dx = ch.arr[i].x - ch.arr[0].x;
        ch.arr[i].dy = ch.arr[i].y - ch.arr[0].y;
    }
    sort(ch.arr.begin() + 1, ch.arr.end());

    ll idx = ch.arr.size() - 1;
    while(ch.ccw(ch.arr[0], ch.arr[idx], ch.arr[idx - 1]) == 0 && idx > 0) idx--;
    reverse(ch.arr.begin() + idx, ch.arr.end());

    cout << ch.arr.size() << "\n";
    for(auto& i : ch.arr) cout << i.x << " " << i.y << "\n";
     
     
    return 0;
}