#include <iostream>
#include "trie.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Trie keywords;
    keywords.insert("apple");
    keywords.insert("app");
    keywords.insert("application");
    keywords.insert("ape");

    cout << "searching apple: " << keywords.search("apple") << endl;
    cout << "searching appl: " << keywords.search("appl") << endl;
    cout << "searching app: " << keywords.search("app") << endl;
    cout << "searching ap: " << keywords.search("ap") << endl;
    cout << "searching a: " << keywords.search("a") << endl;

    cout << "starts with \"applic\": " << keywords.startsWith("applic") << endl;

    return 0;
}
