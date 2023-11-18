#pragma once
#include <map>
#include <string>

const std::map<std::string, int> clothesSizeDictionary{
    {"Small", 1},
    {"Medium", 2},
    {"Large", 3},
};

const std::map<std::string, char> materialToSymbol{
    {"Silk", '"'},
    {"Denim", '-'},
    {"Cotton", '*'},
    {"Wool", '+'},
    {"Leather", '#'},
    {"Linen", '&'},
    {"Velvet", '%'},
};

const std::map<std::string, std::string> colorToHex{
    {"Black", "#000000"},
    {"White", "#FFFFFF"},
    {"Red", "#FF0000"},
    {"Green", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Yellow", "#FFFF00"},
    {"Purple", "#800080"},
};
