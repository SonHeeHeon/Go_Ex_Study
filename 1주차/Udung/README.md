# 익스에 필요한 C++ 

### 1. 입출력  

```c++
#include <iostream>

// 입력 : 화살표 >> 오른쪽
std::cin >> num1
    
// 출력 : std::endl은 개행(안써도 무방), 화살표 << 왼쪽
std::cout << "출력" << num1 << std::endl;  

```



### 2. 클래스

```c++
class Emoj {
public:
	int num;
	int sec;
	int clip;
public:
	Emoj() { // 생성자 선언 아무것도 없으면 기본 생성자 자동 생성.
		num = 0;
		sec = 0;
		clip = 0;
	}

	Emoj(int num, int sec, int clip) { // 하나라도 생성자 선언시 기본생성자 자동생성x
		this->num = num;
		this->sec = sec;
		this->clip = clip;
	}
};

int main(){
   Emoj emoj;
   Emoj emoj = Emoj();// 위아래 같음.  
}
```

