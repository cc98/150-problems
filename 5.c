#include <string.h>

static int str_space_count(const char* str){
  int count = 0;
  while(*str){
    if(*str == ' ') count++;
    str++;
  }
  return count;
}

char* str_encode_space(const char* src){
  int space_count;
  int len = strlen(str);
  char* dest;
  space_count = str_space_count(str);
  dest = (char*)malloc(sizeof(char) * (len + 1 + space_count * 2));
  
  while(*str){
     if(*str == ' '){
        *(dest++) = '%';
        *(dest++) = '2';
        *(dest++) = '0';
     }
     else {
        *(dest++)  =*(src++);
     }
  }
  
  return dest;
}
