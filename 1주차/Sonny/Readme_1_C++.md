# 열혈 C++ 정리

## 1장 C++ 으로 전환 (~55)

1. std::cout<< 

    출력함수 (c에서의 %s 처럼 포맷 지정이 필요없음)
    
    아래와 같은 방식으로 출력
    - std::cout<<'  '<<3.14<<"abs";
    - std::cout<<'ab'<<std::endl;

        std::endl는 개행 을 출력

2. std::cin>>
    
    입력함수 (c에서의 %s 처럼 포맷 지정이 필요없음)

    아래와 같은 방식으로 입력
    - std::cin>>number1
    - std::cin>>num1>>num2

3. 오버로딩

    c는 함수의 이름으로만 호출대상을 찾으므로 오버로딩이 안되지만 c++은 파라미터와 함께 호출대상을 찾으므로 오버로딩이 가능

4. 매개변수 초기값 설정

    c++에서는 초기값도 설정 할 수 있다. 다른 언어를 해봤으면 알겠지만 오른쪽부터 매개변수 디폴트값을 채워야 한다

5. 인라인 함수

    실행속도에 이점이 있는 인라인 함수는 c에선 정의가 어려운 단점이 있었지만 c++에선 아래의 방법으로 사용 되어 정의가 어렵지 않다.

    #define SQUARE(x) ((x)*(x))

    inline int SQUARE(int x){
        return x*x;
    }

6. Namespace

    namespace라는 별도의 공간을 만들어 그 안에서 함수와 변수명을 외부와 겹치지 않게 하기 위함
    => practice.c++ 참고

    std::cout 에서 std 도 namespace 이다 std namespace의 cout을 좀 더 간편하게 쓸려면 using std::cout; 을 해주면 cout 만 이용해도 std namespace 에서 쓴다는걸 알 수 있다.

    혹은 using namespace std; 를 해주면 std namespace에 선언된 모든 것에 대해 namespace 지정의 생략이 된다.

    혹은 아래처럼 별칭을 줄 수 도 있다. (AAA 네임스페이스 안에 BBB, BBB네임스페이스 안에 CCC, CCC 안에 함수 또는 변수를 이용할려면 AAA::BBB:CCC ~ 인데 이를 줄여서 ABC로 쓸수있는거임)

    namespace ABC = AAA::BBB::CCC; 

## 2장 c언어 기반의 C++ (~102)

1. 참조자

    참조자는 자신이 참조하는 변수를 대신할 수 있느 또 하나의 이름입니다.      
    int num1=10;  
    int &num2=num1;   
    - 쓰는 방법은 그냥 변수와 동일함!
    - 참조자는 변수를 참조해야되지 만약 값을 선언하거나 비어두는것은 불가능하다.

2. 참조자와 함수 
    
    - Call by Value
    - Call by reference     
      여기서 참조자의 활용이 됨





+ c++에서는 bool 자료형 가능

## 3장 클래스의 기본 