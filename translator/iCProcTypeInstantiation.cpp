#include "iCProcTypeInstantiation.h"
#include "iCProgram.h"
#include "iCProcType.h"
#include "iCProcess.h"

iCProcTypeInstantiation::iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name, 
	iCProcess* instance) : program(program), proctype_name(proctype_name), instance(instance)
{
	if (program != NULL)
	{
		printf("program is not null\n");
	}
	printf("proctype_name = %s\n", proctype_name.c_str());
	printf("instance name = %s\n", instance->name.c_str());
}

void iCProcTypeInstantiation::second_pass()
{
	printf("iCProcTypeInstantiation entered second_pass\n");

	if (instance == NULL)
	{
		printf("iCProcTypeInstantiation error - instance is null\n");
		return;
	}
	printf("iCProcTypeInstantiation instance is not null\n");

	//check whether such proctype exists
	const iCProcType* proctype = program->find_proctype(proctype_name);
	if (NULL == proctype)
	{
		err_msg("undefined process type %s", proctype_name.c_str());
		return;
	}
	printf("found valid proctype %s\n", proctype->name.c_str());

	//instance->add_states(proctype->get_states());
	program->add_process(instance); //-1 pointer
}
