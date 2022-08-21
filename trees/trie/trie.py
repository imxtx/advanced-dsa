class TrieNode:

    def __init__(self):
        self.endOfWord = False
        self.children = {}


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            if not c in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.endOfWord = True

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            if not c in cur.children:
                return False
            cur = cur.children[c]
        return cur.endOfWord

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for c in prefix:
            if not c in cur.children:
                return False
            cur = cur.children[c]
        return True


if __name__ == '__main__':
    keywords = Trie()
    keywords.insert('apple')
    keywords.insert('app')
    keywords.insert('ape')
    keywords.insert('hello')
    print(f"apple exist: {keywords.search('apple')}")
    print(f"appl  exist: {keywords.search('appl')}")
    print(f"app   exist: {keywords.search('app')}")
    print(f"ap    exist: {keywords.search('ap')}")
    print(f"a     exist: {keywords.search('a')}")
    print(f"starts with 'hell': {keywords.startsWith('hell')}")
