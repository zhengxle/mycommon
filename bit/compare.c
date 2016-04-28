/*
 * =====================================================================================
 *
 *       Filename:  compare.c
 *
 *    Description:  作者：夏洋
 *                  链接：https://www.zhihu.com/question/44356016/answer/97251524
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
int compare(uint32_t a, uint32_t b) {
  uint32_t diff = a ^ b;
  if (!diff) return 0;
  
  // 001xxxxx -> 00100000
  diff |= diff >> 1;
  diff |= diff >> 2;
  diff |= diff >> 4;
  diff |= diff >> 8;
  diff |= diff >> 16;
  diff ^= diff >> 1;
  
  return a & diff ? 1 : -1;
}


