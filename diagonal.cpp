#include <iostream>
#include<vector>
using namespace std;

string winner(vector<int> a, vector<int> h, int n){
	int ap, bp;
	vector<int> ba(n), fa(n), fmin(n), bmin(n);
	fa[0] = a[0];
	fmin[0] = a[0];
	for(int i = 1; i < n; i++){
		fa[i] += fa[i - 1] + a[i];
		fmin[i] = min(fmin[a - 1], a[i]);
	}
	ba[0] = a[n - 1];
	for(int i = 1; i < n; i++){
		ba[i] += ba[i - 1] + a[n - i - 1];
		bmin[i] = min(bmin[i - 1], a[n - i - 1]);
	}
	ap = h[0] * a[0];
	bp = ba[1]
	for(int i = 1; i < n; i++){
		ap = h[i] * a[i];
		bp = 
	}
}

int main() {
	int q, n;
	cin>>q;
	for(int i = 0; i < q; i++){
		cin>>n;
		vector<int> a(n), h(n);
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < n; i++)
			cin>>h[i];
		cout<<winner(a, h, n);
		cout<<endl;
	}
}