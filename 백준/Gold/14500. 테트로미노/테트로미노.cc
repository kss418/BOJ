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
constexpr ll MAX = 501;
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result;
bool match[4][4][19];

void init(){
    for(int i = 0;i < 4;i++) match[0][i][0] = match[i][0][1] = 1;
    for(int i = 0;i < 2;i++) match[i][1][2] = 1;
    match[0][0][2] = match[1][2][2] = 1;
    
    for(int i = 0;i < 2;i++) match[1][i][3] = 1;
    match[0][1][3] = match[2][0][3] = 1;

    for(int j = 0;j < 3;j++) match[0][j][4] = match[1][j][5] = 1;
    match[1][2][4] = match[0][0][5] = 1;

    for(int j = 0;j < 3;j++) match[j][0][6] = match[j][1][7] = 1;
    match[0][1][6] = match[2][0][7] = 1;

    for(int i = 0;i < 3;i++){
        match[i][0][8] = match[i][1][9] = 1;
    }
    match[1][1][8] = match[1][0][9] = 1;

    for(int i = 0;i < 3;i++){
        match[0][i][10] = match[1][i][11] = 1;
    }
    match[1][1][10] = match[0][1][11] = 1;
    
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++) match[i][j][12] = 1;
    }

    for(int i = 0;i < 2;i++) match[i][1][13] = 1;
    match[1][0][13] = match[0][2][13] = 1;

    for(int i = 0;i < 2;i++) match[1][i][14] = 1;
    match[2][1][14] = match[0][0][14] = 1;

    for(int i = 0;i < 3;i++){
        match[1][i][15] = match[0][i][16] = 1;
    }
    match[0][2][15] = match[1][0][16] = 1;

    for(int i = 0;i < 3;i++){
        match[i][1][17] = match[i][0][18] = 1;
    }
    match[0][0][17] = match[2][1][18] = 1;
}

ll cnt(ll cy, ll cx, ll num){
    ll ret = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            ll ny = cy + i, nx = cx + j;
            if(ny <= 0 || nx <= 0 || ny > n || nx > m){
                if(match[i][j][num]) return -INF;
                continue;
            }

            ret += a[ny][nx] * match[i][j][num];
        }
    } 

    return ret;
}

int main() {
    fastio;

    init();

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    result = -INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int k = 0;k < 19;k++){
                result = max(result, cnt(i, j, k));
            }
        }
    }
        
    cout << result;


    return 0;
}

