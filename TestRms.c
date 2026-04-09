#include <stdio.h>
#include <math.h>

#define BUFFER_SIZE 512
#define M_PI 3.14159265358979323846

int main(){
    double ac_value = 0.0;
    double rms = 0.0;
    double regis = 0.0;
    double mean = 0.0;
    double sum_of_regis = 0.0;
    printf("Enter your AC value: ");
    scanf("%lf", &ac_value);

    for(int i = 0; i < BUFFER_SIZE; i++){
        regis = ac_value * sin(2*M_PI * i / BUFFER_SIZE);

        sum_of_regis += pow(regis, 2.0);
    }
    mean = sum_of_regis / BUFFER_SIZE;

    rms = sqrt(mean);

    printf("Dc value: %lf", rms);
}