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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool outrange(ll cy, ll cx){
    return (cy < 0 || cx < 0 || cy >= 3 || cx >= 3);
}

class node{
public:
    ll a[3][3], cy, cx;
    vector <node> nn(){
        vector <node> ret;
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            node now = *this; now.cy = ny; now.cx = nx;
            swap(now.a[cy][cx], now.a[ny][nx]);
            ret.push_back(now);
        }

        return ret;
    }

    ll num() const{
        ll ret = 0;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++) {
                ret += a[i][j]; ret *= 9;
            }
        }

        return ret;
    }

    bool operator < (const node& ot) const{
        return num() < ot.num();
    }
} st, en;
deque <pair<node, ll>> q;
map <node, ll> v;

int main() {
    fastio;

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++) {
            cin >> st.a[i][j];
            if(st.a[i][j]) continue;
            st.cy = i; st.cx = j;
        }
    }

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++) en.a[i][j] = i * 3 + j + 1;
        en.a[2][2] = 0; en.cy = 2; en.cx = 2;
    }

    q.push_back({st, 0});
    while(!q.empty()){
        auto[cur, cc] = q.front(); q.pop_front();
        if(!v.count(cur)) v[cur] = INF;
        if(v[cur] <= cc) continue; v[cur] = cc;

        for(auto& nxt : cur.nn()) {
            q.push_back({nxt, cc + 1});
        }
    }

    ll ret = (!v.count(en)) ? -1 : v[en];
    cout << ret;

     
    return 0;
}