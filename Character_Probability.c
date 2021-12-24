#include <stdio.h>

int main(void){
  int i, sum = 0, f[28] = {0};
  char ch;
  FILE *file = NULL;

  
  for(i = 0; i < 29; i++){
    file = fopen("Metamorphosis_for_Statistics.txt", "r");
    while((ch = fgetc(file)) != EOF){
      if(i < 26 && ch == 'a' + i) f[i] ++;
      else if(i == 26 && ch == ' ') f[i] ++;
      else if(i == 27 && ch == '\n') f[i] ++;
      else if(i == 28) sum ++;
    }
  fclose(file);
  }
  
  file = fopen("Character_Frequency.txt", "w");
  for(i = 0; i < 29; i++){
    if(i < 26 ) fprintf(file, "%c:%d\n", 'a' + i, f[i]);
    else if(i == 26) fprintf(file, "_:%d\n", f[i]);
    else if(i == 27) fprintf(file, "↓:%d\n", f[i]);
    else if(i == 28) fprintf(file, "sum:%d", sum);
  }
  fclose(file);
  
  return 0;
}
