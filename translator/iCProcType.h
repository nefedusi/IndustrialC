#pragma once

#include "iCNode.h"

class iCProcType : public iCDeclaration
{
	iCStateList states;
public:
    std::string name;
    iCProcType(const std::string& name, const ParserContext& context);
	void add_states(const iCStateList& states);
	//const iCStateList& copy_states() const;
	const iCStateList& get_states() const { printf("iCProctype get_states called\n"); return states; }
    virtual void gen_code(CodeGenContext& context); //todo: remove gen_code
};
