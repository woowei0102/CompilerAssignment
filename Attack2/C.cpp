#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
string str;
char c;
int s,t=0;
int x=0,y=0,o=0;;
////////////////////////////////
struct FS{
    char nt;
    int empty=0;
    int eol=0;
    int repeat=0;
	int Fsum=0;
    int Gsum=0;
    char Fset[1000];
    char Gset[1000];
}F[1000];
/////////////////////////////////
void arrange(){
    while (getline(cin, str)){
        if(str=="END_OF_GRAMMAR")
            break;
        s=str.length(); 
        while(t<s){
            if(str[t]==' ')
                o=1;
            if((str[t]>='A')&&(str[t]<='Z')&&(o==0)){
                F[x].nt=str[t];
            }
            else if((str[t]>='A')&&(str[t]<='Z')&&(o==1)){
                 F[x].Gset[y++]=str[t];
            }
            else if(((str[t]>='a')&&(str[t]<='z'))||(str[t]=='|')){
                F[x].Gset[y++]=str[t];
            }
            else if(str[t]==';'){
                F[x].Gset[y++]=str[t];
                F[x].empty=1;
            }
            else if(str[t]=='$'){
                F[x].Gset[y++]=str[t];
                F[x].eol=1;
            }
        t++;
       }
       F[x].Gsum=y;
       x++;
       t=0;
       y=0;
       o=0;
    }
}
int Search_T(char t){
    int i=0;
    while(i<x){
        if(F[i].nt==t){
            return i;
        }
        i++;
    }
}
void repeat_cut(int s){
    char temp;
    int q,i,j,l;
    q=F[s].Fsum;
    for(i=0;i<q;i++){
        for(j=i+1;j<q;j++){
            if(F[s].Fset[i]==F[s].Fset[j]){
                    for(l=j;l<q-1;l++){
                        temp=F[s].Fset[l];
                        F[s].Fset[l]=F[s].Fset[l+1];
                        F[s].Fset[l+1]=temp;
                    }
                    q--;
                    F[s].Fset[q]='\0';
                   
                }
            F[s].Fsum=q;
        }
    }
    
      


}
void FirstSet(int s){
    int i=0,j=0,k=0;
    int z;
    int b=0;
    int a=0;
        while(i<F[s].Gsum){
            if((F[s].Gset[i]>='a')&&(F[s].Gset[i]<='z')&&(b==0)){
                a=1;
                b=1;
                F[s].Fset[j++]=F[s].Gset[i];
            }
            else if((F[s].Gset[i]>='A')&&(F[s].Gset[i]<='Z')&&(b==0)){
                a=0;
                z=Search_T(F[s].Gset[i]);
                FirstSet(z);
                while(k<F[z].Fsum){
                    if(F[z].Fset[0]==';'){
                        a=0;
                    }
                         
                    if(F[z].Fset[k]!=';')
                        F[s].Fset[j++]=F[z].Fset[k];
                   
                    
                    k++;
                }
                F[s].empty=F[z].empty;
                if(F[z].empty==0){
                    b=1;  
                }
                else{
                    b=0;
                }
               
            }
            else if(F[s].Gset[i]=='|'){ 
                if((F[s].empty==1)&&(F[s].eol==0)&&(a==0))
                    F[s].Fset[j++]=';';
                a=0;
                b=0;
            }
           
            k=0;
            i++;
        }  
    
    if((F[s].empty==1)&&(F[s].eol==1))   
        F[s].Fset[j++]='$';
    if((F[s].empty==1)&&(F[s].eol==0)&&(a==0))
      F[s].Fset[j++]=';';
    F[s].Fsum=j;
    F[s].repeat=1;
    repeat_cut(s);
    repeat_cut(s);
    while(s<x){
        if((F[s].repeat==0))
            FirstSet(s);
        s++;
    }
} 
void printAns(){
    int i=0,j,k,q;
    char temp;
      while(i<x){
        q=F[i].Fsum;
        for(j=0;j<F[i].Fsum;j++){
          
            for(k=j+1;k<F[i].Fsum;k++){
                if(F[i].Fset[j]>=F[i].Fset[k]){ 
                    temp=F[i].Fset[j];
                    F[i].Fset[j]=F[i].Fset[k];
                    F[i].Fset[k]=temp;
                }
            }
        }

      //////////////////////
    if((F[i].Fset[0]=='$')&&(F[i].Fset[1]==';')){
        for(j=1;j<q-1;j++){
        temp=F[i].Fset[j];
        F[i].Fset[j]=F[i].Fset[j+1];
        F[i].Fset[j+1]=temp;
        }
        q--;
        F[i].Fset[q]='\0'; 
        F[i].Fsum=q;
    }
      /////////////////////////


        i++;
    }
    i=0;
    struct FS p;
    for(j=0;j<x;j++){
        for(k=j+1;k<x;k++){
            if(F[j].nt>=F[k].nt){
                p=F[j];
                F[j]=F[k];
                F[k]=p;
            }
        }
    }
    for(i=0;i<x;i++)
        printf("%c %s\n",F[i].nt,F[i].Fset);
    printf("END_OF_FIRST\n");
}
/////////////////////////////////////
int main(){
    arrange();
    FirstSet(0);
    printAns();
    
}