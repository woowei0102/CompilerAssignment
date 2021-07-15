#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
string str;
char c;
int i=0,s,tab=0,x=0,y=0;
/////////////////////////////
void arrange(){
    while (getline(cin, str)){
        s=str.length(); 
        if((str[0]==' ')||(str[0]=='\t')){
            while((str[i]==' ')||(str[i]=='\t')){
                i++;
                x++;  
            }
                
        
        y=x; 
        for(int k=0;k<s;k++){
            str[k]=str[x];
            x++;
        } 
        s-=y;   
        i=0;
        }
/////////////////////////////////////////
    while(i<s){
        if((str[i]=='}')||(str[i]=='}'))
            tab--;
        i++;
            }
    i=0;
//////////////////////////////////////////
    for(int j=0;j<tab;j++)
            cout<<'\t';
/////////////////////////////////////////
         while(i<s){
                cout<<str[i++];
            }
        i=0;
/////////////////////////////////////////////
        cout<<endl;
        while(i<s){
            if((str[i]=='{')||(str[i]=='{'))
                tab++;
            i++;
            }
        
      
        i=0;
        x=0;
        y=0;
    }
}
////////////////////////////
int main(){
    arrange();
      
    
}