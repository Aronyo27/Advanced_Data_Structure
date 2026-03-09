/**
 * We can insert and search in O(n) time , faster than BST
 * Using trie ,we can easily print all words in alphabetical
 *      order which is not easily possible with hashing
 * We can easily do prefix search (or auto-complete)with trie
 * It need O(n) , a lot of memory
 */


#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode*child[26];
    bool endmark;
    TrieNode(){
        endmark=false;
        for(int i=0;i<26;i++)child[i]=NULL;
    }
};

class Trie{
public: 
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string s){
        TrieNode*cur=root;
        for(char c:s){
            int id=c-'a';
            if(cur->child[id]==nullptr)cur->child[id]=new TrieNode();
            cur=cur->child[id];
        }
        cur->endmark=true;
    }
    bool search(string s){
        TrieNode* cur=root;
        for(char c:s){
            int id=c-'a';
            if(cur->child[id]==nullptr)return false;
            cur=cur->child[id];
        }
        return cur->endmark;
    }
    bool startsWith(string s){
        TrieNode* cur=root;
        for(char c:s){
            int id=c-'a';
            if(cur->child[id]==nullptr)return false;
            cur=cur->child[id];
        }
        return true;
    }
};


int main() {
    Trie trie;

    trie.insert("app");
    trie.insert("apple");
    trie.insert("bat");
    trie.insert("ball");

    cout << trie.search("app")<<'\n';     // 1
    cout << trie.search("apple")<<'\n';   // 1
    cout << trie.search("ap")<<'\n';      // 0
    cout << trie.search("bat")<<'\n';     // 1
    cout << trie.search("bad")<<'\n';     // 0

    cout << trie.startsWith("app")<<'\n'; // 1
    cout << trie.startsWith("apl")<<'\n'; // 0
    cout << trie.startsWith("ba")<<'\n';  // 1
    cout << trie.startsWith("cat")<<'\n'; // 0

    return 0;
}

