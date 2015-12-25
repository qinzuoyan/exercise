#ifndef  __STRREP_H_
#define  __STRREP_H_

/**
 * On success, strrep() returns a newly allocated string, which is constructed by
 * replacing all substring `from' in `src' with `to'.
 *
 * If `from' is a null string(with length of 1), then return a duplication of `src'.
 *
 * On failure, when insufficient memory is available, returns NULL.
 * 
 * @param src is a null-terminated string.
 * @param from is a null-terminated string.
 * @param to is a null-terminated string.
 */
char* strrep(const char* src, const char* from, const char* to);

#endif  //__STRREP_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
