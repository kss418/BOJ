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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result = INF;
ll ag[6] = { -1, 4, 2, 4, 4, 1 };
ll cnt[MAX][MAX];
ll dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

class node{
public:
    ll cy, cx, num;
};
vector <node> arr;
vector <ll> num;

void move(ll cy, ll cx, ll dy, ll dx, ll val){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return;
    if(a[cy][cx] == 6) return;
    cnt[cy][cx] += val;
    move(cy + dy, cx + dx, dy, dx, val);
}

void c1(ll idx, ll type, ll val){
    auto [cy, cx, num] = arr[idx];
    move(cy, cx, dx[type], dy[type], val);
}

void c2(ll idx, ll type, ll val){
    auto [cy, cx, num] = arr[idx];
    move(cy, cx, dx[type], dy[type], val);
    move(cy, cx, dx[(type + 2) % 4], dy[(type + 2) % 4], val);
}

void c3(ll idx, ll type, ll val){
    auto [cy, cx, num] = arr[idx];
    for(int i = 0;i < 2;i++){
        ll nxt = (type + i) % 4;
        move(cy, cx, dx[nxt], dy[nxt], val);
    }
}

void c4(ll idx, ll type, ll val){
    auto [cy, cx, num] = arr[idx];
    for(int i = 0;i < 3;i++){
        ll nxt = (type + i) % 4;
        move(cy, cx, dx[nxt], dy[nxt], val);
    }
}

void c5(ll idx, ll type, ll val){
    auto [cy, cx, num] = arr[idx];
    for(int i = 0;i < 4;i++){
        ll nxt = (type + i) % 4;
        move(cy, cx, dx[nxt], dy[nxt], val);
    }
}

void c(ll idx, ll type, ll val){
    ll num = arr[idx].num;
    if(num == 1) c1(idx, type, val);
    else if(num == 2) c2(idx, type, val);
    else if(num == 3) c3(idx, type, val);
    else if(num == 4) c4(idx, type, val);
    else c5(idx, type, val);
}

void bt(){
    if(num.size() == arr.size()){
        ll cur = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(!cnt[i][j]) cur++;
            }
        }

        result = min(result, cur);
        return;
    }

    for(int i = 0;i < ag[arr[num.size()].num];i++){
        c(num.size(), i, 1);
        num.push_back(i); 
        bt();
        num.pop_back(); 
        c(num.size(), i, -1);
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            if(a[i][j] == 6) cnt[i][j] = 1;
            if(a[i][j] && a[i][j] != 6){
                arr.push_back({i, j, a[i][j]});
            }
        }
    }

    bt(); cout << result;

     
    return 0;
}