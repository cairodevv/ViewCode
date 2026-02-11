#ifndef VIEWCODE_TYPES
#define VIEWCODE_TYPES

#include <string>
#include <vector>
#include <typeinfo>

enum BlockTypes {
    ENCLOSED,
    VARIABLE,
    OPERATOR,
    NORMAL,
    EXPRESSION,
    HEADER
};

struct Block {
    std::string name;
    BlockTypes blockType;
    std::pair<std::string, std::string> text;
    std::vector<std::pair<std::string, const std::type_info&>> parameters;


    Block(
        std::string name,
        const BlockTypes blockType,
        std::string text,
        std::vector<std::pair<std::string,
        const std::type_info&>> parameters
        ):
    name(std::move(name)),
    blockType(blockType),
    text(std::move(text), ""),
    parameters(std::move(parameters)) {}

    Block(
        std::string name,
        const BlockTypes blockType,
        std::pair<std::string, std::string> text,
        std::vector<std::pair<std::string,
        const std::type_info&>> parameters
        ):
    name(std::move(name)),
    blockType(blockType),
    text(std::move(text)),
    parameters(std::move(parameters)) {}
};

#endif //VIEWCODE_TYPES