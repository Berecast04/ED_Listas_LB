#include <stdio.h>
#include <stdlib.h>

// Función para intercambiar dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para ordenar la lista con Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
              for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);

              }
              printf("\n");
            }else{
              for (int i = 0; i < n; i++) {
            

              }
              
            }
          
        }
      
    }
  
}

int main() {
    int n;
    printf("Ingrese el número de elementos en la lista: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("No se pudo asignar memoria para la lista.\n");
        return 1;
    }

    printf("Ingrese los elementos de la lista:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nLista ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Liberar la memoria asignada a la lista
    free(arr);

    return 0;
}
