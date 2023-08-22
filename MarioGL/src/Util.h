#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Util {
public:
	static std::string ReadFileContents(const std::string& path);
	static std::vector<std::string> Split(const std::string& s, char delimiter);
};