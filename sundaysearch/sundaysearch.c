/*
 * =====================================================================================
 *
 *       Filename:  sundaysearch.c
 *
 *    Description:  
 *    Sunday Search算法(D.M. Sunday: A Very Fast Substring Search Algorithm. Communications of the ACM, 33, 8, 132-142 (1990))
 *
 *    是大多数情况下比KMP和BM算法更快的串搜索算法,而且原理非常简单易理解.
 *
 *    例如要在”searcqpozreusevnsearch”中搜索”search”
 *
 *    首先初始化一个256长度的索引表,记录每个字节对应搜索串中的倒数位置,即’h'=1,’c'=2,’r'=3,’a'=4,’e'=5,’s'=6,其它字节对应-1
 *
 *    searcqpozreusevnsearch
 *    search
 *    第一次循环发现’q'与’h'不等,这时候查看搜索字符串长度后一位’p'在索引表中的值,发现是-1,则直接右移搜索字符串长度+1
 *
 *    searcqpozreusevnsearch
 *    -------search
 *    第二次循环,’s'与’o'不同,再查看搜索字符串长度后一位’e'在索引表中值为5,直接右移5位
 *
 *    searcqpozreusevnsearch
 *    ------------search
 *    第三次循环,’v'与’a'不同,查询索引表中’a'的值为4,右移4位
 *
 *    searcqpozreusevnsearch
 *    ----------------search
 *    第四次循环找到匹配.正常情况下比BM和Horspool都要快很多.
 *
 *        Version:  1.0
 *        Created:  2016年04月12日 15时56分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoliang (zxl), xiaoliang.zxl@taobao.com
 *        Company:  Taobao.com
 *
 * =====================================================================================
 */

#include <string.h>

unsigned char* sunday_search(unsigned char* str, size_t str_len, unsigned char* sub, size_t sub_len)
{
    unsigned mark[256];
    size_t i;
    size_t j;
    size_t k;

    if (str_len == -1)
        str_len = strlen(str);

    if (sub_len == -1)
        sub_len = strlen(sub);

    if (str_len < sub_len)
        return NULL;

    if (sub_len == 1) {
        for (i = 0; i < str_len; ++i) {
            if (str[i] == *sub) {
                return str + i;
            }
        }
    }

    for (i = 0; i < 256; ++i) {
        mark[i] = sub_len + 1;
    }

    for (i = 0; i < sub_len; ++i) {
        mark[(unsigned char)(sub[i])]= sub_len - i;
    }

    size_t max_pos = str_len - sub_len + 1; 
    for (i = 0; i < max_pos;) {
        for (k = 0; k < sub_len; ++k) {
            if (str[i+k] != sub[k]) {
                i += mark[(unsigned char)(str[i+sub_len])];
                break;
            }
        }
        if (k == sub_len) {
            return str + i;
        }
    }
    return NULL;
}
