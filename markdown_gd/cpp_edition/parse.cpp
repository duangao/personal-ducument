#include "parse.h"
#include "common.h"
extern std::string parse(std::string);

bool isUnorderedList(std::string &input){
    if ((input[0] == '*' || input[0] == '+' || input[0] == '-') && input[1] == ' ') {
        return true;
    }
    else {
        return false;
    }

}

bool isQuote(std::string &input) {
    if (input[0] == '>' && input[1] == ' ') {
        return true;
    }
    else {
        return false;
    }
}
bool isOrderedList(std::string &input) {
    if (isdigit(input[0]) && input[1] == '.' && input[2] == ' ') {
        return true;
    }
    else {
        return false;
    }
}
bool isHerLine(std::string &input) {
    std::string::iterator i;
    for (i = input.begin(); i != input.end(); i++) {
        if (*i != '-') {
            break;
        }
    }
    if (i == input.end() && input.size() >= 3) {
        return true;
    }
    else {
        return false;
    }
}
codeType isCodeBlock(std::string &input){
    codeType codeSym;
    if (input == "```python") {
        codeSym = codeType::PYTHON;
    }
    else if (input == "```c++") {
        codeSym = codeType::CPP;
    }
    else {
        codeSym = codeType::WRONG;
    }
    return codeSym;
}

// handle with link sup img
std::string regex(std::string &input) {

    // \[*](*),link
    std::regex re_link("/\\[(.*)\\]\\((.*)\\)");
    input=std::regex_replace(input, re_link, "<a href=\"$2\" target=\"_blank\">$1</a>");

    std::regex re_sup("\\[(.*)\\]\\[(.*)\\]");
    input = std::regex_replace(input, re_sup, "$1<sup>$2</sup>");

    std::regex re_img("!\\[(.*),(.*)\\]\\((.*)\\)");// ![width,height](url)
    input = std::regex_replace(input, re_img, "&nbsp<img src=\"$3\" width=\"$1\" height=\"$2\" align=\"middle\">");
    return input;
}



bool isOrder=false;
bool currentLineOrder = false;

stateBlock state=stateBlock::BEGIN;

std::string tokenTemplate(std::string&input, std::string match) {
    size_t first_itatic = 0;
    size_t next_itatic = 0;
    std::string::size_type np = std::string::npos;
    size_t length = match.size();


    while (next_itatic != input.size() && first_itatic != np && next_itatic != np) {

        first_itatic = input.find(match);
        next_itatic = input.find(match, first_itatic + length);

        if (first_itatic !=np && next_itatic != np && first_itatic < next_itatic) {
            std::string temp(input, first_itatic + length, next_itatic - first_itatic - length);

            if (match == "*") {
                temp.insert(0, "<i>");
                temp += "</i>";
            }
            else if (match == "**") {
                temp.insert(0, "<b>");
                temp += "</b>";
            }
            else if (match == "~") {
                temp.insert(0, "<S>");
                temp += "</S>";
            }
            input.replace(first_itatic, next_itatic - first_itatic + length, temp);
        }
    }
    return input;
}




std::string handleItatic(std::string &input) {

    return tokenTemplate(input, "*");
}

std::string handleBold(std::string &input) {

    return tokenTemplate(input, "**");
}
std::string handleDelete(std::string &input) {
    return tokenTemplate(input, "~");
}



std::string token(std::string &input) {
    input = handleBold(input);
    input = handleItatic(input);
    input = handleDelete(input);

    return input;
}

std::string closeOrderList(std::string &input) {
    if (isOrder == true && currentLineOrder==false) {

        input.insert(0, "</ol>");
        isOrder = false;
    }
    return input;
}

std::string handleTitle(std::string input, int level)  {
    std::string temp;
    switch (level) {
        case 1:
        {
            temp = std::string(input.begin() + 2, input.end());
            temp.insert(0, "<h1>");
            temp += "</h1>";
            break;
        }
        case 2:
        {
            temp = std::string(input.begin() + 3, input.end());
            temp.insert(0, "<h2>");
            temp += "</h2>";
            break;
        }
        case 3:
        {
            temp = std::string(input.begin() + 4, input.end());
            temp.insert(0, "<h3>");
            temp += "</h3>";
            break;
        }
    }
    return temp;
}

