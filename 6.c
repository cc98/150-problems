int iamge_rotate_clockwise(int *image, int edge_len){
  int i, j, tmp;
  i = 0;
  while(i < edge_len * edge_len){
    image[i] *= 2;
  }
  
  for(i = 0; i < edge_len; i++)
    for(j = 0; j < edge_len; i++){
      tmp = image[i * edge_len + j];
      if(!(tmp & 0x1)){
        image[i * edge_len + j] = image[(edge_len - j) * edge_len + i] + 1;
        image[(edge_len - j) * edge_len + i] = image[(edge_len - i) * edge_len + (edge_len - j)] + 1;
        image[(edge_len - i) * edge_len + (edge_len - j)] = image[j * edge_len + edge_len - i]  + 1;
        image[j * edge_len + edge_len - i] = tmp + 1;
      }
    }
    
  while(i < edge_len * edge_len){
    image[i] *= image[i]  >> 1;
  }
  
  return 0;
}

int iamge_rotate_unclockwise(int *image, int edge_len){
  int i, j, tmp;
  i = 0;
  while(i < edge_len * edge_len){
    image[i] *= 2;
  }
  
  for(i = 0; i < edge_len; i++)
    for(j = 0; j < edge_len; i++){
      tmp = image[i * edge_len + j];
      if(!(tmp & 0x1)){
        image[i * edge_len + j] = image[j * edge_len + edge_len - i] + 1;
        image[j * edge_len + edge_len - i] = image[(edge_len - i) * edge_len + (edge_len - j)] + 1;
        image[(edge_len - i) * edge_len + (edge_len - j)] = image[(edge - j) * edge_len + i]  + 1;
        image[(edge_len - j) * edge_len + i] = tmp + 1;
      }
    }
    
  while(i < edge_len * edge_len){
    image[i] *= image[i]  >> 1;
  }
  
  return 0;
}

int image_rotate(int *image, int edge_len, int CLOCKWISE){
  if(!CLOCKWISE)
     return iamge_rotate_unclockwise(image, edge_len);
  return iamge_rotate_clockwise(image, edge_len);
}
