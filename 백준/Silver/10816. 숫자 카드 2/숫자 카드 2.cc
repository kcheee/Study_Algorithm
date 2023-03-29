#include <iostream>
using namespace std;

int card[20000001];
int main() {
	int N, M, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		card[tmp + 10000000]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		printf("%d ", card[tmp + 10000000]);
	}
}