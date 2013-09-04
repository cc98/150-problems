
#define FLAGMENT 32

int flag[4] = {0};

int str_remove_duplicate(char* str){
  char *p = str;
  char *cur = str;
  while(*p){
    if(flag[*p / 32] >> (*p %32 ) & 1) *p = -1;
    else
       flag[*p / 32] |= 1 << (*p % 32);
  }
  /* TODO: I'm confused  */
  return 0;
}
