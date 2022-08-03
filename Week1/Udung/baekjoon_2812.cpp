#include <iostream>
//baekjoon 2812 ũ�Ը����


class Stack {
public:
	int n[500001];
	int rear = 0;

	Stack() {}

	char pop() {
		if (this->rear != 0){
			return n[--this->rear];
		}
		return 0;
	}
	void push(char k) {
		this->n[this->rear++] = k;
	}
	char peek() {
		if (this->rear > 0) return this->n[this->rear - 1];
		return 0;
	}

};


int main() {
	char num[500001];
	Stack st;
	int N, K;

	std::cin >> N >> K;
	std::cin >> num;


	for (register int i = 0; i < N; i++)
	{
		int cur = num[i] - '0';
		while (st.rear != 0 && K > 0 && cur > st.peek()) {
			st.pop();
			K--;
		}
		st.push(cur);
	}

	for (register int i = 0; i < K; i++) st.pop();

	for (register int i = 0; i < st.rear; i++)
	{
		std::cout << st.n[i];
	}
}

