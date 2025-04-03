#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, m, a[MAX];
ll sum[MAX];

ll cal(ll s, ll e){
    return sum[e] - sum[s - 1];
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    while(m--){
        ll s, e; cin >> s >> e;
        cout << cal(s, e) << "\n";
    }

    return 0;
}

