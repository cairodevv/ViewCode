#ifndef VIEWCODE_BLOCKS
#define VIEWCODE_BLOCKS

#include <stdexcept>
#include "types/types.h"
#include <string>
#include <typeinfo>

/*
 All implemented blocks:
 Print
 Include
 IfNotDefined
 IfDefined
 Define
 Loop
 If
 IfElse(needs 3rd text)
 Elif
 */
class Print : public Block {
public:
    explicit Print(std::string output)
    : Block(
        "print",
        NORMAL,
        {"std::cout << " + std::move(output)},
        {
            {
                "output",
                typeid(output)
            }})
    {}
};

class Include : public Block {
public:
    explicit Include(std::string file)
    : Block(
        "include",
        HEADER,
        {"#include " + std::move(file)},
        {
            {
                "file",
                typeid(file)
            }})
    {}
};

class IfNotDefined : public Block {
public:
    explicit IfNotDefined(std::string define)
    : Block(
        "ifnotdefined",
        ENCLOSED,
        {"#ifndef " + std::move(define), "#endif"},
        {
            {
                "define",
                typeid(define)
            }})
    {}
};

class IfDefined : public Block {
public:
    explicit IfDefined(std::string define)
    : Block(
        "ifdefined",
        ENCLOSED,
        {"#ifdef " + std::move(define), "#endif"},
        {
            {
                "define",
                typeid(define)
            }})
    {}
};

class Define : public Block {
public:
    explicit Define(std::string  define)
    : Block(
        "define",
        HEADER,
        {"#define " + std::move(define)},
        {
            {
                "define",
                typeid(define)
            }})
    {}
};

class Loop : public Block {
public:
    explicit Loop(int length)
    : Block(
    "loop",
    ENCLOSED,
    {"for (int i = 0; i < " + std::to_string(length) + "; i++) {", "}"},
    {
        {
            "length",
            typeid(length)
        }})
    {}
};

class If : public Block {
public:
    explicit If(bool condition)
    : Block(
        "if",
        ENCLOSED,
        {"if (" + std::to_string(condition) + ") {", "}"},
        {
            {
                "condition",
                typeid(condition)
            }})
    {}
};

class IfElse : public Block {
public:
    explicit IfElse(bool condition)
    : Block(
        "ifelse",
        ENCLOSED,
        {"if (" + std::to_string(condition) + ") {", "} else {"},
        {
            {
                "condition",
                typeid(condition)
            }})
    {}
};

class Elif : public Block {
public:
    explicit Elif(bool condition)
    : Block(
        "elif",
        ENCLOSED,
        {"else if (" + std::to_string(condition) + ") {", "}"},
        {
            {
                "condition",
                typeid(condition)
            }})
    {}
};

#endif //VIEWCODE_BLOCKS
