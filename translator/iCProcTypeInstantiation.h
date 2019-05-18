#pragma once

#include "iCNode.h"
#include "iCProcess.h"

class iCProgram;
class CodeGenContext;

class iCProcTypeInstantiation: public iCProcess
{
	iCProgram *program; // does not own
	const iCProcType *proctype; // does not own
	const std::string proctype_name;
public:
	iCProcTypeInstantiation(iCProgram* program, const std::string& proctype_name, const std::string& instance_name, 
		const ParserContext& context);
	virtual ~iCProcTypeInstantiation() {}
	void second_pass();
	void gen_code(CodeGenContext& context); //todo: remove from iCNode?
};
