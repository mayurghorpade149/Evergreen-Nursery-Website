#include <iostream>
#include <fstream>
#include <string>

class FileReader {
public:
    FileReader(const std::string& filename) : filename(filename) {}

    bool readAndPrintFileContent() {
        if (filename.empty()) {
            std::cerr << "File name is empty." << std::endl;
            return false;
        }

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "File does not exist: " << filename << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            fileContent += line + "\n";
        }

        file.close();
        std::cout << "File Data: " << std::endl << fileContent << std::endl;
        return true;
    }

private:
    std::string filename;
    std::string fileContent;
};

int main() {
    FileReader reader("Sample.txt");
    if (reader.readAndPrintFileContent()) {
        // File was read successfully.
    } else {
        // Handle the error.
    }

    return 0;
}
