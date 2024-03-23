#include <stdio.h>

float convertir_a_dolares(float cantidad, char moneda);
float convertir_a_euros(float cantidad, char moneda);
float convertir_a_quetzales(float cantidad, char moneda);

int main() {
    float cantidad;
    char moneda_origen, moneda_destino;
    
    printf("Ingrese la cantidad a convertir: ");
    scanf("%f", &cantidad);
    
    printf("Ingrese la moneda de origen (Q para quetzales, $ para dólares, E para euros): ");
    scanf(" %c", &moneda_origen);
    
    printf("Ingrese la moneda de destino (Q para quetzales, $ para dólares, E para euros): ");
    scanf(" %c", &moneda_destino);
    
    float resultado;
    if (moneda_origen == 'Q' && moneda_destino == 'E') {
        resultado = convertir_a_euros(cantidad, moneda_origen);
        printf("%.2f GTQ equivalen a %.2f EUR\n", cantidad, resultado);
    } else if (moneda_origen == 'Q' && moneda_destino == '$') {
        resultado = convertir_a_dolares(cantidad, moneda_origen);
        printf("%.2f GTQ equivalen a %.2f USD\n", cantidad, resultado);
    } else if (moneda_origen == '$' && moneda_destino == 'E') {
        resultado = convertir_a_euros(cantidad, moneda_origen);
        printf("%.2f USD equivalen a %.2f EUR\n", cantidad, resultado);
    } else if (moneda_origen == '$' && moneda_destino == 'Q') {
        resultado = convertir_a_quetzales(cantidad, moneda_origen);
        printf("%.2f USD equivalen a %.2f GTQ\n", cantidad, resultado);
    } else if (moneda_origen == 'E' && moneda_destino == 'Q') {
        resultado = convertir_a_quetzales(cantidad, moneda_origen);
        printf("%.2f EUR equivalen a %.2f GTQ\n", cantidad, resultado);
    } else if (moneda_origen == 'E' && moneda_destino == '$') {
        resultado = convertir_a_dolares(cantidad, moneda_origen);
        printf("%.2f EUR equivalen a %.2f USD\n", cantidad, resultado);
    } else {
        printf("Las monedas seleccionadas no son compatibles.\n");
    }
    
    return 0;
}

float convertir_a_dolares(float cantidad, char moneda) {
    if (moneda == 'Q') {
        return cantidad * 0.129; // 1 GTQ = 0.129 USD (tasa aproximada)
    } else if (moneda == 'E') {
        return cantidad * 1.13; // 1 EUR = 1.13 USD (tasa aproximada)
    } else {
        return cantidad; // si es USD, no es necesario convertir
    }
}

float convertir_a_euros(float cantidad, char moneda) {
    if (moneda == 'Q') {
        return cantidad * 0.110; // 1 GTQ = 0.110 EUR (tasa aproximada)
    } else if (moneda == '$') {
        return cantidad * 0.89; // 1 USD = 0.89 EUR (tasa aproximada)
    } else {
        return cantidad; // si es EUR, no es necesario convertir
    }
}

float convertir_a_quetzales(float cantidad, char moneda) {
    if (moneda == '$') {
        return cantidad * 7.76; // 1 USD = 7.76 GTQ (tasa aproximada)
    } else if (moneda == 'E') {
        return cantidad * 9.08; // 1 EUR = 9.08 GTQ (tasa aproximada)
    } else {
        return cantidad; // si es GTQ, no es necesario convertir
    }
}
