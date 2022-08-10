// 백준 6416 트리인가

#include <iostream>
int parent[14];
int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}
int main() {
	int a, b;
	bool flag = true;
	int test = 1;
	bool check[14];

	while (flag) {
		bool tree = true;
		for (int i = 0; i < 14; i++) {
			parent[i] = i;
			check[i] = false;
		}

		while (true) {
			std::cin >> a >> b;
			if (a == 0 && b == 0) break;
			if (a == -1 && b == -1) {
				flag = false;
				break;
			}
			check[a] = true;
			check[b] = true;
			int pa = find(a);
			int pb = find(b);

			if (pa == pb) 
				tree = false;
			
			parent[pb] = pa;
		}

		int prev = 0;
		bool first = true;
		for (int i = 1; i < 14; i++)
		{	
			find(i);
			if (first && check[i]) {
				prev = parent[i];
				first = false;
			}
			if (check[i] && prev != parent[i]) {
				tree = false;
			}			
		}

		if (tree && flag) {
			std::cout << "Case " << test << " is a tree." << std::endl;
		}
		else if (!tree && flag) {
			std::cout << "Case " << test << " is not a tree." << std::endl;
		}

		test++;
	}
}