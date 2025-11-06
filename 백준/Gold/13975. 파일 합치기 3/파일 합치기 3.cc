#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010101;
ll n, t, a[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

void solve(){
    cin >> n; ll result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i], pq.push(a[i]);
    while(pq.size() > 1){
        ll fi = pq.top(); pq.pop();
        ll se = pq.top(); pq.pop();
        result += fi + se;
        pq.push(fi + se);
    }

    pq.pop();
    cout << result << "\n";
}

int main(){
    cin >> t;
    while(t--) solve();
    return 0;
}