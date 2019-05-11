#include "iCProcType.h"
#include "CodeGenContext.h"
#include "ParserContext.h"
#include "iCState.h"

iCProcType::iCProcType(const std::string& name, const ParserContext& context) : iCNode(context)
{
	//printf("proctype %s constructor call message\n", name.c_str());
    this->line_num = context.line();
    this->name = name;
}

void iCProcType::add_states(const iCStateList& states)
{
	this->states = states;
	//printf("iCProcType.add_states: argument states size =%d, this->states size=%d\n", states.size(), this->states.size());
	//todo: if (isr_driven) ? (see iCProcess)
}

//const iCStateList& iCProcType::copy_states() const
//{
//	iCStateList copied_states;// = states; //copy
//	for (iCStateList::const_iterator i = states.begin(); i < states.end(); i++)
//	{
//		iCState *state = new iCState(**i);
//		copied_states.push_back(state);
//	}
//	return states;
//}

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
