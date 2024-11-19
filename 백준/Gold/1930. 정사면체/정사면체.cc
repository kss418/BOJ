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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[2][4];

bool rot(ll idx){
    vector <ll> arr;
    for(int i = 0;i < 4;i++){
        if(i == idx) continue;
        arr.push_back(a[1][i]);
    }
    if(idx == 1 || idx == 3) reverse(all(arr));

    for(int i = 0;i < 3;i++){
        if(a[0][1] != arr[i]) continue;
        if(a[0][2] != arr[(i + 1) % 3]) continue;
        if(a[0][3] != arr[(i + 2) % 3]) continue;
        return 1;
    }

    return 0;
}

bool chk(){
    for(int i = 0;i < 4;i++){
        if(a[0][0] != a[1][i]) continue;
        if(rot(i)) return 1;
    }

    return 0;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        ll result = 0;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 4;j++) cin >> a[i][j];
        }

        cout << chk() << "\n";
    }


    return 0;
}

