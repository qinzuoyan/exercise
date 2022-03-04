#ifndef  __DOC_SUMMARY_H_
#define  __DOC_SUMMARY_H_

#include <string>
#include <vector>

// Find a document summary with minimal length which contains all keywords.
// @retval true if succeed, and pass out "start_pos" and "len" of the sub doc.
// @retval false if failed when the document does not contains all keywords.
bool find_minimal_doc_summary(
        const std::vector<std::string>& doc,
        const std::vector<std::string>& keywords,
        int* start_pos, int* len);

bool find_minimal_doc_summary_simple(
        const std::vector<std::string>& doc,
        const std::vector<std::string>& keywords,
        int* start_pos, int* len);

#endif  //__DOC_SUMMARY_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
