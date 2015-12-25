#include "strrep.h"
#include <string.h>
#include <malloc.h>

char* strrep(const char* src, const char* from, const char* to)
{
    char *des, *des_cur;
    int from_len, to_len, src_len, des_len;
    const char *src_cur, *src_end, *occ;
    const char **marks; 
    int mark_len, m, rep_count;
    // prepare
    from_len = strlen(from);
    to_len = strlen(to);
    src_len = strlen(src);
    if (from_len == 0)
        return strdup(src);
    // mark all occurence of `from' in `src'
    mark_len = 0x4;
    marks = (const char**)malloc(sizeof(char*) * mark_len);
    if (marks == NULL)
        return NULL;
    rep_count = 0;
    src_cur = src;
    while((occ = strstr(src_cur, from)) != NULL) {
        rep_count++;
        // need more space for mark
        if (rep_count > mark_len) {
            mark_len << 1;
            marks = (const char**)realloc(marks, mark_len);
            if (marks == NULL)
                return NULL;
        }
        // mark the position
        marks[rep_count - 1] = occ;
        // find next occurence from the current position
        src_cur = occ + from_len;
    }
    // construct new string
    des_len = src_len + (to_len - from_len) * rep_count;
    des = (char*)malloc(des_len + 1);
    if (des == NULL)
        return NULL;
    des_cur = des;
    src_cur = src;
    m = 0;
    if (m < rep_count)
        occ = marks[m];
    else
        occ = NULL;
    while(*src_cur) {
        if (src_cur != occ)
            *des_cur++ = *src_cur++;
        else {
            // replace `from' with `to'
            strncpy(des_cur, to, to_len);
            src_cur += from_len;
            des_cur += to_len;
            // more to replace?
            m++;
            if (m < rep_count)
                occ = marks[m];
            else
                occ = NULL;
        }
    }
    des_cur = '\0';
    free(marks);
    return des;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
