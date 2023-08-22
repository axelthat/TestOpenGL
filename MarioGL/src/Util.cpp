#include "Util.h"

std::string Util::ReadFileContents(const std::string& path) {
	std::ifstream file(path);

	std::stringstream stream;
	stream << file.rdbuf();

	auto contents = stream.str();

	file.close();

	return contents;
}

std::vector<std::string> Util::Split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}