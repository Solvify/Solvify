#include<iostream>
#include<string>
#include<unordered_map>
#ifndef CONSTANTS_H
#define CONSTANTS_H

using namespace std;

struct Constants {
    string TABLE_TEMPLATE;
    string SILUTION_LINK_PRIFIX;
    unordered_map<string, string> images;
    Constants() : TABLE_TEMPLATE("<!-- \nIcon link template for the diff lang\n[<img src=\"https://img.icons8.com/color/c-plus-plus-logo.png\" width=\"30px\" height=\"30px\">](your_file_link)\n[<img src=\"https://img.icons8.com/color/java.png\" width=\"30px\" height=\"30px\">](your_file_link)\n[<img src=\"https://img.icons8.com/color/javascript.png\" width=\"30px\" height=\"30px\">](your_file_link)\n[<img src=\"https://img.icons8.com/color/python.png\" width=\"30px\" height=\"30px\">](your_file_link)\n-->\n| ID  | Problem | Solution |\n| :-: | :------ | :------: |"), SILUTION_LINK_PRIFIX("https://github.com/pol-alok/competitive-programming/blob/master/"), images({ {"cpp", "[<img src=\"https://img.icons8.com/color/c-plus-plus-logo.png\" width=\"30px\" height=\"30px\">]"}, {"java", "[<img src=\"https://img.icons8.com/color/java.png\" width=\"30px\" height=\"30px\">]"}, {"js", "[<img src=\"https://img.icons8.com/color/javascript.png\" width=\"30px\" height=\"30px\">]"}, {"py", "[<img src=\"https://img.icons8.com/color/python.png\" width=\"30px\" height=\"30px\">]"} }) {}

};

#endif