#include <stdio.h>

void file_reading(char str[]){
  int i = 0;
  char ch;
  FILE *file = NULL;
  
  file = fopen("Metamorphosis.txt", "r");
  
  while((ch = fgetc(file)) != EOF){
    if(ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
    else if(ch != '\n' && (ch < 'a' || ch > 'z')) ch = ' ';
    str[i] = ch;
    i++;
  }
  
  fclose(file);
  return;
}

void file_writing(char str[]){
  FILE *file = NULL;
  file = fopen("Metamorphosis_for_Statistics.txt", "w");
  fprintf(file, "%s", str);
  fclose(file);
  return;
}

int main(void){
  char str[200000];
  file_reading(str);
  file_writing(str);
  return 0;
}
