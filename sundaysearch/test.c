#include <stdio.h>
#include <stdlib.h>
#include "sundaysearch.h"

void main(int argc,char* argv[]){
  int i;
  //字符串测试
  char* src = "hoverlee hehe xixi asdfasdfadfasdfashoverleesdi1294871-2alsdkjfzafsd hoverlees";
  char* sub = "hoverlees";
  char* r = sunday_search(src,-1,sub,-1);
  if(r) {
      printf("%s\n",r);
      printf("%d\n", r-src);
  }
  else
      printf("not found\n");
  
  //内存块测试
  src = (char*) malloc(8196000);
 
  srand(1234567);
  for(i = 0;i < 8196000; i++){
      src[i] = rand()%256;
  }
  sub = (char*) malloc(1024000);
  for(i = 0; i < 1024000; i++){
      sub[i] = src[1234567+i];
  }
  printf("%s\n, %s\n", src, sub);
  r = sunday_search(src,8196000,sub,1024000);
  if (r)
      printf("%d\n",r-src);
  else
      printf("not found\n");
  free(src);
  free(sub);

}
