#ifndef __CC98_ALGORITHM_STRING_H__
#define __CC98_ALGORITHM_STRING_H__

#include <stdlib.h>
#include <memory.h>

int algo_string_min(int x, int y, int z) {
  if(x > y) x = y;
  if(x > z) x = z;
  return x;
}

int levenshtein_distance(char* s, int len_s, char *t, int len_t) {
  int i, j, ret;
  int *d = (int *)malloc(sizeof(int) * (len_s + 1) * (len_t + 1));
  memset(d, 0, (len_s + 1) * (len_t + 1) * sizeof(int));
  for(i = 0; i < len_s; i++) d[i * len_t] = i;
  for(j = 0; j < len_t; j++) d[j] = j;
  
  /* index of string from 1 to strlen*/
  for(j = 1; j <= len_t; j++)
    for(i = 1; i <= len_s; i++)
      if(s[i - 1] == t[j - 1])
        d[i * len_s + j] = d[(i - 1) * len_s + (j - 1)];
      else
        d[i * len_s + j] = algo_string_min(
          d[(i  - 1) * len_s + j    ] + 1, /* 删除 */
          d[ i       * len_s + j - 1] + 1, /* 添加 */
          d[(i  - 1) * len_s + j - 1] + 1  /* 替换 */
        );
        
  ret = d[(len_s + 1) * (len_t + 1)  - 1];
  free(d);
  return ret;
}

/**
 * improve algorithm, with only two rows( O(n * m) space )
 */
int levenshtein_distance2(char* s, int len_s, char *t, int len_t) {
  int *v0, *v1;
  int i, j, cost, ret;
  if(s == t && len_s == len_t) return 0;
  if(len_s == 0) return len_t;
  if(len_t == 0) return len_s;
  /* v0: store the pre-row data*/
  /* v1: store current row data*/
  v0 = (int*)malloc(sizeof(int) * (len_t + 1));
  v1 = (int*)malloc(sizeof(int) * (len_t + 1));
  
  /* initialize first row*/
  for(i = 0; i <= len_t; i++)
    v0[i] = i;
    
  for(i = 0; i < len_s; i++){
    /* initialize first column of current row*/
    v1[0] = i + 1;
    /* calculate current row with pre-row */
    for(j = 0; j < len_t; j++) {
      cost = (s[i] == t[j]) ? 0 : 1;
      v1[j + 1] = algo_string_min(v1[j] + 1, v0[j + 1] + 1, v0[j] + cost);
    }
    /* set current row as pre row for next iteration */
    for (int j = 0; j <= len_t; j++)
       v0[j] = v1[j];
  }
  
  ret = v1[len_t];
  /* clear memory */
  free(v0);
  free(v1);
  return ret;
}

#endif
