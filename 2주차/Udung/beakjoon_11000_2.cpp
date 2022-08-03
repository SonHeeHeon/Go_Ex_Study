#include <iostream>
//sort : 시작시간 순으로 정렬
//solve : 끝나는 시간 순으로 정렬
//sort 하나씩 빼면서 solve의 끝나는 시간보다 작으면 강의실 배정 크면 pop하고 push
inline void swap(int* a, int* b) {
	int temp[2];
	temp[0] = a[0];
	temp[1] = a[1];
	a[0] = b[0];
	a[1] = b[1];
	b[0] = temp[0];
	b[1] = temp[1];
}
bool comp_sort(int a[], int b[]) {
	if (a[0] > b[0])
		return false;
	if (a[0] == b[0]) {
		if (a[1] > b[1])
			return false;
	}
	return true;

}
bool comp_solve(int a[], int b[]) {
	if (a[1] > b[1])
		return false;
	//if (a[1] == b[0]) {
	//	if (a[1] > b[1])
	//		return false;
	//}
	return true;

}
class Priority {
public:
	int time[200001][2];
	int last_index;
	bool flag;

	Priority(bool flag) {
		last_index = 0;
		this->flag = flag;
	}
	bool comp(int a[], int b[]) {
		if (this->flag) return comp_sort(a, b);
		return comp_solve(a, b);
	}
	void push(int in[]) {
		int index = ++this->last_index;

		while (index > 1 && comp(in, this->time[index / 2])) {
			this->time[index][0] = this->time[index / 2][0];
			this->time[index][1] = this->time[index / 2][1];
			index /= 2;
		}
		this->time[index][0] = in[0];
		this->time[index][1] = in[1];
	}

	int* pop() {
		int* output = new int[2];
		output[0] = this->time[1][0];
		output[1] = this->time[1][1];
		if (this->last_index == 1) {
			this->last_index = 0;
			return output;
		}

		this->time[1][0] = this->time[this->last_index][0];
		this->time[1][1] = this->time[this->last_index--][1];

		int parent = 1;
		int child = 2;

		while (child <= this->last_index) {
			if (child < this->last_index && !comp(this->time[child], this->time[child + 1]))
				child++;

			if (comp(this->time[parent], this->time[child])) {
				break;
			}

			swap(this->time[child], this->time[parent]);
			parent = child;
			child *= 2;
		}

		return output;
	}
};



int main() {
	int N;
	std::cin >> N;
	Priority sort=  Priority(true);
	Priority solve= Priority(false);

	for (size_t i = 0; i < N; i++)
	{
		int start, end;
		std::cin >> start >> end;
		int arr[] = { start,end };

		sort.push(arr);
	}

	int cnt = 0;
	int max = 1;
	int idx = sort.last_index;

	for (int i = 0; i < idx; i++) {
		int* arr = sort.pop();
		solve.push(arr);
		if (arr[0] >= solve.time[1][1]) {
			solve.pop();
		}
		max = max < solve.last_index ? solve.last_index : max;
	}
	std::cout << max;
}