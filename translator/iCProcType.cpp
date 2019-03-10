#include "iCProcType.h"
#include "CodeGenContext.h"
#include "ParserContext.h"

void iCProcType::gen_code(CodeGenContext& context)
{
    std::cout << "entered proctype codegen" << std::endl;
    context.to_code_fmt("\n");
    context.to_code_fmt("%s\n", C_COMMENT_FRAME);
    context.to_code_fmt("//Process type: %s\n", name.c_str());
    context.to_code_fmt("%s\n", C_COMMENT_FRAME);
    context.set_location(line_num, filename);
    context.indent();

    context.to_code_fmt("proctype %s was handled\n", this->name);
}

iCProcType::iCProcType(const std::string& name, const ParserContext& context) : iCNode(context)
{
    std::cout << "proctype constructor call message;" << std::endl;
    printf("name=%s\n", name);
    this->line_num = context.line();
    this->name = name;
}
