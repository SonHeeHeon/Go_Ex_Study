/*
 * Banking System Ver 0.1
*/

#include<iostream>

using namespace std;

void ShowMenus(void);

int main(void){

    int choice;

    while(1){
        ShowMenus();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }

    }

}

void ShowMenus(){

    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입금"<<endl;
    cout<<"3. 출금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

