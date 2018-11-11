#include <iostream>
#ifdef __MING32__
	#include <windows.h>
#elif __linux__
	#include <dirent.h>
#endif

#include "../include/resources.hpp"
#include "../include/util.hpp"

using std::string;
using std::vector;

std::map<string, sf::Texture> Resources::Textures = {};
std::map<string, sf::Font> Resources::Fonts = {};

void Resources::addTexture(const string &name, const string &path) {
    sf::Texture tex;
    tex.loadFromFile(path);
    Resources::Textures[name] = tex;
}

void Resources::addFont(const string &name, const string &path) {
    sf::Font font;
    font.loadFromFile(path);
    Resources::Fonts[name] = font;
}

void Resources::listFolderFiles(const string &path, int degree, string fullQualifier) {
    vector<string> folderList;
#ifdef __MING32__
    HANDLE hFind;
    WIN32_FIND_DATA data;
    string searchPath = path + "*.*";
    hFind = FindFirstFile(searchPath.c_str(), &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
			string filename = data.cFileName;
            if (string(filename) == "." or string(filename) == "..") continue;
            if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 16) {
                folderList.push_back(string(filename));
            }
            else {
                string fileExtension = split(fullQualifier.substr(1) + "_" + filename, '.')[1];
                string key = split(fullQualifier.substr(1) + "_" + filename, '.')[0];
                string value = path + filename;
                if (fileExtension == "ttf")
                    addFont(key, value);
                else
                    addTexture(key, value);
            }
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
#elif __linux__
	DIR *d;
	struct dirent *dir;
	d = opendir(path.c_str());
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			string filename = dir->d_name;
			if (filename == "." or filename == "..") continue;
			string tabs = string(degree, ' ');
			if (dir->d_type == DT_DIR) {
				listFolderFiles(path + filename + "/", degree+1, fullQualifier + "_" + filename);
			}
			else {
                string fileExtension = split(fullQualifier.substr(1) + "_" + filename, '.')[1];
                string key = split(fullQualifier.substr(1) + "_" + filename, '.')[0];
                string value = path + filename;
                if (fileExtension == "ttf")
                    addFont(key, value);
                else
                    addTexture(key, value);
			}
		}
		closedir(d);
	}
#endif
    for (auto &p : folderList)
        listFolderFiles(path + p + "\\", degree+1, fullQualifier + "_" + p);
}

void Resources::scan(const string &rootPath) {
    string fullQualifier = "";
    listFolderFiles(rootPath, 0, fullQualifier);
}

sf::Font& Resources::getFont(const string &fontKey) {
    std::cout << fontKey << std::endl;
    if (Resources::Fonts.count(fontKey) == 0)
        std::cout << "KEY NOT IN FONTS" << std::endl;
    return Resources::Fonts[fontKey];
}

sf::Texture& Resources::getTexture(const string &textureKey) {
    std::cout << textureKey << std::endl;
    if (Resources::Textures.count(textureKey) == 0)
        std::cout << "KEY NOT IN RESOURCES" << std::endl;
    return Resources::Textures[textureKey];
}
