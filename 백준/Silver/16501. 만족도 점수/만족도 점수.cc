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
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
ll a[MAX], cnt[4], result[3], mx;
vector <ll> num;

void bt(){
    if(num.size() == 8){
        ll na = 0, nb = 0;
        for(int i = 0;i < 8;i++){
            if(!num[i]) na += a[i];
            else if(num[i] == 1) na -= a[i];
            else if(num[i] == 2) nb += a[i];
            else nb -= a[i];
        }
        na = 5 * abs(na); nb =  5 * abs(nb);

        ll sa = 100 - na, sb = 100 - nb;
        mx = max(min(sa, sb), mx);
    
        return;
    }

    for(int i = 0;i < 4;i++){
        if(cnt[i] >= 2) continue;
        num.push_back(i); cnt[i]++;
        bt();
        num.pop_back(); cnt[i]--;
    }
}

int main() {
    fastio;

    for(int i = 0;i < 8;i++) cin >> a[i]; bt();
    result[0] = mx / 100; mx -= result[0] * 100;
    result[1] = mx / 10;
    result[2] = mx % 10;

    cout << result[0] << "." << result[1];
    if(result[2]) cout << result[2];

    return 0;
}