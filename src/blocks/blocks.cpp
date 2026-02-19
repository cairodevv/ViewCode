#include "blocks.h"

Print::Print(std::string output) : Block("print", NORMAL, {"std::cout << " + std::move(output)}, {{"output", typeid(output)}}) {}

Include::Include(std::string file) : Block("include", HEADER, {"#include " + std::move(file)}, {{"file", typeid(file)}}) {}

IfNotDefined::IfNotDefined(std::string define) : Block("ifnotdefined", ENCLOSED, {"#ifndef " + std::move(define), "#endif"}, {{"define", typeid(define)}}) {}

IfDefined::IfDefined(std::string define) : Block("ifdefined", ENCLOSED, {"#ifdef " + std::move(define), "#endif"}, {{"define", typeid(define)}}) {}

Define::Define(std::string  define) : Block("define", HEADER, {"#define " + std::move(define)}, {{"define", typeid(define)}}) {}
