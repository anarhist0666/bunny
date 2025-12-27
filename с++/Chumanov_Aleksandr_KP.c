#include <stdio.h>
#include <math.h>

long double Function(long double x) {
    return (1.0l - x * x / 2.0l) * cosl(x) - (x / 2.0l) * sinl(x);
}

int main(void) {
    long double begin = 0.1l;
    long double end = 0.6l;
    long double step = 0.005l;
    
    for (int i = 0; i < 76; i++) printf("-");
    printf("\n");
    
    printf("| x     | част. сумма ряда       | значение функции       | число итераций |\n");
    
    for (int i = 0; i < 76; i++) printf("-");
    printf("\n");
    
    for (long double x = begin; x <= end + step / 2; x += step) {
        long double sum = 1.0L;
        long double xPower = 1.0l;
        long double factorial = 1.0l;
        int n;
        
        for (n = 1; n <= 100; n++) {
            xPower *= (x * x);
            factorial *= (2*n - 1);
            factorial *= (2*n);
            
            long double sign = (n % 2 == 0) ? 1.0l : -1.0l;
            long double coefficient = 2.0l*n*n + 1.0l;
            long double term = sign * coefficient * xPower / factorial;
            
            sum += term;
        }
        
        long double exact_value = Function(x);
        
        printf("| %.3lf | %.20lf | %.20lf | %d", x, sum, exact_value, n);
        for (int i = 0; i < 14; i++) { 
            printf(" ");
        }
        printf("|\n");
    }
    
    for (int i = 0; i < 76; i++) {
        printf("-");
    }
    printf("\n");
    
    return 0;
}
