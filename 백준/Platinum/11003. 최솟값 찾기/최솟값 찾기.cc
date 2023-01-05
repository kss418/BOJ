#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
int n;

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;




int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m, num;
    pair<int, int> cur;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push({ num,i });
        while (pq.top().second <= i - m) {
            pq.pop();
        }
        cout << pq.top().first << " ";
    }
    
  
    return 0;
}