#ifndef VIEWCODE_BLOCKS
#define VIEWCODE_BLOCKS

#include <stdexcept>
#include "types.h"
#include <typeinfo>

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
    explicit IfNotDefined(/* implement header define enum */ auto define)
    : Block(
        "ifnotdefined",
        ENCLOSED,
        {"#ifndef " + std::move(define), "#endif"},
        {
            {
                "define",
                typeid(define)
            }})
    {
        throw std::logic_error("TODO: implement header define enum in file class");
    }
};

class IfDefined : public Block {
public:
    explicit IfDefined(/* implement header define enum */ auto define)
    : Block(
        "ifdefined",
        ENCLOSED,
        {"#ifdef " + std::move(define), "endif"},
        {
            {
                "define",
                typeid(define)
            }})
    {
        throw std::logic_error("TODO: implement header define enum in file class");
    }
};

class Define : public Block {
public:
    explicit Define(/* implement header define enum */ auto define)
    : Block(
        "define",
        HEADER,
        {"#define " + std::move(define)},
        {
            {
                "define",
                typeid(define)
            }})
    {
        throw std::logic_error("TODO: implement header define enum in file class");
    }
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


#endif //VIEWCODE_BLOCKS
