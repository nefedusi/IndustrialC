#include "iCProcType.h"
#include "CodeGenContext.h"
#include "ParserContext.h"

iCProcType::iCProcType(const std::string& name, const ParserContext& context) : iCNode(context)
{
	//printf("proctype %s constructor call message\n", name.c_str());
	this->line_num = context.line();
	this->name = name;
}

void iCProcType::add_states(const StateList& states)
{
	this->states = states;
	//if (isr_driven)
	//{
	//	//pass isr_driven to states
	//	for (StateList::iterator i = this->states.begin(); i != this->states.end(); i++)
	//	{
	//		iCState* state = *i;
	//		state->set_isr_driven();
	//		if (state->has_timeout())
	//			_has_timeouts = true;
	//	}
	//}
}

StateList* iCProcType::get_states()
{
	StateList* state_list = new StateList();
	for (StateList::iterator i = this->states.begin(); i != this->states.end(); i++)
	{
		iCState* state = *i;
		state_list->push_back(state);
	}
	return state_list;
}

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

iCProcType::~iCProcType()
{
	for (StateList::iterator i = states.begin(); i != states.end(); i++)
		delete *i;
}
