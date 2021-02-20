#include <iostream>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    int frq_magazine[123]{0},frq_note[123]{0},no_of_character_matched=0,no_of_character_note_has=0;
    for(char c: magazine)   ++frq_magazine[c];
    for(char c: ransomNote) {
        ++frq_note[c];
        ++no_of_character_note_has;
    }
    for(int i=96; i<123; i++)   if(frq_note[i]!=0 && frq_magazine[i]>=frq_note[i])    no_of_character_matched+=frq_note[i];
    return no_of_character_matched == no_of_character_note_has;
}
int main() {


    cout<<canConstruct("aa","ab");

    return 0;
}