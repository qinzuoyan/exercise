#include "find_servlet.h"
#include <cassert>
#include <iostream>

void check_find(const ServletMap& map, const std::string& path, Servlet expect_ret, int expect_count)
{
    int count;
    Servlet ret = find_servlet(map, path, &count);
    assert(ret == expect_ret);
    assert(count == expect_count);
    std::cout << path << ": " << count << std::endl;
}

int main()
{
    Servlet s1 = (Servlet)0x1;
    Servlet s2 = (Servlet)0x2;
    Servlet s3 = (Servlet)0x3;
    Servlet s4 = (Servlet)0x4;
    Servlet s5 = (Servlet)0x5;
    ServletMap m;
    m["/"] = s1;
    m["/a"] = s2;
    m["/a/b"] = s3;
    m["/a/b/c/d/e/f/g/h/i"] = s4;
    m["/a/bcde"] = s5;

    check_find(m, "", NULL, 0);
    check_find(m, "/", s1, 1);
    check_find(m, "/a", s2, 1);
    check_find(m, "/a/b", s3, 2);
    check_find(m, "/a/b/c", s3, 3);
    check_find(m, "/a/b/c/d", s3, 3);
    check_find(m, "/a/b/c/d/e", s3, 3);
    check_find(m, "/a/b/c/d/e/f", s3, 3);
    check_find(m, "/a/b/c/d/e/f/g", s3, 3);
    check_find(m, "/a/b/c/d/e/f/g/h", s3, 3);
    check_find(m, "/a/b/c/d/e/f/g/h/i", s4, 3);
    check_find(m, "/a/bbbb", s2, 2);
    check_find(m, "/a/bcde", s5, 2);
    check_find(m, "/a/bcdefghi", s2, 2);
    check_find(m, "/a/x", s2, 2);
    check_find(m, "/b", NULL, 1);
    check_find(m, "/b/c", NULL, 1);
    check_find(m, "/b/c/d", NULL, 1);
    check_find(m, "/b/c/d/e", NULL, 1);

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
