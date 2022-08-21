#include <string>
#include <unordered_map>

class Trie
{
public:
    struct TrieNode
    {
        TrieNode() : endOfWord(false) {}
        ~TrieNode()
        {
            for (auto kv : children)
                if (kv.second)
                    delete kv.second;
        }
        bool endOfWord;
        std::unordered_map<char, TrieNode *> children;
    };

    Trie();
    void insert(const std::string &word) const;
    bool search(const std::string &word) const;
    bool startsWith(const std::string &prefix) const;

private:
    TrieNode *_root;
    // Find a prefix, return the pointer to the tail character
    // or nullptr if not exist
    TrieNode *find(const std::string &prefix) const;
};