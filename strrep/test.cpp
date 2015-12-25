#include "strrep.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(const char* old_str, const char* from_str,
        const char* to_str,  const char* expect_ret)
{
    char* real_ret = strrep(old_str, from_str, to_str);
    if (real_ret == NULL) {
        fprintf(stderr, "FAIL: real_ret=NULL\n");
        exit(1);
    }
    if (strcmp(expect_ret, real_ret) != 0) {
        fprintf(stderr, "FAIL: old_str[%s] from_str[%s] to_str[%s] expect_ret[%s] real_ret[%s]\n",
                old_str, from_str, to_str, expect_ret, real_ret);
        delete real_ret;
        exit(1);
    }
    fprintf(stderr, "SUCCESS: old_str[%s] from_str[%s] to_str[%s] expect_ret[%s]\n",
            old_str, from_str, to_str, expect_ret);
    delete real_ret;
}

int main()
{
    check("", "xx", "yy", "");
    check("a", "a", "b", "b");
    check("ab", "ab", "ba", "ba");
    check("aaaa", "a", "b", "bbbb");
    check("aaaa", "aa", "bb", "bbbb");
    check("aaaa", "aaa", "bbb", "bbba");
    check("aaaa", "aaaa", "bbbb", "bbbb");
    check("aaaa", "", "x", "aaaa");
    check("axxbxxc", "xx", "yy", "ayybyyc");
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
