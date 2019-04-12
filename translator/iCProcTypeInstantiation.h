#pragma once

#include "iCNode.h"

class iCProgram;
class iCProcess;
class CodeGenContext;
#include "CodeGenContext.h"

class iCProcTypeInstantiation: public iCNode
{
	const iCProgram* program; // does not own
	const std::string proctype_name;
	iCProcess* instance; // does not own
public:
	iCProcTypeInstantiation(const iCProgram* program, const std::string& proctype_name, iCProcess* instance);
	~iCProcTypeInstantiation() { /*delete *proctype_name;*/ }

	void gen_code(CodeGenContext& context) {}; //remove from iCNode?
	void second_pass();
};
