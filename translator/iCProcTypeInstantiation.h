#pragma once

#include "iCNode.h"

class iCProgram;
class iCProcess;

class iCProcTypeInstantiation//: public iCNode
{
	std::string proctype_name;
	const iCProgram* program; // does not own
	const iCProcess* instance; // does not own
public:
	//iCProcTypeInstantiation() {}
	//iCProcTypeInstantiation(const std::string& proctype_name, const iCProcess* instance);
	//virtual void second_pass();
};
