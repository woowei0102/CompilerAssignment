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
}setG[1000];
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
/////////////Grammer原型宣告//////////////////////////////////////////
int factor(int x);
int term_tail(int x);
int expr_tail(int x);
int term(int x);
int expr(int x);
//////////////////////////////////////////////////////////////
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
    expr(0);//Grammer;
}
////////////////////////////////////////////////////
int main(){
    arrange();
    Scan();
    //cout << str;
}
//////////////////Grammer///////////////////////////
int factor(int i){
    printf("factor\n");
    if(setG[i].type==5){
        i++;
        i=expr(i)+1;
         return i;
    }
    else if((setG[i].type==1)||(setG[i].type==2)){
        i+=2;
        return i;
    }
    else if(setG[i].type==0){
        i++;
        return i;
    }

}
int term_tail(int i){
    printf("term_tail\n");
     if((setG[i].type==3)||(setG[i].type==4)){
         i++;
         return term_tail(factor(i));
     }
     else 
        return i;
}
int expr_tail(int i){
     printf("expr_tail\n");
    // printf("%d\n",i);
     if((setG[i].type==1)||(setG[i].type==2)){     
         i++;
        return expr_tail(term(i));
     }
     else  
        return i;
}
int term(int i){
    printf("term\n");
    return term_tail(factor(i));
}
int expr(int i){
printf("expr\n");
return expr_tail(term(i));
}
///////////////////////////////////////////////////////