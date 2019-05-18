#include "iCProcTypeInstantiation.h"
#include "iCProgram.h"
#include "iCProcType.h"
#include "iCProcess.h"
#include "iCState.h"

iCProcTypeInstantiation::iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name, 
	const std::string& instance_name) : program(program), proctype_name(proctype_name), instance_name(instance_name)
{
	printf("iCProcTypeInstantiation constructor, proctype_name = %s, instance_name = %s\n", 
		proctype_name.c_str(), instance_name.c_str());
}

void iCProcTypeInstantiation::gen_code(CodeGenContext& context)
{
	if (instance_name.length() == 0)
	{
		printf("iCProcTypeInstantiation error - instance is empty\n");
		return;
	}
	printf("iCProcTypeInstantiation instance_name is not empty, it's name=%s\n", instance_name.c_str());

	//check whether such proctype exists
	const iCProcType* proctype = program->find_proctype(proctype_name);
	if (NULL == proctype)
	{
		err_msg("undefined process type %s", proctype_name.c_str());
		return;
	}
	printf("iCProcTypeInstantiation found valid proctype %s\n", proctype->name.c_str());

	iCVariablesList var_list = proctype->get_variables();
	for (iCVariablesList::iterator i = var_list.begin(); i != var_list.end(); i++)
	{
		iCVariable *var = new iCVariable(**i);
		var->full_name = instance_name + "_" + (*i)->name;
		std::cout << "iCProcTypeInstantiation: instance var full_name=" << var->full_name << std::endl;
		var->gen_code(context);
	}

	iCStateList state_list = proctype->get_states();
	for (iCStateList::iterator i = state_list.begin(); i != state_list.end(); i++)
		(*i)->gen_code(context);
}
