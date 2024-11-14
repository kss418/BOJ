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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <pll, set<pll>> arr;
ll a[MAX][MAX], v[MAX][MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector <pll> num;
deque <pll> q;

int main() {
    fastio;

    cin >> n >> m >> k;
    while(k--){
        ll x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        arr[{y1, x1}].insert({y2, x2});
        arr[{y2, x2}].insert({y1, x1});
    }

    while(m--){
        ll y, x; cin >> y >> x;
        a[y][x] = 1;
        num.push_back({y, x});
    }

    ll result = 0;
    for(auto& cur : num){  
        memset(v, 0, sizeof(v));
        q.push_back(cur);

        while(!q.empty()){
            auto[cy, cx] = q.front(); q.pop_front();
            if(v[cy][cx]) continue; v[cy][cx] = 1;

            for(int i = 0;i < 4;i++){
                ll ny = cy + dy[i], nx = cx + dx[i];
                if(ny <= 0 || nx <= 0 || nx > n || ny > n) continue;
                if(arr[{cy, cx}].count({ny, nx})) continue;
                q.push_back({ny, nx});
            }
        }

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(!a[i][j]) continue;
                if(v[i][j]) continue;
                result++;
            }
        }
    }

    cout << (result >> 1);


    return 0;
}

