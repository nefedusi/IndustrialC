#pragma once

#include "iCNode.h"
class CodeGenContext;

//=================================================================================================
//Expression statement
//=================================================================================================
class iCExpressionStatement : public iCStatement
{
public:
	iCExpression* expr; // Owns
	iCExpressionStatement(iCExpression* expr, const ParserContext& context);
	virtual ~iCExpressionStatement();
	virtual void gen_code(CodeGenContext& context);

#ifdef DEBUG
	virtual const std::string& identify() const { return "iCExpressionStatement";}
#endif//DEBUG
};