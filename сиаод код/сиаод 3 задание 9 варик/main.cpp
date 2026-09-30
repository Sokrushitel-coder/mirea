#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int len = 1000;
void main1(){
    char a[len], e[1],a1[len];
    int j=0;
    while((a[j]=getchar())!=EOF){
        if (a[j]=='\n' and j!=0){
            break;
        }
        j++;
    }
    //scanf("%s",a);
    //printf(a);
    scanf("%s",e);
    printf("Ответ:");
    putchar('\n');
    if (e[0]=='Y'){
        for (int i=1;i<j;i++){
            if (48>a[i] or a[i]>57){
                putchar(a[i]);
            }

        }

    }
    else if (e[0]=='N') {
        int q=0;

        for (int i=1;i<j;i++){
            if (48>a[i] or a[i]>57){
                putchar(a[i]);
            } else {

                a1[q]=a[i];
                q++;
            }

        }
        putchar(a1[q-1]);
        for (int r=1;r<q-1;r++){
            putchar(a1[r]);
        }
        putchar(a1[0]);
    }
}

int main() {
    system("chcp 1251");
    while (1) {

        cout << endl << "Введите номер задания (1 или 2)" << endl;
        int choose;
        cin >> choose;
        cout << "Введите в первой строке предложение, а во второй - управляющий символ (Y/N)" << endl;
        switch (choose) {
        case (1): {
            main1();
            break;
            //return 0;
        }
        case (2):{
            string s,e,s1;
            cin>>s;
            //cout<<s<<endl;

            cin>>e;
            cout<<"Ответ:\n";
            if (e=="Y"){
                for (int i=0;i<s.length();i++){
                    if (48>s[i] or s[i]>57){

                        cout<<s[i];
                    }

                }

            }
            else if (e=="N") {
                int q=0;
                for (int i=0;i<s.length();i++){
                    if (48>s[i] or s[i]>57){
                        cout<<s[i];
                    } else {

                        s1[q]=s[i];
                        q++;

                    }

                }
                cout<<s1[q-1];
                for (int r=1;r<q-1;r++){
                    cout<<s1[r];
                }
                cout<<s1[0];
            }

        }


        }
    }
}
