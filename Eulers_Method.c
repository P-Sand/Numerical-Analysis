#include <stdio.h>
#define delta_x 1

double function(double x){
  return 2 * x;
}

double Eulers_Method(double x_0, double y_0){
  return y_0 + delta_x * function(x_0);
}

int main(void){
  int i;
  double x_0 = 1, y_0 = 1;
  printf("Please enter the initial value.\n>");
  scanf("%lf", &x_0); 
  
  for(i = 0; i < 102; i ++){ 
    printf("Round %3d : %5.2lf, %5.4lf\n", i, x_0, y_0);
    y_0 = Eulers_Method(x_0, y_0);
    x_0 += delta_x;
  }
  return 0;
}
