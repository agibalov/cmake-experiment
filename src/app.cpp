#include <iostream>
#include <fstream>
#include <sstream>

#include "tinyxml2.h"

using namespace tinyxml2;

std::string readFile(std::string const& fileName);
void writeFile(std::string const& fileName, std::string const& content);

int main() {	
	writeFile("1.xml", "<html><title>hello file</title></html>");

	std::string const xml = readFile("1.xml");
	XMLDocument doc;	
	doc.Parse(xml.c_str());

	XMLElement* titleElement = doc.FirstChildElement("html")->FirstChildElement("title");
	char const* title = titleElement->GetText();
	std::cout << "read from xml: " << title << std::endl;
}

std::string readFile(std::string const& fileName) {
	std::ifstream ifs(fileName.c_str());
	std::stringstream buf;
	buf << ifs.rdbuf();
	return buf.str();	
}

void writeFile(std::string const& fileName, std::string const& content) {
	std::ofstream ofs;
	ofs.open(fileName.c_str());
	ofs << content;
	ofs.close();
}
