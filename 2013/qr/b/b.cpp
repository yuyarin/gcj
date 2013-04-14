#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int a[128][128];
int N, M;

int check(int x, int y, int h){
	int i, j;
	int x_all = 1, y_all = 1;
	REP(i,N)
		if (a[i][y] > h) y_all = 0;
	REP(j,M)
		if (a[x][j] > h) x_all = 0;
	if (x_all || y_all)
		return 0;
	return 1;
}

void main2(void){
	int i, j, h;
	cin >> N >> M;
	REP(i,N) REP(j,M)
		cin >> a[i][j];
	REP(h,100) REP(i,N) REP(j,M) {
		if (a[i][j] <= h and check(i,j,h)) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
