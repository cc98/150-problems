int str_len(char* str){
  int i = 0;
  assert(str);
  while(*str) {i++;str++;}
  return i;
}

char* str_reserve(char *str){
  int len = str_len(str);
  int i = 0; 
  char* result = (char*)malloc(sizeof(char) * len);
  while(i <= (len - 1) / 2){
    *(result + i) = *(str + len - i - 1);
  }
  
  return result;
}
