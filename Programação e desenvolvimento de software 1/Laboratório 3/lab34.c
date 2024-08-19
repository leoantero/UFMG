#include <stdio.h>
int main (void){
    
    int x;
    scanf("%d", &x); 
    int aeds[x];
    for (int i=0; i<x; i++) {
     scanf("%d", &aeds[i]);
    }
    
    int y;
    scanf("%d", &y); 
    int calc[y];
    for (int i=0; i<y; i++) {
     scanf("%d", &calc[i]);
    }
    
    for (int i=0; i<x; i++){
     for (int j=0; j<y; j++){
      if(aeds[i]==calc[j]) printf("%d \n", aeds[i]);
         
     }
    
    }
        
        
        
}