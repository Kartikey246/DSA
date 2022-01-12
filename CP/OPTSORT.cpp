#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >>t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    vector<int> v =a;
	    sort(v.begin(),v.end());
	    multiset<int> s,t;
	    long long ans =0;
	    for(int i=0;i<n;i++){
	        s.insert(a[i]);
	        t.insert(v[i]);
	        if(s == t){
	            ans += (*s.rbegin() - *s.begin());
	            s.clear();
	            t.clear();
	        }
	    }
	    cout << ans << endl;
	}
}
