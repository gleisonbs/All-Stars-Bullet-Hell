#include <iostream>
#ifdef __MING32__
	#include <windows.h>
#elif __linux__
	#include <dirent.h>
#endif

#include "../include/resources.hpp"
#include "../include/util.hpp"

std::map<string, sf::Texture> Resources::Textures = {};
std::map<string, sf::Font> Resources::Fonts = {};

using std::string;
using std::vector;

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
#ifdef __MING32__
	std::cout << "WINDOWS DEF" << std::endl;
    HANDLE hFind;
    WIN32_FIND_DATA data;

    vector<string> folderList;

    string searchPath = path + "*.*";
    hFind = FindFirstFile(searchPath.c_str(), &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (string(data.cFileName) == "." or string(data.cFileName) == "..") continue;
            if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 16) {
                folderList.push_back(string(data.cFileName));
            }
            else {
                for (int i = 0; i < degree; i++) std::cout << "\t";
                //addTexture(fullQualifier, )
                string key = split(fullQualifier.substr(1) + "_" + data.cFileName, '.')[0];
                string fileExtension = split(fullQualifier.substr(1) + "_" + data.cFileName, '.')[1];
                string value = path + data.cFileName;
                std::cout << "key: " << key << " - val: " << value << std::endl;
                if (fileExtension == "ttf")
                    addFont(key, value);
                else
                    addTexture(key, value);
            }
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }

    for (auto &p : folderList) {
        listFolderFiles(path + p + "\\", degree+1, fullQualifier + "_" + p);
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
				std::cout << tabs << path + filename + "/" << std::endl;
				listFolderFiles(path + filename + "/", degree+1, fullQualifier + "_" + filename);
			}
			else {
				std::cout << tabs << filename << std::endl;
			}
		}
		closedir(d);
	}
#endif
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
