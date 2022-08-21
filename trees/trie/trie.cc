#include "trie.h"

// private methods

Trie::TrieNode *Trie::find(const std::string &prefix) const
{
    TrieNode *cur = _root;
    for (const char c : prefix)
    {
        if (!cur->children.count(c))
            return nullptr;
        cur = cur->children[c];
    }
    return cur;
}

// public methods

Trie::Trie() : _root(new Trie::TrieNode()) {}

void Trie::insert(const std::string &word) const
{
    TrieNode *cur = _root;
    for (const char c : word)
    {
        if (!cur->children.count(c))
            cur->children[c] = new TrieNode();
        cur = cur->children[c];
    }
    cur->endOfWord = true;
}

bool Trie::search(const std::string &word) const
{
    TrieNode *p = find(word);
    return p && p->endOfWord;
}

bool Trie::startsWith(const std::string &prefix) const
{
    return find(prefix) != nullptr;
}