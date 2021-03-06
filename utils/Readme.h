#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<unordered_map>
#include <algorithm>
#include <cctype>
#include <regex>
#include "Row.h"
#include "Data.h"
#include "Constants.h"

using namespace std;

#ifndef README_H
#define README_H

Constants constants;

class Readme {
private:
    inline string trim(const string& s) {
        auto wsfront = find_if_not(s.begin(), s.end(), [](int c) {return isspace(c);});
        auto wsback = find_if_not(s.rbegin(), s.rend(), [](int c) {return isspace(c);}).base();
        return (wsback <= wsfront ? string() : string(wsfront, wsback));
    }

    string extractIdFromIdWithLink(string idWithLink) {
        return idWithLink.substr(3, idWithLink.find("]") - 4);
    }

    string getLang(string newSolutionLink) {
        return trim(newSolutionLink.substr(newSolutionLink.find_last_of(".") + 1, newSolutionLink.length()));
    }

    string buildSolution(string solutionLink) {
        return constants.images[getLang(solutionLink)] + "(" + solutionLink + ")";
    }

    Row* buildNewRow(Data data, Row* next = nullptr) {
        string idWithLink = "[`#" + data.id + "`](" + data.problemLink + ")";
        string program = data.problemName;
        string solution = buildSolution(data.solutionLink);
        return new Row(data.id, idWithLink, program, solution, next);
    }

    Row* getRowFromLine(string line) {
        size_t pos = 0;
        vector<string> tokens;
        string token;
        while ((pos = line.find("|")) != string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(trim(token));
            line.erase(0, pos + 1);
        }
        return new Row(extractIdFromIdWithLink(tokens[1]), tokens[1], tokens[2], tokens[3]);
    }
    Row getRowFromLineAsElement(string line) {
        size_t pos = 0;
        vector<string> tokens;
        string token;
        if (trim(line) == "")
            return Row();
        while ((pos = line.find("|")) != string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(trim(token));
            line.erase(0, pos + 1);
        }
        return Row(extractIdFromIdWithLink(tokens[1]), tokens[1], tokens[2], tokens[3]);
    }

    Row* insert(Row* head, Data data) {
        if ((head == nullptr) || !(head->id < data.id)) {
            return buildNewRow(data, head);
        }
        head->next = insert(head->next, data);
        return head;
    }
    string newSolution(string oldSolution, Data data) {
        return oldSolution + buildSolution(data.solutionLink);
    }

    bool isCurrentLangSolutionExixts(string solution, string lang) {
        size_t pos = 0;
        return ((pos = solution.find("." + lang)) != string::npos);
    }

    bool insertSolution(Row* head, Data data) {
        if (head->id == data.id) {
            if (isCurrentLangSolutionExixts(head->solution, getLang(data.solutionLink))) {
                return false;
            } else {
                head->solution.replace(0, head->solution.length(), newSolution(head->solution, data));
                return true;
            }

        }
        return insertSolution(head->next, data);
    }
    Row* insert(Row* head, string line) {
        if (!head) {
            return getRowFromLine(line);
        }
        head->next = insert(head->next, line);
        return head;
    }

    Row* readDataFromFile(string platform) {
        Row* head = nullptr;
        ifstream file("../" + platform + "/README.md");
        if (file.is_open()) {
            string line;
            int skip = 10;
            while (getline(file, line)) {
                if (--skip < 0) {
                    if (trim(line) == "")
                        break;
                    head = insert(head, line);
                } else {
                    constants.FILE_PREFIX_DATA += line + "\n";
                }
            }
            file.close();
        }
        return head;
    }

    vector<Row> readDataFromFileAsArray(string platform) {
        vector<Row> records = {};
        fstream readme("../" + platform + "/README.md");
        if (!readme) {
            cout << "File not created!" << endl;
        } else  if (readme.is_open()) {
            string line;
            int skip = 10;
            while (getline(readme, line)) {
                if (--skip < 0) {
                    Row row = getRowFromLineAsElement(line);
                    if (row.id == "")
                        break;
                    records.push_back(row);
                }
            }
            readme.close();
        }
        return records;
    }

    bool searchWithId(vector<Row>& records, int start, int end, string id) {
        return binary_search(records.begin(), records.end(), Row(id));
    }

    void writeData(Row* curr, ofstream& readme) {
        if (curr == nullptr) {
            cout << "\n";
            return;
        }
        readme << curr->toRow() << endl;
        writeData(curr->next, readme);
    }

    int writeDataTofile(Row* head, string platform) {
        ofstream readme("../" + platform + "/README.md");
        if (!readme) {
            cout << "File not created!";
        } else {
            // cout << "File created successfully!" << endl;
            readme << constants.FILE_PREFIX_DATA;
            writeData(head, readme);
            readme << endl;
            readme << constants.FILE_SUFFIX_DATA << endl;
            readme.close();
        }
        return 0;
    }

    // void printList(Row* curr) {
    //     if (curr == nullptr) {
    //         cout << "\n";
    //         return;
    //     }
    //     cout << curr->id << " " << curr->idWithLink << endl;
    //     printList(curr->next);
    // }

    bool addNewRow(Data data) {
        vector<Row> records = readDataFromFileAsArray(data.platform);
        if (records.size() != 0 && searchWithId(records, 0, records.size(), data.id)) {
            cout << "Given Id #" + data.id + " already exists!\n" << endl;
            return false;
        }
        Row* head = readDataFromFile(data.platform);
        // printList(head);
        head = insert(head, data);
        writeDataTofile(head, data.platform);
        cout << "Entry Added successfully!\n" << endl;
        return true;
    }

    bool addSolution(Data data) {
        vector<Row> records = readDataFromFileAsArray(data.platform);

        if (!searchWithId(records, 0, records.size(), data.id)) {
            cout << "Given Id #" + data.id + " not exists!\nPlease check and add." << endl;
            return false;
        }
        Row* head = readDataFromFile(data.platform);
        if (insertSolution(head, data)) {
            writeDataTofile(head, data.platform);
            cout << "Solution Added successfully!" << endl;
            return true;
        } else {
            cout << "Solution In " + getLang(data.solutionLink) + " Already exist!\nPlease put your solution in already existed file." << endl;
            return false;
        }
    }

public:
    Readme() {
    }
    string generateSolutionLink(string relativePath) {
        return constants.SILUTION_LINK_PRIFIX + relativePath;
    }
    int addRow(Data data) {
        if (!addNewRow(data)) {
            addSolution(data);
        }
        return 0;
    }
};

#endif
