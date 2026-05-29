#include <stdio.h>

int main() {
    int n;
    printf("Введите размер системы: ");
    scanf("%d", &n);
    
    if (n == 2) {
        double a1, a2, b1, b2, c1, c2;
        
        printf("a1 b1 c1: ");
        scanf("%lf %lf %lf", &a1, &b1, &c1);
        
        printf("a2 b2 c2: ");
        scanf("%lf %lf %lf", &a2, &b2, &c2);
        
        double A = a1 * b2 - a2 * b1;
        double AX = c1 * b2 - c2 * b1;
        double AY = a1 * c2 - a2 * c1;
        
        double x = AX / A;
        double y = AY / A;
        
        

        printf("Ответ: x = %.2f, y = %2.f\n", x, y);
        if (A == 0){
            printf("Ответ: Нет единственного решения.");
        }
        else {
            printf("Ответ: x = %.2f, y = %2.f\n", x, y);
        }

    }
    else if (n == 3) {
        double a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;

        printf("a1 b1 c1 d1: ");
        scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);
        
        printf("a2 b2 c2 d2: ");
        scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);
        
        printf("a3 b3 c3 d3: ");
        scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);
        
        double A = a1*(b2*c3 - b3*c2) - b1*(a2*c3 - a3*c2) + c1*(a2*b3 - a3*b2);
        
        double AX = d1*(b2*c3 - b3*c2) - b1*(d2*c3 - d3*c2) + c1*(d2*b3 - d3*b2);
    
        double AY = a1*(d2*c3 - d3*c2) - d1*(a2*c3 - a3*c2) + c1*(a2*d3 - a3*d2);
        
        double AZ = a1*(b2*d3 - b3*d2) - b1*(a2*d3 - a3*d2) + d1*(a2*b3 - a3*b2);
        
        double x = AX / A;
        double y = AY / A;
        double z = AZ / A;
        

        if (A == 0){
            printf("Ответ: Нет единственного решения.");
        }
        else {
            printf("Ответ: x = %.2f, y = .%2f, z = %.2f\n", x, y, z);
        }
        
    }
     
}