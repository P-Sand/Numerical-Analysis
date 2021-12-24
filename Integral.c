#include <stdio.h>
#include <math.h>

double function_1(double x){
  return pow(x, 4) - 2 * pow(x, 3) + pow(x, 2) - 3 * x + 1;
}

double function_2(double x){
  return 1 / x;
}

double function_3(double x){
  return atan(x);
}

double small_section(double a[2]){
  double division_number;
  printf("How many divisions do you want to divide the integration interval into?\n>");
  scanf("%lf", &division_number);
  return (a[0] - a[1]) / division_number;
}

double trapezoidal_rule(double delta_x, double r[2]){
  double x = r[1], y = 0;
  while(x < r[0]){
    y += function_3(x);
    y += function_3(x + delta_x);
    x += delta_x;
  }
  return (delta_x / 2) * y;
}

double Simpsons_rule(double delta_x, double r[2]){
  double x = r[1], y = 0;
  while(x < r[0]){
    y += function_3(x);
    y += 4 * function_3(x + delta_x);
    y += function_3(x + 2 * delta_x);
    x += 2 * delta_x;
  }
  return (delta_x / 3) * y;
}

int main(void){
  double range_1[2] = {3, 0}, range_2[2] = {2, 1}, range_3[2] = {4, 0};
  double delta_x, TIV, SIV;
  delta_x = small_section(range_3);
  TIV = trapezoidal_rule(delta_x, range_3);
  SIV = Simpsons_rule(delta_x, range_3);
  printf("Solve with trapezoidal rule...\n>%lf\nSolve with Simpson's rule...\n>%lf\n", TIV, SIV);
  return 0;
}
