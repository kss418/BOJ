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
ll n, m, k, t; 

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class node{
public:
    ll x, y, z;
    ll dist(node& ot){
        ll dx = x - ot.x;
        ll dy = y - ot.y;
        ll dz = z - ot.z;
        return dx * dx + dy * dy + dz * dz;
    }

    friend istream& operator>>(istream& in, node& node) {
        in >> node.x >> node.y >> node.z;
        return in;
    }
};
node s, e;

int main() {
    fastio;

    cin >> s >> e >> n; ll sum = 0;
    for(int i = 1;i <= n;i++) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1);

    if(sum * sum < s.dist(e)) cout << "NO";
    else if(2 * a[n] - sum < 0) cout << "YES";
    else if((2 * a[n] - sum) * (2 * a[n] - sum) > s.dist(e)) cout << "NO";
    else cout << "YES";


    return 0;
}

