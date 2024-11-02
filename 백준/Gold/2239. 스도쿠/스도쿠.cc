#include <bits/stdc++.h>
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
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
string st[MAX];
vector <ll> arr;
bool flag;
ll x[MAX][MAX], y[MAX][MAX], sq[MAX][MAX];


void bt(ll cur){
    if(flag) return;
    if(arr.size() == 81){
        flag = 1;
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++) cout << arr[i * 9 + j];
            cout << "\n";
        }
        return;
    }

    ll cy = cur / 9, cx = cur % 9;
    ll now = (cy / 3) * 3 + cx / 3;
    if(st[cy][cx] == '0'){
        for(int i = 1;i <= 9;i++){
            if(sq[now][i] || x[cx][i] || y[cy][i]) continue;
            sq[now][i] = x[cx][i] = y[cy][i] = 1;
            arr.push_back(i);
            bt(cur + 1);
            arr.pop_back();
            sq[now][i] = x[cx][i] = y[cy][i] = 0;
        }
    }
    else{
        arr.push_back(st[cy][cx] - '0');
        bt(cur + 1);
        arr.pop_back();
    }
}

int main() {
    fastio;

    for(int i = 0;i < 9;i++) {
        cin >> st[i];
        for(int j = 0;j < 9;j++){
            if(st[i][j] == '0') continue;
            x[j][st[i][j] - '0'] = 1;
            y[i][st[i][j] - '0'] = 1;
            ll now = (i / 3) * 3 + j / 3;
            sq[now][st[i][j] - '0'] = 1;
        }
    }
    bt(0);


    return 0;
}

