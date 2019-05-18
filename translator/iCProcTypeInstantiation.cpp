#include "iCProcTypeInstantiation.h"
#include "CodeGenContext.h"
#include "iCProgram.h"
#include "iCProcType.h"
#include "iCProcess.h"
#include "iCState.h"

iCProcTypeInstantiation::iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name,
	const std::string& instance_name, const ParserContext& context) : program(program), proctype_name(proctype_name), 
	iCProcess(instance_name, context)
{
	printf("iCProcTypeInstantiation constructor, proctype_name = %s, instance_name = %s\n",
		proctype_name.c_str(), instance_name.c_str());
}

void iCProcTypeInstantiation::second_pass()
{
	if (name.length() == 0)
	{
		printf("iCProcTypeInstantiation error - instance is empty\n");
		return;
	}
	printf("iCProcTypeInstantiation instance_name is not empty, it's name=%s\n", name.c_str());

	//check whether such proctype exists
	proctype = program->find_proctype(proctype_name);
	if (NULL == proctype)
	{
		err_msg("undefined process type %s", proctype_name.c_str());
		return;
	}
	printf("iCProcTypeInstantiation found valid proctype %s\n", proctype->name.c_str());

	program->add_process(this);
}

void iCProcTypeInstantiation::gen_code(CodeGenContext& context)
{
	std::cout << "iCProcTypeInstantiation.gen_code called for " << name << std::endl;

	iCVariablesList var_list = proctype->get_variables();
	for (iCVariablesList::iterator i = var_list.begin(); i != var_list.end(); i++)
	{
		iCVariable *var = new iCVariable(**i);
		var->full_name = name + "_" + (*i)->name;
		std::cout << "iCProcTypeInstantiation: instance var full_name=" << var->full_name << std::endl;
		var->gen_code(context);
	}

	//update context
	context.process = this;

	//Add comments
	context.to_code_fmt("%s\n", C_COMMENT_FRAME);
	context.to_code_fmt("//Process: %s\n", name.c_str());
	context.to_code_fmt("%s\n", C_COMMENT_FRAME);
	context.set_location(line_num, filename);

	//Process header
	context.indent();
	context.to_code_fmt("switch(%s[%s].%s)\n", C_PROC_ARRAY_NAME, name.c_str(), C_STATE_FUNC_ATTR_NAME);
	context.indent();
	context.to_code_fmt("{\n");
	context.indent_depth++;

	iCStateList state_list = proctype->get_states();
	for (iCStateList::iterator i = state_list.begin(); i != state_list.end(); i++)
		(*i)->gen_code(context);

	//process footer
	context.indent_depth--;
	context.indent();
	context.to_code_fmt("}  //process %s\n\n", name.c_str());

	//update context
	context.process = NULL;

	std::cout << "iCProcTypeInstantiation.gen_code ended for " << name << std::endl;
}
