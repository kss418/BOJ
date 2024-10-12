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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1 << 11;
constexpr ll MOD = 998244353;
ll mx[MAX];
char result[MAX][MAX];

void dnc(ll cx, ll cy, ll si){
    if(si == 0){
        result[cy][cx] = '*';

        mx[cy] = max(mx[cy], cx);
        return;
    }

    ll nxt = si >> 1;
    dnc(cx, cy, nxt);
    dnc(cx + nxt, cy, nxt);
    dnc(cx, cy + nxt, nxt);
}

int main() {
    fastio;

    cin >> n;
    dnc(0, 0, (1 << n));

    for(int i = 0;i < (1 << n);i++){
        for(int j = 0;j <= mx[i];j++){
            if(result[i][j] == '*') cout << '*';
            else cout << " ";
        }
        cout << "\n";
    }


    return 0;
}