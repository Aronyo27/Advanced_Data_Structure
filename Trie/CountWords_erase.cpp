#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*child[26];
    int pCnt=0;
    int endCnt=0;
    Node(){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        pCnt=0,endCnt=0;
    }
};

class Trie {
    private:
        Node* root;
	public:
	    Trie(){
            root=new Node();         
	    }
	    void insert(string word) {
            Node*cur=root;
            for(char &c:word){
                int t=c-'a';
                if(cur->child[t]==nullptr)cur->child[t]=new Node();
                cur=cur->child[t];
                cur->pCnt++;
            }
            cur->endCnt++;
    	}
	    int countWordsEqualTo(string word) {
            Node*cur=root;
            for(char &c:word){
                int id=c-'a';
                if(cur->child[id]==nullptr)return 0;
                cur=cur->child[id];
            }
            return cur->endCnt;
    	}
	    int countWordsStartingWith(string word) {
            Node*cur=root;
            for(char &c:word){
                int id=c-'a';
                if(cur->child[id]==nullptr)return 0;
                cur=cur->child[id];
            }
            return cur->pCnt;            	        
    	}

	    void erase(string word) {
            if(countWordsEqualTo(word)==0)return;
	        Node*cur=root;
            for(char &c:word){
                int id=c-'a';
                cur=cur->child[id];
                cur->pCnt--;
            }
            cur->endCnt--;
	    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");

    cout << trie.countWordsEqualTo("apple") << '\n';      // 2
    cout << trie.countWordsStartingWith("app") << '\n';   // 3

    trie.erase("apple");
    trie.erase("banana"); // safe, nothing happens

    cout << trie.countWordsEqualTo("apple") << '\n';      // 1
    cout << trie.countWordsStartingWith("app") << '\n';   // 2

    return 0;
}