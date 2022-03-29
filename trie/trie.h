#ifndef __TRIE_H_
#define __TRIE_H_

#include <string>
#include <cstring>
#include <deque>

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Trie {
public:
    Trie() {
        root_ = new TrieNode();
    }

    ~Trie() {
        std::deque<TrieNode*> to_delete;
        to_delete.push_back(root_);
        while (!to_delete.empty()) {
            TrieNode* n = to_delete.front();
            to_delete.pop_front();
            for (int i = 0; i < 26; i++) {
                if (n->children[i] != nullptr) {
                    to_delete.push_back(n->children[i]);
                }
            }
            delete n;
        }
    }
    
    void insert(const std::string& word) {
        TrieNode* n = root_;
        for (size_t i = 0; i < word.size(); i++) {
            int k = word[i] - 'a';
            if (n->children[k] == nullptr)
                n->children[k] = new TrieNode();
            n = n->children[k];
        }
        n->is_word = true;
    }
    
    bool search(const std::string& word) {
        TrieNode* n = root_;
        for (size_t i = 0; i < word.size(); i++) {
            int k = word[i] - 'a';
            if (n->children[k] == nullptr)
                return false;
            n = n->children[k];
        }
        return n->is_word;
    }
    
    bool startsWith(const std::string& prefix) {
        TrieNode* n = root_;
        for (size_t i = 0; i < prefix.size(); i++) {
            int k = prefix[i] - 'a';
            if (n->children[k] == nullptr)
                return false;
            n = n->children[k];
        }
        return true;
    }

private:
    struct TrieNode {
        bool is_word;
        TrieNode* children[26];
        TrieNode(): is_word(false) {
            memset(children, 0, sizeof(children));
        }
    };
    TrieNode* root_;
};

#endif
