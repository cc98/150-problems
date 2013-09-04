#include <string.h>

int is_anagrams(char *left, char *right){
  int i = 0, len = strlen(left);
  if(len != strlen(right)) return FALSE;
  
  while(i < len / 2){
    if(*(left + i) != *(right + len - i - 1))
      return FALSE;
    i++;
  }
  return TRUE;
}
