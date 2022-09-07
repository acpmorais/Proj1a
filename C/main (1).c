#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int size) {
  int step;
  for (step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main()
{
    clock_t start_t, end_t;
    double total_t;
    int i, j, z, m[1024][100];
    srand(time(NULL));
    FILE *f;
    f = fopen("tempo.txt", "w");

    for(z=0;z<1024;z++){
        start_t = clock();
        for(i=0;i<1024;i++){
            for(j=0;j<100;j++){
                m[i][j] = rand() % 1000;
            }
        }

        for(i=0;i<1024;i++){
            insertionSort(m[i], 100);
        }
        end_t = clock();
        total_t = (double)(end_t - start_t) / ((CLOCKS_PER_SEC)/1000);
        fprintf(f, "%f \n", total_t);
    }

    fclose(f);

    return 0;
}


