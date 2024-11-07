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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
string st[5];

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < 4;i++) cin >> st[i];

    string result;
    for(int i = 0;i < n;i++){
        if(st[0][i] != st[2][i]) continue;
        if(st[1][i] != st[3][i]){
            cout << "htg!"; return 0;
        }
        result.push_back(st[1][i]);
    }

    for(auto& i : result) cout << i;
    
    
    return 0;
}