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
constexpr ll MAX = 13; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};

class node{
public:
    ll cy, cx, dir;
};
node num[MAX];
vector <ll> arr[MAX][MAX];

void st(ll cur, ll cy, ll cx, ll ny, ll nx){
    vector <ll> now; bool flag = 0;
    for(auto& i : arr[cy][cx]){
        if(i == cur) flag = 1;
        if(flag) now.push_back(i);
    }

    while(!arr[cy][cx].empty()){
        ll back = arr[cy][cx].back();
        arr[cy][cx].pop_back();
        if(back == cur) break;
    }

    for(auto& i : now) {
        num[i].cx = nx; num[i].cy = ny;
        arr[ny][nx].push_back(i);
    }
}

bool chk(ll cy, ll cx){
    return (cy <= 0 || cx <= 0 || cx > n || cy > n);
}

void rev(ll cur){
    ll cy = num[cur].cy, cx = num[cur].cx;
    vector <ll> now;
    while(!arr[cy][cx].empty()){
        ll back = arr[cy][cx].back();
        now.push_back(back); arr[cy][cx].pop_back();
        if(back == cur) break;
    }

    for(auto& i : now) arr[cy][cx].push_back(i);
}

void move(ll cur, ll cnt){
    ll cy = num[cur].cy;
    ll cx = num[cur].cx;
    if(arr[cy][cx][0] != cur) return;
    ll& dir = num[cur].dir;

    ll ny = cy + dy[dir];
    ll nx = cx + dx[dir];

    if(a[ny][nx] == 2 || chk(ny, nx)){
        if(cnt == 1) return;
        dir ^= 1; move(cur, cnt + 1);
    }
    else if(!a[ny][nx]) st(cur, cy, cx, ny, nx);
    else st(cur, cy, cx, ny, nx), rev(cur);
}

bool simulation(){
    for(int i = 1;i <= m;i++) {
        move(i, 0);
        node cur = num[i];
        if(arr[cur.cy][cur.cx].size() >= 4) return 0;
    }

    return 1;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= m;i++){
        ll cy, cx, dir; cin >> cy >> cx >> dir;
        num[i] = {cy, cx, dir - 1};
        arr[cy][cx].push_back(i);
    }

    ll t = 0;
    while(++t){
        if(t > 1000){ t = -1; break; }
        if(!simulation()) break;
    }

    cout << t;

     
    return 0;
}