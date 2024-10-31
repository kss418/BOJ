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
constexpr ll MAX = 51;
constexpr ll MOD = 998244353;
ll si[MAX];
map <ll, char> dp[MAX];

char dnc(ll cur, ll cnt){
    if(dp[cur].count(cnt)) return dp[cur][cnt];
    char&ret = dp[cur][cnt];
    if(!cnt || !cur) return ret = '-';

    if(cnt >= si[cur - 1] + 1) ret = dnc(cur - 2, cnt - si[cur - 1] - 1);
    else ret = dnc(cur - 1, cnt);

    return ret;
}

int main() {
    fastio;

    cin >> n;
    si[1] = 5; si[2] = 13;
    for(int i = 3;i <= 41;i++) si[i] = si[i - 1] + si[i - 2] + 1;

    s = "Messi-Gimossi";
    for(int i = 1;i <= 5;i++) dp[1][i] = s[i - 1];
    for(int i = 1;i <= 13;i++) dp[2][i] = s[i - 1];

    char ret = dnc(41, n);
    if(ret == '-') cout << "Messi Messi Gimossi";
    else cout << ret;


    return 0;
}

