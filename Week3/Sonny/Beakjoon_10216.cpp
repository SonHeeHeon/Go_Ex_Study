#include <iostream>
#include <cmath> 

using namespace std;

typedef struct POINT{
    int x,y,r;
};

inline double dist(POINT startPoint,POINT endPoint){
    return sqrt(pow(std::abs(startPoint.x-endPoint.x),2)+pow(std::abs(startPoint.y-endPoint.y),2));
}

int find(int a,int arr[]){
    if(arr[a] == a) return a;
    return arr[a] = find(arr[a],arr);
}

void link_group(int a,int b,int arr[]){
    a = find(a,arr);
    b = find(b,arr);
    arr[a] = b;
}

void solve(){

    int N;
    POINT points[3000+2];
    int groups[3000+2];
    int result=0;

    cin>>N;
    for (size_t i = 1; i <= N; i++)
    {
        cin>>points[i].x>>points[i].y>>points[i].r;
        groups[i]=i; 
    }

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = i+1; j <= N; j++)
        {
            if(dist(points[i],points[j])<=points[i].r+points[j].r){ 
                link_group(i,j,groups);
            }
        }
        
    }
    
    for (size_t i = 1; i <=N; i++)
    {
        if(groups[i]!=i) result++;
    }
    
    cout<<result<<endl;
    
}

int main(){

    int T;
    int N;
    POINT points[5000+2];

    cin>>T;

    for (size_t i = 0; i < T; i++)
    {
        solve();
    }

    return 0;
}

// 의문 : 클래스를 만들어서 어떻게 풀 수 있는가?
// dist 계산 유정이랑 다른데 어떤 차이 ?
// 리스트 써도 되나?
// 연결 리스트 문제인가?
// cmath 라이브러리 써도 되는지 확인 

/*
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = i; j <= N; j++) 
    => 이러면 nlogn 시간인가? n*(n-1) 인가?
*/