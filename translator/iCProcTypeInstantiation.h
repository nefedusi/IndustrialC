#pragma once

#include "iCNode.h"

class iCProgram;
class iCProcess;
class CodeGenContext;
#include "CodeGenContext.h"

class iCProcTypeInstantiation: public iCNode
{
	iCProgram* program; // does not own
	const std::string proctype_name;
	const std::string instance_name; // does not own
public:
	iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name, const std::string& instance_name);
	void gen_code(CodeGenContext& context); //remove from iCNode?
	void second_pass();
};
