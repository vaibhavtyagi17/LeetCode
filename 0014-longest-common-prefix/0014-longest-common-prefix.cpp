class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int c;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        c = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->c++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void lowestcommonprefix(TrieNode* root, string first, string& ans) {
        for (int i = 0; i < first.length(); i++) {
            char ch = first[i];
            if (root->c == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            } else {
                break;
            }
            if (root->isTerminal) {
                break;
            }
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (const string& s : strs) {
            if (s.empty()) return "";
        }
        Trie* t = new Trie();
        for (int i = 0; i < strs.size(); i++) {
            t->insert(strs[i]);
        }
        string ans = "";
        t->lowestcommonprefix(t->root, strs[0], ans);
        return ans;
    }
};
