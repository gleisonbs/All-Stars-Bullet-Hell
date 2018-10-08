#include <iostream>
#include <windows.h>

#include "../include/resources.hpp"
#include "../include/util.hpp"

std::map<std::string, sf::Texture> Resources::Textures = {};
std::map<std::string, sf::Font> Resources::Fonts = {};

void Resources::addTexture(const std::string &name, const std::string &path) {
    sf::Texture tex;
    tex.loadFromFile(path);
    Resources::Textures[name] = tex;
}

void Resources::addFont(const std::string &name, const std::string &path) {
    sf::Font font;
    font.loadFromFile(path);
    Resources::Fonts[name] = font;
}

void Resources::listFolderFiles(const std::string &path, int degree, std::string fullQualifier) {
    HANDLE hFind;
    WIN32_FIND_DATA data;

    // removes backslash at the end

    //fullQualifier = fullQualifier.substr(0, fullQualifier.size()-1);

    std::vector<std::string> folderList;

    std::string searchPath = path + "*.*";
    hFind = FindFirstFile(searchPath.c_str(), &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (std::string(data.cFileName) == "." or std::string(data.cFileName) == "..") continue;
            if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 16) {
                folderList.push_back(std::string(data.cFileName));
            }
            else {
                for (int i = 0; i < degree; i++) std::cout << "\t";
                //addTexture(fullQualifier, )
                std::string key = split(fullQualifier.substr(1) + "_" + data.cFileName, '.')[0];
                std::string fileExtension = split(fullQualifier.substr(1) + "_" + data.cFileName, '.')[1];
                std::string value = path + data.cFileName;
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
}

void Resources::scan(const std::string &rootPath) {
    std::string fullQualifier = "";
    listFolderFiles(rootPath, 0, fullQualifier);
}

sf::Font& Resources::getFont(const std::string &fontKey) {
    std::cout << fontKey << std::endl;
    if (Resources::Fonts.count(fontKey) == 0)
        std::cout << "KEY NOT IN FONTS" << std::endl;
    return Resources::Fonts[fontKey];
}

sf::Texture& Resources::getTexture(const std::string &textureKey) {
    std::cout << textureKey << std::endl;
    if (Resources::Textures.count(textureKey) == 0)
        std::cout << "KEY NOT IN RESOURCES" << std::endl;
    return Resources::Textures[textureKey];
}
