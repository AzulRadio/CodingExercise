#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node * curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->chars[word[i] - 'a'] == NULL) {
                curr->chars[word[i] - 'a'] = new Node();
            }
            curr = curr->chars[word[i] - 'a'];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_recur(root, word, 0);
    }
    
private:
    struct Node{
        bool isEnd;
        vector<Node*> chars;
        Node() {
            isEnd = false;
            chars = vector<Node*> (26, nullptr);
        }
    };
    
    Node *root;
    
    
    bool search_recur(Node * curr, string word, int index) {
        if (index >= word.size()) {
            return false;
        }
        
        if (index == word.size() - 1) {
            if (word[index] !='.' &&
                curr->chars[word[index]-'a'] != NULL &&
                curr->chars[word[index]-'a']->isEnd)
            return true;
        } 
        
        if (word[index] != '.') {
            if (curr->chars[word[index] - 'a'] == NULL) {
                return false;
            }
            return search_recur(curr->chars[word[index] - 'a'], word, index + 1);
        } 
        
        bool ret = false;
        for (int i = 0; i < 26; i++) {
            if (curr->chars[i] == NULL) {
                continue;
            }
			if (index == word.size() - 1 && curr->chars[i]->isEnd) {
				ret = true;
			}
            ret = ret || search_recur(curr->chars[i], word, index + 1);
        }
        return ret;
    }
};

int main() {
	WordDictionary* obj = new WordDictionary();
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad"); 
	obj->search("pad");
	obj->search("bad");
	obj->search(".ad");
	obj->search("b..");
	//obj->search("a.");
	
}