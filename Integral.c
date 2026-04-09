#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double func(double var, int selector){
    if(selector == 1){
        return sin(var);
    } else if(selector == 2){
        return cos(var);
    } else {
        printf("Use 1 and 2");
        return 0;
    }
}

int main(){
    double a,i,b; //a,b are the limits of integral and "i" is the divider 
    double sum; 
    double pass; // Pass the value to the func
    double integral; // Sum of the integral
    int select; // Selector

    printf("Which function do you want to integrate?(1-> Sin | 2-> Cos):\n");
    scanf("%d", &select);
    
    b = 2*M_PI;
    a = 0;
    i = 320;

    double step_size = (b-a)/i;
    
    sum = func(a,select) + func(b,select);

    for(int n = 0; n < 320; n++){
        pass = a + (step_size * n);


        if(n % 2 == 1){
            sum += 4 * func(pass, select);
        } else {
            sum += 2 * func(pass, select);
        }
    }

    integral = (step_size/3.0) * sum;
    printf("%lf \n", sum);
    printf("%lf \n", integral);

    printf("%f \n", step_size);
    return 0;
}