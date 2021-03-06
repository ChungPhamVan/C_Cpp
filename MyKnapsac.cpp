#include<bits/stdc++.h>
#define MAX 35
/*
Yeu cau: x1.c1 + x2.c2 + ... + xn.cn -> max
sao cho: x1.a1 + x2.a2 + ... + xn.an <= b
xi = {0,1}
VD: n = 5, x = {1,1,0,1,0} nghia la lay cac do vat 1,2,4 va ko lay cac do vat 3,5
*/
using namespace std;

int n,b;
int bk;		//tong trong luong con lai cua cai tui
int x[MAX];		//matrix kq
int a[MAX];		//ma tran khoi luong
int c[MAX];		//ma tran gia tri
vector< pair<int, int> > data;

int f=0;	//tong gia tri hien tai cua cac do vat dang co trong tui
int fopt = -1;	//f_optimize: ki luc: la gia tri su dung tot nhat

void input() {
	cin >> n >> b;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> c[i];
		data.push_back(make_pair(a[i], c[i]));
	}
}

void printSolution() {
	for(int i=0; i<n; i++) {
		cout<<x[i];
	}
	cout << endl;
}

bool compare(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second * 1.0/x.first > y.second*1.0/y.first;		//sap xep giam dan, chu y can chuyen sang dangj soos thwcj
}

void knapsac(int k) {
	int start = 0, end;
	if(bk < a[k]) end = 0;	//neu do vat thu k lon hon trong luong con lai cua tui thi ko the lay no!
	else end = 1;
	
	for(int i = start; i <= end; i++) {
		x[i] = i;
		bk = bk - i*a[k];
		f = f + i*c[k];
		if(k == n-1) {
			if(f > fopt) {
				fopt = f;	//update ki luc
				cout << "fopt toi uu nhat = " << fopt << endl;
				printSolution();
			}
		} else {
			if(f + bk*c[k+1]/a[k+1] > fopt) knapsac(k+1);	//su dung thuat toan nhanh can de giam bot cac truong hop ko can thiet
		}
		
		bk = bk + i*a[k];
		f = f - i*c[k];
	}
}

int main () {
	freopen("knapsac.txt", "r", stdin);
	input();
	std::sort(data.begin(), data.end(), compare);
	fopt = -1;
	f = 0;
	bk = b;
	knapsac(0);
	cout << fopt;
}


