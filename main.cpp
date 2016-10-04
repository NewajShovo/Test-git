#include <bits/stdc++.h>
using namespace std;
const int N_ = 1050;
int N;
int P[N_];
char S[N_];
///my name is shovo///
int group[N_];

int Find(int x) {
	if(group[x]==x) return x;
	return group[x]=Find(group[x]);
}

void Union(int a, int b) {
	group[Find(b)]=Find(a);
}

vector<int> pos[N_];
int cnt[N_];

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) group[i] = i;

	for (int i = 1; i <= N; i++) scanf("%d", &P[i]);
	for (int i = 1; i <= N; i++) {
		scanf("%s", S + 1);
		for (int j = 1; j <= N; j++) if (S[j] == '1') Union(i, j);
	}

	for (int i = 1; i <= N; i++) pos[Find(i)].push_back(P[i]);
	for (int i = 1; i <= N; i++) sort(pos[i].begin(), pos[i].end());

	for (int i = 1; i <= N; i++) {
		int g = Find(i);
		printf("%d%c", pos[g][cnt[g]++], (i == N) ? '\n' : ' ');
	}


	return 0;
}
