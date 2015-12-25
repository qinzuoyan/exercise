#include "doc_summary.h"
#include <map>
#include <climits>

struct MatchPos
{
    int keyword_id;
    int doc_pos;
};

// Prepare keyworks map:
//   keyword  ==>  id (starts from 0)
static void prepare_keywork_id_map(const std::vector<std::string>& keywords,
        std::map<std::string, int>* keyword_map);

// Match keywords in doc, returns vector of MatchPos.
static void match_keyworks_in_doc(const std::vector<std::string>& doc,
        const std::map<std::string, int>& keyword_id_map,
        std::vector<MatchPos>* match_vector); 

// Find minimal sub doc from match vector.
static bool find_minimal_sub_doc(const std::vector<MatchPos>& match_vector,
        int keyword_count, int* start_pos, int* len);

bool find_minimal_doc_summary(const std::vector<std::string>& doc,
        const std::vector<std::string>& keywords,
        int* start_pos, int* len)
{
    if (doc.empty() || keywords.empty())
    {
        // null doc or keywords
        return false;
    }

    // keyword ==> id (starts from 0)
    std::map<std::string, int> keyword_id_map;
    prepare_keywork_id_map(keywords, &keyword_id_map);

    std::vector<MatchPos> match_vector;
    match_keyworks_in_doc(doc, keyword_id_map, &match_vector); 

    if (match_vector.size() < keyword_id_map.size())
    {
        // not match all keywords
        return false;
    }

    if (keyword_id_map.size() == 1u)
    {
        // unique keyword
        *start_pos = match_vector[0].doc_pos;
        *len = 1;
        return true;
    }

    return find_minimal_sub_doc(match_vector, keyword_id_map.size(), start_pos, len);
}

void prepare_keywork_id_map(const std::vector<std::string>& keywords,
        std::map<std::string, int>* keyword_id_map)
{
    int next_id = 0;
    for (std::vector<std::string>::const_iterator it = keywords.begin();
            it != keywords.end(); ++it)
    {
        if (keyword_id_map->find(*it) == keyword_id_map->end())
        {
            keyword_id_map->insert(std::make_pair(*it, next_id));
            ++next_id;
        }
    }
}

void match_keyworks_in_doc(const std::vector<std::string>& doc,
        const std::map<std::string, int>& keyword_id_map,
        std::vector<MatchPos>* match_vector)
{
    int pos = 0;
    for (std::vector<std::string>::const_iterator it = doc.begin();
            it != doc.end(); ++it, ++pos)
    {
        std::map<std::string, int>::const_iterator find = keyword_id_map.find(*it);
        if (find != keyword_id_map.end())
        {
            MatchPos match;
            match.keyword_id = find->second;
            match.doc_pos = pos;
            match_vector->push_back(match);
        }
    }
}

bool find_minimal_sub_doc(const std::vector<MatchPos>& match_vector,
        int keyword_count, int* start_pos, int* len)
{
    std::vector<int> b(keyword_count);
    int p1 = 0;
    int p2 = 0;
    int sub_match_count = 0;
    int match_vector_size = match_vector.size();
    *len = INT_MAX;
    while (p2 < match_vector_size)
    {
        while (sub_match_count < keyword_count && p2 < match_vector_size)
        {
            // go forward p2 util match all
            b[match_vector[p2].keyword_id] += 1;
            if (b[match_vector[p2].keyword_id] == 1)
            {
                ++sub_match_count;
            }
            ++p2;
        }
        while (sub_match_count == keyword_count)
        {
            // go forward p1 util just match all
            if (b[match_vector[p1].keyword_id] == 1)
            {
                break;
            }
            b[match_vector[p1].keyword_id] -= 1;
            ++p1;
        }
        if (sub_match_count == keyword_count)
        {
            // record current length
            int cur_len = match_vector[p2 - 1].doc_pos - match_vector[p1].doc_pos + 1;
            if (cur_len < *len)
            {
                *start_pos = match_vector[p1].doc_pos;
                *len = cur_len;
            }
            // go forward p1 for one step
            b[match_vector[p1].keyword_id] -= 1;
            ++p1;
            --sub_match_count;
        }
    }
    return *len <= INT_MAX;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
