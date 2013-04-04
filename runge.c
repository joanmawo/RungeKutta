#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <f_prima_1.h>
#include <f_prima_2.h>

void rungeKuttaCuartoOrden(float *x, float *y_1, float *y_2, float h, int n_pasos){
  //Condiciones iniciales
  y_1[0] = 0.1;
y_2[0] = 0.0;

  int i;
  float k1_1, k1_2;
  float k2_1, k2_2;
  float k3_1, k3_2;
  float k4_1, k4_2;
  float promedio_k_1, promedio_k_2;
  float x1;
  float x2;
  float x3;
  float y1_1, y1_2;
  float y2_1, y2_2;
  float y3_1, y3_2;

  for(i = 1; i < n_pasos; i ++){

  k1_1 = f_prima_1(y_1[i-1], y_2[i-1]);
  k1_2 = f_prima_2(y_1[i-1],y_2[i-1]);

  //Primer paso
  
  x1 = x[i-1] + (h/2.0);
  y1_1 = y_1[i-1] + (h/2.0)*k1_1;
  y1_2 = y_2[i-1] + (h/2.0)*k1_2;

  k2_1 = f_prima_1(y1_1, y1_2);
  k2_2 = f_prima_2(y1_1, y1_2);

  //Segundo paso

  x2 = x[i-1] + (h/2.0);
  y2_1 = y_1[i-1] + (h/2.0)*k2_1;
  y2_2 = y_2[i-1] + (h/2.0)*k2_2;

  k3_1 = f_prima_1(y2_1, y2_2);
  k3_2 = f_prima_2(y2_1, y2_2);

  //Tercer paso

  x3 = x[i-1] + (h/2.0);
  y3_1 = y_1[i-1] + (h/2.0)*k3_1;
  y3_2 = y_2[i-1] + (h/2.0)*k3_2;

  k4_1 = f_prima_1(y3_1, y3_2);
  k4_2 = f_prima_2(y3_1, y3_2);
  
  //Cuarto paso

  promedio_k_1 = (1.0/6.0)*(k1_1 + 2.0*k2_1 + 2.0*k3_1 + k4_1);
  promedio_k_2 = (1.0/6.0)*(k1_2 + 2.0*k2_2 + 2.0*k3_2 + k4_2);

  x[i] = x[i-1] + h;
  y_1[i] = y_1[i-1] + h*promedio_k_1;
  y_2[i] = y_2[i-1] + h*promedio_k_2;
 
}
