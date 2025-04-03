#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 20101;
ll n, m, a[MAX];
pair <ll, ll> b[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i].first >> b[i].second;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    ll idx = 1, result = 0;
    for(int i = 1;i <= n;i++){
        while(b[idx].first <= a[i] && idx <= m){
            pq.push(b[idx].second);
            idx++;
        }

        while(!pq.empty() && pq.top() < a[i]) pq.pop();
        if(!pq.empty()){
            result++; pq.pop();
        }
    }

    cout << result;

    return 0;
}

