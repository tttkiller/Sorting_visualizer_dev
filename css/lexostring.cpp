#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    map<char, ll> mpp;
    for (int i = 0; i < s.size(); i++) {
        mpp[s[i]]++;
    }

    string ans = "";
    ll s1 = 0, e = s.size();

    while (s1 <= e) {
        ll mid = (s1 + e) / 2;
        string temp = "";
        ll total_count = 0;
        for (auto it : mpp) {
            ll required = (it.second + mid - 1) / mid;
            total_count += required;
            temp.append(required, it.first);  
        }

        if (total_count <= n) {
            ans = temp;  
            e = mid - 1;  
        } else {
            s1 = mid + 1;  
        }
    }
    if (ans == "") {
        cout << -1 << endl;
    } else {
        if (ans.size() < n) {
            char smallest = ans[0];
            ll left = n - ans.size();
            string padding(left, smallest);
            ans = padding + ans;
        }
        sort(ans.begin(), ans.end());  
        cout << ans << endl;
    }

    return 0;
}
