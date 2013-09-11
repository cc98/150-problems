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
  int i, j;
  int *d = (int *)malloc(sizeof(int) * len_s * len_t);
  memset(d, 0, len_s * len_t * sizeof(int));
  for(i = 0; i < len_s; i++) d[i * len_t] = i;
  for(j = 0; j < len_t; j++) d[j] = j;
  
  for(j = 0; j < len_t; j++)
    for(i = 0; i < len_s; i++)
      if(s[i] == t[j])
        d[i * len_s + j] = d[(i - 1) * len_s + (j - 1)];
      else
        d[i * len_s + j] = algo_string_min(
          d[(i  - 1) * len_s + j    ] + 1, /* 删除 */
          d[ i       * len_s + j - 1] + 1, /* 添加 */
          d[(i  - 1) * len_s + j - 1] + 1  /* 替换 */
        );
        
  return d[len_s * len_t  - 1];
}

#endif
