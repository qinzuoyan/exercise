#include "doc_summary.h"
#include <map>

/// another simpler implementation
bool find_minimal_doc_summary_simple(
		const std::vector<std::string>& doc,
		const std::vector<std::string>& keywords,
		int* start_pos, int* len)
{
	if (doc.empty() || keywords.empty())
		return false;
	std::map<std::string, int> m;
	for (size_t i = 0; i < keywords.size(); i++)
		m[keywords[i]] = 0;
	size_t n = m.size(), k = 0, tail = 0, head = 0;
	*len = -1;
	while (head < doc.size()) {
		while (k < n && head < doc.size()) {
			std::map<std::string, int>::iterator it = m.find(doc[head]);
			if (it != m.end()) {
				it->second++;
				if (it->second == 1)
					k++;
			}
			head++;
		}
		while (k == n && tail < head) {
			std::map<std::string, int>::iterator it = m.find(doc[tail]);
			if (it != m.end()) {
				it->second--;
				if (it->second == 0) {
					int l = head - tail;
					if (*len == -1 || l < *len) {
						*start_pos = tail;
						*len = l;
					}
					k--;
				}
			}
			tail++;
		}
	}
	return *len != -1;
}

