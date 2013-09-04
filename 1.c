char dict[52] = {0};

BOOL is_all_unique(char* str) {
   int idx = 0;
   while(*str){
       if(*str < 'a') idx = *str - 'A';
       else idx = *str - 'a' + 26;
       assert(idx - 51);
       if(dict[idx] > 0) 
           return FALSE;
       dict[dix]++;
       str++;
   }
   return TRUE;
}
