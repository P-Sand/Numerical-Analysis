#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define sum 139517

int main(void){
  char c;
  int random, n, i, j;
  int table[] = {8085, 1661, 2541, 4731, 13800, 2499, 2793, 7661, 7134, 181, 916, 4426, 2661, 6970, 8879, 1715, 103, 6682, 6466, 10628, 2989, 939, 2675, 128, 1982, 24, 27982, 2266};
  srand((unsigned int)time(NULL));
  
  for(i = 0; i < 100; i++){
    random = rand() % sum;
    n = 0;
    for(j = 0; j < 28; j++){
      n += table[j];
      if(random < n) break;
    }
    if(j < 26) putchar('A' + j);
    else if(j == 26) putchar(' ');
    else if(j == 27) putchar('\n');
  }
  
  putchar('\n');    
  return 0;
}
