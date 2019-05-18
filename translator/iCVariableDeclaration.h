#pragma once

#include "iCNode.h"
class CodeGenContext;
class iCVariable;
class iCScope;

//=================================================================================================
//Variable declaration
//=================================================================================================
class iCVariableDeclaration : public iCDeclaration
{
	iCVariablesList vars;//owns
public:
	iCVariableDeclaration(const ParserContext& context);
	~iCVariableDeclaration() {}
	void set_vars(const iCVariablesList var_list) { vars = var_list; }
	virtual void gen_code(CodeGenContext& context);

#ifdef DEBUG
	virtual const std::string& identify() const { return "iCVariableDeclaration";}
#endif//DEBUG
};