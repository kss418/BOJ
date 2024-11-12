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
constexpr ll MAX = 201010; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[MAX], num[MAX];

int main() {
    fastio;

    cin >> n; num[0] = num[1] = 0;
    for(int i = 2;i <= n;i++){
        vector <ll> arr;
        for(int j = 0;j <= i - 2;j++){
            arr.push_back(num[i - j - 2] ^ num[j]);
        }
        sort(all(arr)); 

        ll cur = 0;
        for(auto& i : arr) if(i == cur) cur++;
        
        num[i] = cur;
    }

    if(!num[n]) cout << 2;
    else cout << 1;
    
    return 0;
}