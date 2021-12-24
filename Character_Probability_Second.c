#include <stdio.h>

int main(void){
  int i, j, frequency[64][64] = {0};
  char ch, bch = ' ', fch, sch;
  FILE *file = NULL;
  file = fopen("Metamorphosis_for_Statistics.txt", "r");
  
  for(i = 0; i < 64; i++){
    for(j = 0; j < 64; j++){
      if(i <= 25) fch = 'a' + i;
      else if(i <= 51) fch = 'A' + (i - 26);
      else if(i <= 61) fch = '0' + (i - 52);
      else if(i == 62) fch = ' ';
      else if(i == 63) fch = '.';
      
      if(j <= 25) sch = 'a' + j;
      else if(j <= 51) sch = 'A' + (j - 26);
      else if(j <= 61) sch = '0' + (j - 52);
      else if(j == 62) sch = ' ';
      else if(j == 63) sch = '.';
      
      while((ch = fgetc(file)) != EOF){
        if(bch == fch && ch == sch) frequency[i][j] ++;
        printf("%d", frequency[i][j]);
        bch = ch;
      }
    }
  }
  fclose(file);
  
  file = fopen("Character_Frequency_double.txt", "w");
  for(i = 0; i < 64; i++){
    for(j = 0; j < 64; j++){
      if(i <= 25) fch = 'a' + i;
      else if(i <= 51) fch = 'A' + (i - 26);
      else if(i <= 61) fch = '0' + (i - 52);
      else if(i == 62) fch = ' ';
      else if(i == 63) fch = '.';
      
      if(j <= 25) sch = 'a' + j;
      else if(j <= 51) sch = 'A' + (j - 26);
      else if(j <= 61) sch = '0' + (j - 52);
      else if(j == 62) sch = ' ';
      else if(j == 63) sch = '.';
      
      fprintf(file, "%c%c:%d\n", fch, sch, frequency[i][j]);
      printf("%c%c:%d\n", fch, sch, frequency[i][j]);
    }
  }
  fclose(file);
  
  return 0;
}
