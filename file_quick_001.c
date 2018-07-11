#include <stdio.h>
#include <string.h>

void fun_quick(char *vet, int n){
    if(n<2) return;

    int pivot = vet[n/2];
    int i,j;
    char temp;

    for(i=0,j=n-1;;i++,j--){
        while (vet[i]<pivot) i++;
        while (vet[j]>pivot) j--;
        if (i>=j) break;

        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;

    }

fun_quick(vet, i);
fun_quick(vet+i, n-i);
}

int main(){

   #define max 30
   char vet[max] = {"qwertyuiopasdfghjklzxcvbnm"};
   FILE *arquivo;

   arquivo = fopen("desordenado.txt", "w");
   fputs(vet, arquivo);
   fclose(arquivo);


   arquivo = fopen("desordenado.txt", "r");
   fgets(vet, max, arquivo);

   arquivo = fopen("ordenado.txt", "w");
   fun_quick(vet, strlen(vet));
   fputs(vet, arquivo);
   fclose(arquivo);






return 0;
}


