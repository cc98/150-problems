#include <string.h>

int str_check_rotation(const char* s1, const char* s2){
  int len = strlen(s1);
  if(len != strlen(s2)) return FALSE;
  
  char *tmp = (char*)malloc(sizeof(char) * len * 2);
  
  strcpy(tmp, s1);
  strcat(tmp, s1);
  
  return isSubstring(tmp, s2);
}
