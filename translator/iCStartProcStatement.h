#pragma once

#include "iCNode.h"
class CodeGenContext;
class ParserContext;
class iCProgram;

//=================================================================================================
//IndustrialC "start process <started_proc_name>;" statement
//=================================================================================================
class iCStartProcStatement : public iCStatement
{
	bool in_isr;
	bool proc_is_proctype_param = false;
	const iCProcTypeParam *proctype_param = NULL; //where to take value from if started_proc_name is proctype param
public:
	std::string started_proc_name; 
	const iCProgram* program; // does not own
	const iCProcess* started_proc; // does not own
	iCStartProcStatement(const std::string& proc_name, const ParserContext& context);
	virtual ~iCStartProcStatement(){}
	virtual void gen_code(CodeGenContext& context);
	virtual void second_pass();

#ifdef DEBUG
	virtual const std::string& identify() const { return "iCStartProcStatement";}
#endif//DEBUG
};
