#include <bits/stdc++.h>

using namespace std;

int main() {
    string filePath = "answers.txt";
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Unable to open the file." << endl;
        return 1;
    }

    string question;

    while (true) {
        cout << "Ask a question (type 'exit' to quit): ";
        getline(cin, question);

        if (question == "exit") {
            break;
        }

        transform(question.begin(), question.end(), question.begin(), ::tolower);

        string bestMatch;
        int maxMatchingChars = 0;

        string line;
        while (getline(inputFile, line)) {
            transform(line.begin(), line.end(), line.begin(), ::tolower);

            int matchingChars = 0;
            for (int i = 0; i < question.length(); ++i) {
                int cnt = 0;
                for (int j = 0; j < line.length() && i + j < question.length(); ++j) {
                    if (question[i + j] == line[j]) {
                        cnt++;
                    }
                }
                matchingChars = max(cnt, matchingChars);
            }

            if (matchingChars > maxMatchingChars) {
                maxMatchingChars = matchingChars;
                bestMatch = line;
            }
        }

        inputFile.clear(); // Clear the end-of-file flag
        inputFile.seekg(0, ios::beg); // Rewind to the beginning of the file

        cout << "Closest matching question: " << bestMatch << endl;
    }

    inputFile.close();
    return 0;
}
