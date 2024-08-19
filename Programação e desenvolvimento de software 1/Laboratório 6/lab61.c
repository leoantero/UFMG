#include <stdio.h>
#include <stdlib.h>

int bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasnomes(int mes, int ano) {
    if (mes == 2) {
        return bissexto(ano) ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}


int diasnoano(int dia, int mes, int ano) {
    int dias = dia;
    for (int i = 1; i < mes; i++) {
        dias += diasnomes(i, ano);
    }
    return dias;
}


int dias_totais(int dia, int mes, int ano) {
    int diabase = 17, mesbase = 9, anobase = 2020;

    int dias_totais = 0;

    if (ano < anobase) {
        for (int i = ano; i < anobase; i++) {
            dias_totais += bissexto(i) ? 366 : 365;
        }   
        dias_totais -= diasnoano(dia, mes, ano);
        dias_totais += diasnoano(diabase, mesbase, anobase);
    } else if (ano>anobase) {
        for (int k = anobase; k < ano; k++) {
            dias_totais += bissexto(k) ? 366 : 365;
        }
        dias_totais -= diasnoano(diabase, mesbase, anobase);
        dias_totais += diasnoano(dia, mes, ano);
    } else {
        dias_totais = abs(diasnoano(diabase, mesbase, anobase) - diasnoano(dia, mes, ano));
    }

    return dias_totais + 1; 
}

int main() {
    int dia, mes, ano;

    while (scanf("%d %d %d", &dia, &mes, &ano) == 3) {
        int dias = dias_totais(dia, mes, ano);
        printf("%d\n", dias);
    }

    return 0;
}
