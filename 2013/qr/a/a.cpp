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

char f[4][5];
int max_oc = 0;
int max_xc = 0;
int dc = 0;
int tc = 0;
int oc = 0;
int xc = 0;

void check(int i, int j){
	switch (f[i][j]) {
	case 'X':
		oc = 0;
		xc += 1;
		break;
	case 'O':
		oc += 1;
		xc = 0;
		break;
	case 'T':
		tc += 1;
		break;
	case '.':
		dc += 1;
		break;
	}
	if (oc==3 && tc>0) oc += 1;
	if (xc==3 && tc>0) xc += 1;
	if (oc>3 && max_oc < oc) max_oc = oc;
	if (xc>3 && max_xc < xc) max_xc = xc;
}

void main2(void){
	int i,j;
	char nl[4];
	REP(i,4)
		cin >> f[i];
	max_oc = 0;
	max_xc = 0;
	dc = 0;
	REP(i,4) {
		oc = 0; xc = 0; tc = 0;
		REP(j,4)
			check(i,j);
	}
	REP(j,4) {
		oc = 0; xc = 0; tc = 0;
		REP(i,4)
			check(i,j);
	}
	oc = 0; xc = 0; tc = 0;
	REP(i,4)
		check(i,i);
	oc = 0; xc = 0; tc = 0;
	REP(i,4)
		check(i,3-i);
		
	if (max_oc > 3 || max_xc > 3) {
		if (max_oc > max_xc) {
			printf("O won");
		} else if (max_oc < max_xc) {
			printf("X won");
		} else {
			printf("Draw");
		}
	} else { 
		if (dc > 0) {
			printf("Game has not completed");
		} else {
			printf("Draw");
		}
	}
	printf("\n");
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
