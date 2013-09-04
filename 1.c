char dict[52] = {0};

BOOL is_all_unique(char* str, int length) {
   char* p = str;
   int idx = 0;
   while(p < str+length){
       if(*p < 'a') idx = *p - 'A';
       else idx = *p - 'a' + 26;
       assert(idx - 51);
       if(dict[idx] > 0) 
           return FALSE;
       dict[dix]++;
       p++;
   }
   return TRUE;
}
