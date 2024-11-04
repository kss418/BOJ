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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll a[MAX];

class _ch{
public:
    _ch() {}
    vector <ll> result;

    class node{
    public:
        ll x, y, dx, dy;
        node(pll a) : node(a.x, a.y, 1, 0) {};
        node(ll x, ll y, ll dx, ll dy){
            this->x = x; this->y = y;
            this->dx = dx; this->dy = dy;
        }

        bool operator <(node& ot){
            if(dy * ot.dx != dx * ot.dy) return dy * ot.dx < dx * ot.dy;
            if(y != ot.y) return y < ot.y;
            return x < ot.x;
        }

        operator pll(){ return { x, y }; }
    };
    vector <node> arr;

    ll ccw(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; // cw
        else if(num < 0) return -1; // ccw
        return 0;
    }
    
    void add(ll a, ll b) { add({a, b}); }
    void add(pll a){ arr.push_back(a); }

    void init(){
        sort(all(arr));
        for(int i = 1;i < arr.size();i++){
            arr[i].dx = arr[i].x - arr[0].x;
            arr[i].dy = arr[i].y - arr[0].y;
        }
        sort(arr.begin() + 1, arr.end());

        result.push_back(0); result.push_back(1);
        ll nxt = 2;

        while(nxt < arr.size()){
            while(result.size() >= 2){
                ll fi = result.back(); result.pop_back();
                ll se = result.back();
                ll chk = ccw(arr[se], arr[fi], arr[nxt]);
                if(chk > 0){ result.push_back(fi); break; }
            }
            result.push_back(nxt++);
        }
    }

    vector <ll> ret(){ return result; }
};

int main() {
    fastio;

    cin >> n; _ch ch;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        ch.add(a[i]);
    }
    ch.init();

    cout << ch.ret().size() << "\n";


    return 0;
}

