#include <stdio.h>

void determineTriangle(float a, float b, float c) { 
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Bukan Segitiga (Input <= 0)\n");
        return;
    }
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Bukan Segitiga\n");
    } 
    else if (a == b && b == c) {
        printf("Segitiga Sama Sisi (Equilateral)\n");
    } 
    else if (a == b || b == c || a == c) {
        printf("Segitiga Sama Kaki (Isosceles)\n");
    } 
    else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a)) {
        printf("Segitiga Siku-siku (Right Triangle)\n");
    } 
    else {
        printf("Segitiga Bebas\n");
    }
}

int main() {
    float s1, s2, s3;
    printf("Masukkan tiga sisi: ");
    scanf("%f %f %f", &s1, &s2, &s3);
    determineTriangle(s1, s2, s3);
    return 0;
}