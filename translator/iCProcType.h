#pragma once

#include "iCNode.h"

class iCProcType : public iCDeclaration
{
	StateList states;
public:
    std::string name;
    iCProcType(const std::string& name, const ParserContext& context);
	const StateList& states get_states();
    virtual void gen_code(CodeGenContext& context);
};
