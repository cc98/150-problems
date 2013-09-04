#include <memory.h>

int matrix_zero(int *matrix, int m, int n) {
  int i, j, k;
  char *flag = (int*)malloc(sizeof(char) * m * n);
  memset(flag, 0, m* n);
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++) {
      if(!flag[ i * m + j] && !matrix[i * m + j]) {
        for(k = 0; k < m; k++){
          flag[k * m + j] = 1;
          matrix[k * m + j] = 0;
        }
        for(k = 0; k < n; k++){
          flag[i * m + k] = 1;
          matrix[i * m + k] = 0;
        }
      }
    }
    
  return 0;
}
