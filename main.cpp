#include <iostream>
#include <fstream>
#include <vector>
// #include <locale> Doesnt support multibyte characters

using namespace std;

long file_size(string &path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    file.seekg(0, ios::end);
    long size = file.tellg();
    return size;
}

vector<string> file_line(string &path) {
    vector<string> lines;
    fstream file_handler(path.c_str());

    if (file_handler.fail()) {
        cout << "Can't open the file\n";
        return lines;
    }

    string line;
    while (getline(file_handler, line))
        lines.push_back(line);

    file_handler.close();
    return lines;
}

vector<string> file_word(string &path) {
    vector<string> words;
    fstream file_handler(path.c_str());

    if (file_handler.fail()) {
        cout << "Can't open the file\n";
        return words;
    }
    string ss;
    while (file_handler >> ss)
        words.push_back(ss);

    file_handler.close();
    return words;
}

vector<char> file_chars(string &path) {
    vector<char> chars;
    fstream file_handler(path.c_str());

    if (file_handler.fail()) {
        cout << "Can't open the file\n";
        return chars;
    }
    char ch;
    while (file_handler.get(ch))
        chars.push_back(ch);

    file_handler.close();
    return chars;
}

int main(int argc, char* argv[]) {

    if (argc == 2) {
        string path = argv[1];

        vector<string> lines = file_line(path);
        cout <<lines.size() << endl;

        vector<string> words = file_word(path);
        cout << words.size() << endl;

        long sizee = file_size(path);
        cout <<sizee  << endl;

        return 0;
    }

    string path = argv[2];

    if (string(argv[1]) == "-c") {
        long sizee = file_size(path);
        cout << sizee<< endl;
    }

    if (string(argv[1]) == "-l") {
        vector<string> lines = file_line(path);
        cout << lines.size() << endl;
    }

    if (string(argv[1]) == "-w") {
        vector<string> words = file_word(path);
        cout<< words.size() << endl;
    }

    if (string(argv[1]) == "-m") {
        vector<char> chars = file_chars(path);
        cout<<chars.size() << endl;
    }

    return 0;
}
