#ifndef PARSE_H
#define PARSE_H

#include <fstream>
#include <iostream>
#include <string>
#include <regex>

enum class stateBlock{
    BEGIN,
    IN,
    END,
};

enum class codeType {
    PYTHON,
    CPP,
    WRONG
};
extern codeType code;


extern std::string parse(std::string);
extern std::string token(std::string &);

extern bool isUnorderedList(std::string &);
extern bool isOrderedList(std::string &input);
extern bool isQuote(std::string &input);
extern bool isHerLine(std::string &input);
extern codeType isCodeBlock(std::string &input);

extern std::string regex(std::string &);




#endif // PARSE_H
