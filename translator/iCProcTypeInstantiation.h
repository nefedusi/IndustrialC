#pragma once

#include "iCNode.h"

class iCProgram;
class iCProcess;
class CodeGenContext;

class iCProcTypeInstantiation: public iCNode
{
	iCProgram* program; // does not own
	const std::string proctype_name;
	const std::string instance_name;
public:
	iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name, std::string instance_name);
	virtual void gen_code(CodeGenContext& context); //remove from iCNode?
};
