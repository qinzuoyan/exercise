#ifndef  _INCLUDE_GUARD_H_
#define  _INCLUDE_GUARD_H_

#include <string>

// Generate include guard string from name:
//   a --> _A_
//   a.b --> _A_B_
//   simple.ver_1_0_0.HelloService  --> _SIMPLE_VER_1_0_0_HELLO_SERVICE_
//   simple.ver_1_0_0.ASTParser --> _SIMPLE_VER_1_0_0_AST_PARSER_
extern std::string include_guard_str(const std::string& name);

#endif // _INCLUDE_GUARD_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