std::string handleUnorderedList(std::string input) {
    std::string temp= input;
    temp.replace(0, 2, "<ul><li>");
    temp += "</li></ul>";
    return temp;
}

std::string handleOrderedList(std::string input) {
    std::string temp = input;
    char num = input[0];
    isOrder = true;
    currentLineOrder = true;
    if (num == '1') {
        temp.replace(0, 3, "<ol><li>");
        temp += "</li>";
    }
    else {
        temp.replace(0, 3, "<li>");
        temp += "</li>";
    }
    return temp;
}

std::string handleQuote(std::string input) {
    std::string temp = input;
    temp.replace(0, 2, "<blockquote style=\"color:#8fbc8f\"> <i>");
    temp += "</i></blockquote>";
    return temp;
}

std::string handleBlock(std::string input) {
    std::string temp = input;
    if (state == stateBlock::BEGIN) {
        temp = "<blockquote style=\"background-color:#FFEBCD\">";
        state = stateBlock::IN;
    }
    else if(state==stateBlock::IN) {
        temp = "</blockquote>";
        state = stateBlock::END;
    }
    return temp;
}
std::string handleCodeBlock() {
    std::string temp = "<blockquote style=\"background-color:#FFEBCD\">";
    return temp;

}

std::string handleHerLine() {
    return std::string("<hr>");
}

std::string setColor(std::string input) {
    std::string temp = input;
    std::vector<std::string> keyword = {"print","while","if","def","elif","import"};
    std::vector<std::string> color = { "#9900cc", "#00ffff", "#00ffff", "#8b0000", "#00ffff","#00ff00" };
    std::vector<std::string>::iterator i;
    std::vector<std::string>::iterator j;
    for (i = keyword.begin(), j = color.begin(); i != keyword.end(); i++, j++) {
        if (temp.find(*i) != std::string::npos) {
            temp = temp.replace(temp.find(*i), (*i).size(), "<font color=\"" + *j + "\">" + *i + "</font>");
        }
    }
    return temp;
}
int  preHandle(std::string &input) {

    if (input == "```") {
        input = handleBlock(input);
    }
    if (isCodeBlock(input) != codeType::WRONG) {
        input = handleCodeBlock();
        state = stateBlock::IN;
    }
    if (state == stateBlock::IN) {

        return 0;
    }

    else {
        return -1;
    }
}

std::string parse(std::string input) {
    std::string temp= input;
    if (input.empty()) {
        return "";
    }
    if (state == stateBlock::IN) {
        std::regex re_blank("\\s");
        std::regex re_lt("<");
        temp = std::regex_replace(temp, re_blank, "&nbsp");
        temp = std::regex_replace(temp, re_lt, "&lt");
    }


    if (preHandle(temp) == 0) {
        temp = setColor(temp);
        temp.insert(0, "<p>");
        temp+="</p>";
        return temp;
    }

    currentLineOrder = false;
    temp = token(temp);
    temp = regex(temp);
    if (input[0] == '#'&& input[1] == ' ') {
        temp=handleTitle(input, 1);
    }
    else if (input[0] == '#'&& input[1] == '#' &&input[2]==' ') {
        temp=handleTitle(input, 2);
    }
    else if (input[0] == '#'&& input[1] == '#' &&input[2] == '#' && input[3]==' ') {
        temp=handleTitle(input, 3);
    }

    else if (isUnorderedList(input) ){
        temp = handleUnorderedList(temp);
    }
    else if (isQuote(input)) {
        temp = handleQuote(temp);
    }
    else if (isOrderedList(input)) {
        temp = handleOrderedList(temp);
    }
    else if (isHerLine(input)) {
        temp = handleHerLine();
    }
    else {
        temp += "</br>";
    }
    closeOrderList(temp);
    return temp;
}


