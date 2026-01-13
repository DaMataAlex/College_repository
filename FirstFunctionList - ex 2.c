/*2. Faca um programa que leia a quantidade total de segundos e envia para uma funcao,
nesta funcao converta para Horas, Minutos e Segundos e imprima o resultado da
conversao no formato HH:MM:SS.*/

#include <stdio.h>

int reading_seconds(){
    int seconds;
    scanf("%d", &seconds);
    return seconds;
}

void printing_time(int a){
    int seconds;
    int minutes;
    int hours;

    hours = a/3600;
    minutes = (a%3600)/60;
    seconds = a%60;

    printf("%d:%d:%d\n", hours, minutes, seconds);
}

int main(){

    int time;
    time = reading_seconds();
    printing_time(time);
    
    return 0;
}