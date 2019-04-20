#include "iCProcType.h"
#include "CodeGenContext.h"
#include "ParserContext.h"

iCProcType::iCProcType(const std::string& name, const ParserContext& context) : iCNode(context)
{
	//printf("proctype %s constructor call message\n", name.c_str());
    this->line_num = context.line();
    this->name = name;
}

const StateList& iCProcType::get_states()
{
	return states;
}

//todo: remove gen_code
void iCProcType::gen_code(CodeGenContext& context)
{
	//std::cout << "entered proctype codegen" << std::endl;
	context.to_code_fmt("\n");
	context.to_code_fmt("%s\n", C_COMMENT_FRAME);
	context.to_code_fmt("//Process type: %s\n", name.c_str());
	context.to_code_fmt("%s\n", C_COMMENT_FRAME);
	context.set_location(line_num, filename);
	context.indent();

	//printf("proctype %s was handled\n", this->name.c_str());
}
