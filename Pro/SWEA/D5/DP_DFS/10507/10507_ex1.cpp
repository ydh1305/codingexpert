#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int N, P;

int solve(vector<bool> visit, int end) {
    int sol = P + 1;
    int s = 1, e = 1;
    int cnt = 0;
    while(e <= end) {
        if(visit[e]) {
            e++;
            cnt++;
        }
        else {
            if(!P) {
                if(!visit[s]) P++;
                s++;
                cnt--;
            }
            else {
                P--;
                e++;
                cnt++;
            }
        }
        if(sol < cnt) sol = cnt;
    }
    return sol;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        vector<int> v;
        cin >> N >> P;
        for(int j = 0; j < N; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        vector<bool> visit(MAX);
        for(int j = 0; j < v.size(); j++) 
            visit[v[j]] = true;
        cout << '#' << i << ' ' << solve(visit, v[N - 1]) << '\n';
    }

    return 0;
}