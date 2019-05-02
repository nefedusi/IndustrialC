#include "iCProcTypeInstantiation.h"
#include "iCProgram.h"
#include "iCProcType.h"
#include "iCProcess.h"

iCProcTypeInstantiation::iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name, 
	iCProcess* instance) : program(program), proctype_name(proctype_name), instance(instance)
{
	printf("iCProcTypeInstantiation constructor, proctype_name = %s, instance name = %s\n", 
		proctype_name.c_str(), instance->name.c_str());
}

void iCProcTypeInstantiation::second_pass()
{
	printf("iCProcTypeInstantiation entered second_pass\n");

	if (NULL == instance)
	{
		printf("iCProcTypeInstantiation error - instance is null\n");
		return;
	}
	printf("iCProcTypeInstantiation instance is not null, it's name=%s\n", instance->name.c_str());

	//check whether such proctype exists
	const iCProcType* proctype = program->find_proctype(proctype_name);
	if (NULL == proctype)
	{
		err_msg("undefined process type %s", proctype_name.c_str());
		return;
	}
	printf("iCProcTypeInstantiation found valid proctype %s\n", proctype->name.c_str());

	instance->add_states(proctype->get_states());
	program->add_process(instance); //-1 pointer
}
