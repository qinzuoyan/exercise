#include "doc_summary.h"
#include <assert.h>

void split_string(const std::string& str, const std::string& delim, std::vector<std::string>* substr_list)
{
    if (str.empty()) return;
    if (delim.empty()) {
        substr_list->push_back(str);
        return;
    }
    std::string::size_type start = 0;
    while (true) {
        std::string::size_type pos = str.find(delim, start);
        if (pos == start) {
            start += delim.length();
            continue;
        }
        else if (pos == std::string::npos) {
            substr_list->push_back(str.substr(start));
            break;
        }
        else {
            substr_list->push_back(str.substr(start, pos - start));
            start = pos + delim.length();
        }
    }
}

void check(const std::string& doc_str, const std::string& query_str,
        bool expect_ret, int expect_start_pos, int expect_len)
{
    std::vector<std::string> doc;
    split_string(doc_str, " ", &doc);
    std::vector<std::string> keywords;
    split_string(query_str, " ", &keywords);
	{
		int start_pos, len;
		bool ret = find_minimal_doc_summary(doc, keywords, &start_pos, &len);
		assert(ret == expect_ret);
		if (ret)
		{
			assert(start_pos == expect_start_pos);
			assert(len == expect_len);
		}
	}
	{
		int start_pos, len;
		bool ret = find_minimal_doc_summary_simple(doc, keywords, &start_pos, &len);
		assert(ret == expect_ret);
		if (ret)
		{
			assert(start_pos == expect_start_pos);
			assert(len == expect_len);
		}
	}
}

int main()
{
    check("b c d", "b d", true, 0, 3);
    check("b c d", "d b", true, 0, 3);
    check("a b c d", "b d", true, 1, 3);
    check("a b c d", "d b", true, 1, 3);
    check("b c d e", "b d", true, 0, 3);
    check("b c d e", "d b", true, 0, 3);
    check("a b c d e", "b d", true, 1, 3);
    check("a b c d e", "d b", true, 1, 3);

    check("", "b d", false, 0, 0);
    check("b c d", "", false, 0, 0);
    check("a b c", "b d", false, 0, 0);

    check("b b b", "b", true, 0, 1);
    check("b b b", "b b", true, 0, 1);
    check("a b c d", "b", true, 1, 1);
    check("a b c d", "b b", true, 1, 1);

    check("a b c d e b", "b d", true, 1, 3);
    check("a b c d b", "b d", true, 3, 2);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
