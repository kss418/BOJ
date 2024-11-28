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
char a[MAX];
string result;


int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll l = 1, r = n;
    while(l <= r){
        if(a[l] < a[r]) result.push_back(a[l]), l++;
        else if(a[r] < a[l]) result.push_back(a[r]), r--;
        else{
            ll nr = r, nl = l;
            while(a[nr] == a[nl] && nl < nr) nr--, nl++;
            if(a[nr] > a[nl]) result.push_back(a[l]), l++;
            else result.push_back(a[r]), r--;
        }
    }

    for(int i = 0;i < result.size();i++){
        cout << result[i];
        if(i % 80 == 79) cout << "\n";
    }

     
    return 0;
}