#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
char str[1000];
char s;
int temp=0;
int tempG=0;
int i; 
/*/////////////////////////////////////////////
typedef enum {num=0, plus=1, minus=2, mul=3, div=4, lpr=5, pdr=6 
}type;*/
struct token{
	int type;
    int Val=0;
};
struct token setG[1000];
//////////////////////////////////////////
void arrange(){
    int i = 0;
    while(cin>>s){
        if((s!=' ')||(s!='\n')){
            str[i++] =s; 
        }    
    }
}
int atoi(char c){
    return (c-'0');
}
int ScanDigit(int t, int g){
    if((*(str+t)>='0')&&(*(str+t)<='9')){
        setG[g].Val=setG[g].Val*10+atoi(*(str+t));
        t++;
        ScanDigit(t,g);
    }
    else
         return t;
}
void Scan(){
    while(*(str+temp)!='\0'){
        if((*(str+temp)>='0')&&(*(str+temp)<='9')){
           temp =  ScanDigit(temp,tempG)-1;
           setG[tempG++].type = 0;
        }
        else if(*(str+temp)=='+'){
                setG[tempG++].type = 1;
        }
        else if(*(str+temp)=='-'){
            setG[tempG++].type = 2;
        }
        else if(*(str+temp)=='*'){
            setG[tempG++].type = 3;
        }
        else if(*(str+temp)=='/'){
            setG[tempG++].type = 4;
        }
        else if(*(str+temp)=='('){
            setG[tempG++].type = 5;
        }
        else if(*(str+temp)==')'){
            setG[tempG++].type = 6;
        }
        temp++;
    }
    for(i=0;i<tempG;i++){
        switch(setG[i].type){
            case 0:
                printf("NUM %d\n",setG[i].Val);
                break;
            case 1:
                printf("PLUS\n");
                break;
            case 2:
                printf("MINUS\n");
                break;
            case 3:
                printf("MUL\n");
                break;
            case 4:
                printf("DIV\n");
                break;
            case 5:
                printf("LPR\n");
                break;
            case 6:
                printf("RPR\n");
                break;

        }
    }
}
////////////////////////////////////////////////////
int main(){
    arrange();
    Scan();
   // cout << str;
}