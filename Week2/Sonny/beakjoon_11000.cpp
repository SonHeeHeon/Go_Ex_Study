/*
 * 11000번 
 * 강의실 배정
 * 골드 5 문제
*/

#include<iostream>

using namespace std;

typedef struct TIME_TERM{
    int s;
    int t;
}TERM;

void swap(TERM &a,TERM &b){
    TERM temp =a;
    a = b;
    b= temp;
}

void sortTerm(int left,int right,TERM *terms){
    int pivot = left;
    int j = left;
    int i = j+1;

    for(;i<=right;i++){
        if(terms[j].s>terms[i].s){
            j++;
            swap(terms[j],terms[i]);
        }
    }
    swap(terms[j],terms[pivot]);
    pivot = j;

    sortTerm(left,pivot-1,terms);
    sortTerm(pivot+1,right,terms);
}

int main(){

    int N;
    int minRoom=1;
    TERM terms[200000+3];

    cin>>N;
    for (size_t i = 0; i < N; i++)
    {
        cin>>terms[i].s>>terms[i].t;
    }
    // 정렬 - 퀵소트
    sortTerm(0,N-1,terms);

    // 출력
    for (size_t i = 0; i < N; i++)
    {
        cout<<terms[i].s<<terms[i].t<<endl;
    }

    // 우선순위 큐 구현 
    // 우선순위는 - term[i].t 를 기준으로!

    // 알고리즘 구현
    // 현재 생각은 sort된 term으로 맨처음꺼 힙에 넣고 다음꺼 부터는 for 문 사용 
    // term[j].s랑 힙에 들어가있는 것 중 가장 위에꺼 (가장 작은거) 랑 비교했을때 
        // 1) term[j].s >= heap 맨위에 거의 t 값 : while 문 써서 heap에 term[j].s 보다 작은거 다 빼내기 
        // 2) term[j].s >= heap 맨위에 거의 t 값 : j가 힙에 들어감
        // 3) 힙의 크기 > minRoom 이면 minRoom = 힙의 크기

    cout<<minRoom;

    return 0;
}


/*
 * 힙 구현
 * 우선순위 큐 구현
 * 큐 구현
*/