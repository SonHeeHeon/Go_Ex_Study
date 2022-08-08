//Count Circle Gropus

#include<iostream>
int parent[3000];

inline int cal(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}
void union_parent(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}
int main() {
	int T, N;

	std::cin >> T;
	int dot[3000][3];
	for (int i = 0; i < T; i++)
	{
		std::cin >> N;

		for (int i = 0; i < N; i++)
			std::cin >> dot[i][0] >> dot[i][1] >> dot[i][2];

		for (int i = 0; i < N; i++)
			parent[i] = i;

		int res;
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (parent[i] == parent[j]) continue;

				res = cal(dot[i][0], dot[i][1], dot[j][0], dot[j][1]);
				if (res <= (dot[i][2] + dot[j][2]) * (dot[i][2] + dot[j][2])) {
					union_parent(i, j);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++)
			if (parent[i] == i) ans++;

		std::cout << ans << std::endl;
	}
}