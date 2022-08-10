#include <iostream>
#include <cmath> 

using namespace std;

typedef struct POINT{
    int x,y,r;
};

inline int dist(POINT startPoint,POINT endPoint){
    return pow(startPoint.x-endPoint.x,2)+pow(startPoint.y-endPoint.y,2);
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

// 이건 맞음
// 이상한데?? 피타고라스 쓰면 제곱 제곱 더한 후 제곱근 해줘야 하지 않나?