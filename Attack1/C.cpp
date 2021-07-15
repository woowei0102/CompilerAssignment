#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
char str[10000];
int top=0;// stack
char s;
int temp=0;
int tempG=0;
int tempF=0;
int i; 
int pn=-1;
/*/////////////////////////////////////////////
typedef enum {num=0, plus=1, minus=2, mul=3, div=4, lpr=5, pdr=6 
}type;*/
struct token{
	int type;
    int Val=0;
    int priority=-1;//0:(內 1:+- 2:*/ 3:正負 4:(外
    
}setG[10000],post[10000],stack[10000];
//////////////////////////////////////////
void arrange(){
    int i = 0;
    while(cin>>s){
       // if((s!=' ')||(s!='\n')){
            str[i++] =s; 
       // }    
    }
}
int atoi(char c){
    return (c-'0');
}
int ScanDigit(int t, int g){ //temp,tempG//
    if((*(str+t)>='0')&&(*(str+t)<='9')){
        if(setG[g-1].priority==3){
            if(setG[g-1].type==1){
               pn=0;
            }
            else if(setG[g-1].type==2){
                pn=1;
            }
            g--;
            tempG--;
        }
       
           
        setG[g].Val=setG[g].Val*10+atoi(*(str+t));
        setG[g].type = 0;
        setG[g].priority=-1;
        t++;
        ScanDigit(t,g);
    }
    else{
        if(pn==1)
            setG[g].Val=0-setG[g].Val;
        pn=-1;
         return t;
    }
        
}
void push(struct token s[] ,struct token item){
    if(item.priority==4)
        item.priority=0;
    top=top+1;
    stack[top]=item;
}
struct token pop(struct token s[]){
    struct token item;
   
        item=stack[top];
        top=top-1;
        return item;
    
    
    

}
void computePostfix(int t){
    int i=0;
    struct token x,y,z;
    while(i<t){
        if(post[i].type==0){
            push(stack,post[i]);
        }
        else{
            x=pop(stack);//2
            y=pop(stack);//1
            if(post[i].type==1){
                z.Val=y.Val+x.Val;
                z.type=0;
                z.priority=-1;
                printf("1: %d + %d = %d\n",y.Val,x.Val,z.Val);
            }
            else if(post[i].type==2){
                z.Val=y.Val-x.Val;
                z.type=0;
                z.priority=-1;
                printf("2: %d - %d = %d\n",y.Val,x.Val,z.Val);
            }
            else if(post[i].type==3){
                z.Val=y.Val*x.Val;
                z.type=0;
                z.priority=-1;
                printf("3: %d * %d = %d\n",y.Val,x.Val,z.Val);
            }
            else if(post[i].type==4){
                z.Val=y.Val/x.Val;
                z.type=0;
                z.priority=-1;
                printf("4: %d / %d = %d\n",y.Val,x.Val,z.Val);
            }
            push(stack,z);
            
        }
        i++;
    }
    printf("%d\n",stack[1].Val);
}
void postfix(int t){
    int i = 0;
    int k = 0;
    struct token y;
    while(i<t){
        if(setG[i].type==0){
            post[k++]=setG[i];
        }
        else{
            if(setG[i].type==6){
                do{
                    y=pop(stack);    
                    if(y.type!=5)
                        post[k++]=y;
                }while(y.type!=5);
               
                tempF+=2;
                
            }
            else{
                if(top==0){
                    push(stack,setG[i]);
                }
                else if(setG[i].priority>stack[top].priority){
                    push(stack,setG[i]);
                    
                }
                else{
                    do{
                    
                    y=pop(stack); 
                    post[k++]=y;
                    }while(setG[i].priority>y.priority); 
                    push(stack,setG[i]);
                  
                }
               
            }
        }
        i++;
    }
   
     while(top!=0){
        y=pop(stack);
        post[k++]=y;
    }
}
void Scan(){
    while(*(str+temp)!='\0'){
        if((*(str+temp)>='0')&&(*(str+temp)<='9')){
           temp =  ScanDigit(temp,tempG)-1;
           setG[tempG++].type = 0;
        }
        else if(*(str+temp)=='+'){
            if((setG[tempG-1].type>0)&&(setG[tempG-1].type<=5)){
                setG[tempG].priority = 3;
                setG[tempG++].type = 1;
            }
            else{
                setG[tempG].priority = 1;
                setG[tempG++].type = 1;
            }
            if((*(str+temp-1)=='*')||(*(str+temp-1)=='/')){
                pn=0;
            }
            
        }
        else if(*(str+temp)=='-'){
            if((setG[tempG-1].type>0)&&(setG[tempG-1].type<=5)){
                setG[tempG].priority = 3;
                setG[tempG++].type = 2;
            }
            else{
                setG[tempG].priority = 1;
                setG[tempG++].type = 2;
            }
            if((*(str+temp-1)=='*')||(*(str+temp-1)=='/')){
                pn=0;
            }
        }
        else if(*(str+temp)=='*'){
            setG[tempG].priority = 2;
            setG[tempG++].type = 3;
        }
        else if(*(str+temp)=='/'){
            setG[tempG].priority = 2;
            setG[tempG++].type = 4;
        }
        else if(*(str+temp)=='('){
            setG[tempG].priority = 4;
            setG[tempG++].type = 5;
        }
        else if(*(str+temp)==')'){
            setG[tempG++].type = 6;
        }
        temp++;
    }
}
////////////////////////////////////////////////////
int main(){
    arrange();
    cout << str;
    Scan();
    postfix(tempG);
    computePostfix(tempG-tempF);
   // printf("tempG: %d\n",tempG);
   /*    for(int i=0;i<(tempG-tempF);i++){
        //printf("%d %d %d\n",setG[i].type,setG[i].Val,setG[i].priority);
        printf("%d %d %d\n",post[i].type,post[i].Val,post[i].priority);
    }*/
    
}