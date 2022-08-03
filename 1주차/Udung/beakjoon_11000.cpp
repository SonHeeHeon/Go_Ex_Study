#include <iostream>

int h[400001][2];
int last_index = 0;

inline void swap(int* a, int* b) {
	int temp[2];
	temp[0] = a[0];
	temp[1] = a[1];
	a[0] = b[0];
	a[1] = b[1];
	b[0] = temp[0];
	b[1] = temp[1];
}

bool comp(int a[], int b[]) {
	if (a[0] > b[0])
		return false;
	if (a[0] == b[0]) {
		if (a[1] > b[1])
			return false;
	}
	return true;

}

void push(int in[]) {
	int index = ++last_index;

	while (index > 1 && comp(in, h[index / 2])) {
		h[index][0] = h[index / 2][0];
		h[index][1] = h[index / 2][1];
		index /= 2;
	}
	h[index][0] = in[0];
	h[index][1] = in[1];
}

int* pop() {
	int* output = new int[2];
	output[0] = h[1][0];
	output[1] = h[1][1];
	if (last_index == 1) {
		last_index = 0;
		return output;
	}

	h[1][0] = h[last_index][0];
	h[1][1] = h[last_index--][1];

	int parent = 1;
	int child = 2;

	while (child <= last_index) {
		if (child < last_index && !comp(h[child], h[child + 1]))
			child++;

		if (comp(h[parent], h[child])) {
			break;
		}

		swap(h[child], h[parent]);
		parent = child;
		child *= 2;
	}

	return output;
}

int main() {
	int N;
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		int start, end;
		std::cin >> start >> end;
		int arr[] = { start,1 };
		int arr2[] = { end,-1 };
		push(arr);
		push(arr2);
	}

	int cnt = 0;
	int max = 0;
	while (last_index >= 1) {
		register int* out = pop();
		cnt += out[1];

		max = max < cnt ? cnt : max;
	}
	std::cout << max;
}