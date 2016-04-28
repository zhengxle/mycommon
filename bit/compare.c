/*
 * =====================================================================================
 *
 *       Filename:  compare.c
 *
 *    Description:  作者：夏洋
 *                  链接：https://www.zhihu.com/question/44356016/answer/97251524
 *                  来源：知乎
 *                  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *                  作者：Milo Yip
 *                  链接：https://www.zhihu.com/question/44356016/answer/97835471
 *                  来源：知乎
 *                  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 *        Version:  1.0
 *        Created:  2016年04月28日 14时24分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaolerzheng (zxl), xiaolerzheng@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#define POPULATE_RIGHT(X) \
    X |= X >> 1;\
    X |= X >> 2;\
    X |= X >> 4;\
    X |= X >> 8;\
    X |= X >> 16

#define REPLICATE_LSB(X) \
    X |= X << 1;\
    X |= X << 2;\
    X |= X << 4;\
    X |= X << 8;\
    X |= X << 16

#define SELECT(COND, A, B) ((COND) & (A)) | (~(COND) & (B))

int compare(uint32_t a, uint32_t b) {
  uint32_t diff = a ^ b;  
  POPULATE_RIGHT(diff);

  uint32_t greater = a & (diff ^ (diff >> 1));
  POPULATE_RIGHT(greater);
  REPLICATE_LSB(greater);

  uint32_t non_zero = diff & 1;
  REPLICATE_LSB(non_zero);
  
  return SELECT(non_zero, SELECT(greater, 1, -1), 0);
}


