#include<iostream>
#include <vector>
#include<unordered_map>
#include <string>

using namespace std;

class Solution {
public:

    string getEncodedWord(string simple_word) {
        string encoding_characters[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string encoded_word = "";

        for(char ch : simple_word) encoded_word += encoding_characters[ch-97];

        return encoded_word;
    }

    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int>  unique_encoded_words;

        for(string wrd : words) {
            unique_encoded_words[getEncodedWord(wrd)]++;
        }

        return unique_encoded_words.size();
    }
};


int main() {
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution Solution;
    cout << Solution.uniqueMorseRepresentations(words) << endl;
    return 0;
}
