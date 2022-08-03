#include <iostream>

/*
매개변수 디폴트 값 관련 예제
*/

// int Adder(int a,int b=20,int c=10);

// int main(void){

//     std::cout<<Adder(5)<<std::endl;
//     std::cout<<Adder(5,7)<<std::endl;
//     std::cout<<Adder(1,2,3)<<std::endl;
//     return 0;
// }

// int Adder(int a,int b,int c){
//     return a+b+c;
// }

/*
Namespace 관련 예제
*/

namespace BestComImple{
    void SimpleFunc(void);
}

namespace BestComImple{
    void PrettyFunc(void);
}

namespace ProgComImple{
    void SimpleFunc(void);
}

int main(void){
    BestComImple::SimpleFunc();
    return 0;
}

void BestComImple::SimpleFunc(){
    PrettyFunc(); // 같은 namespace 이므로 네임스페이스를 안써도 됨
    ProgComImple::SimpleFunc();
}

void BestComImple::PrettyFunc(){
    std::cout<<"abc"<<std::endl;
}

void ProgComImple::SimpleFunc(){
    std::cout<<"sdc"<<std::endl;
}


