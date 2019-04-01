#pragma once

#include "iCNode.h"
class CodeGenContext;
class ParserContext;
class iCState;

class iCProcType : public iCDeclaration
{
	std::string name;
	StateList states;
public:
	iCProcType(const std::string& name, const ParserContext& context);
	virtual ~iCProcType();
	const std::string& get_name() { return this->name; }
	void add_states(const StateList& states);
	StateList* get_states();
    virtual void gen_code(CodeGenContext& context);
};
