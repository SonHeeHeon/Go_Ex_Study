#include <iostream>
//14226번 이모티콘

class Emoj {
public:
	int num;
	int sec;
	int clip;
public:
	Emoj() {
		num = 0;
		sec = 0;
		clip = 0;
	}

	Emoj(int num, int sec, int clip) {
		this->num = num;
		this->sec = sec;
		this->clip = clip;
	}
};
class Queue {
public:
	Emoj que[65536];
	unsigned short front;
	unsigned short rear;

public:
	Queue() {
		for (size_t i = 0; i < 65536; i++) this->que[i] = Emoj();
		this->front = 0;
		this->rear = 0;
	}
	void push(Emoj emoj) {
		this->que[rear].num = emoj.num;
		this->que[rear].sec = emoj.sec;
		this->que[rear].clip = emoj.clip;

		this->rear++;
	}
	Emoj pop() {
		if (this->front != this->rear) {
			register Emoj res = this->que[this->front++];

			return res;
		}
	}
};


int main() {
	int result;
	std::cin >> result;
	Queue queue = Queue();


	int visit[2000];
	Emoj answer = Emoj();

	queue.push(Emoj(1, 1, 1));
	while (queue.front != queue.rear) {
		Emoj que = queue.pop();

		if (que.num >= 2000) continue;
		if (que.num == result) {
			answer = que;
			break;
		}

		if (que.clip != 0) {
			queue.push(Emoj(que.num + que.clip, que.sec + 1, que.clip));//붙여넣기
		}
		if (visit[que.num] != 1) {
			queue.push(Emoj(que.num, que.sec + 1, que.num));//클립보드 복사
			if (que.num >= 2) queue.push(Emoj(que.num - 1, que.sec + 1, que.clip)); //삭제
			visit[que.num] = 1;
		}
	}

	std::cout << answer.sec;
}