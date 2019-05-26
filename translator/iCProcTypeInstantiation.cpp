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

	//update context
	context.proctype_instantiation = this;

	iCStateList state_list = proctype->get_states();
	if (2 <= state_list.size())//proctype has states other than FS_START
	{
		//state names enumerators
		unsigned int state_id = 3;
		context.to_code_fmt("enum %s_STATES\n{\n", name.c_str());
		for (iCStateList::const_iterator s = state_list.begin(); s != state_list.end(); s++)
		{
			iCState& state = **s;
			if (!state.special)
			{
				std::string state_name = name + state.name;
				context.to_code_fmt("\t%s=%d,\n", state_name.c_str(), state_id++);
			}
		}
		context.to_code_fmt("};\n\n");
	}

	iCVariablesList var_list = proctype->get_variables();
	for (iCVariablesList::iterator i = var_list.begin(); i != var_list.end(); i++)
	{
		iCVariable *var = *i;
		var->full_name = name + "_" + (*i)->name; //todo: changing field of var for every instance is not ok
		std::cout << "iCProcTypeInstantiation: instance var full_name=" << var->full_name << std::endl;

		context.disable_indentation();
		var->gen_code(context);
		context.enable_indentation();
		context.to_code("");
	}

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

	for (iCStateList::iterator i = state_list.begin(); i != state_list.end(); i++)
		(*i)->gen_code(context);

	//process footer
	context.indent_depth--;
	context.indent();
	context.to_code_fmt("}  //process %s\n\n", name.c_str());

	//update context
	context.proctype_instantiation = NULL;

	std::cout << "iCProcTypeInstantiation.gen_code ended for " << name << std::endl;
}
