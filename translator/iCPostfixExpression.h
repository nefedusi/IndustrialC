#pragma once

#include "iCNode.h"
class CodeGenContext;

//=================================================================================================
//Postfix expression
//=================================================================================================
class iCPostfixExpression : public iCExpression
{
	iCExpression* expr;
	std::string op;
public:
	iCPostfixExpression(iCExpression* expr, const std::string& op, const ParserContext& context) : expr(expr), op(op), iCNode(context){}
	~iCPostfixExpression();
	virtual void gen_code(CodeGenContext& context);

#ifdef DEBUG
	virtual const std::string& identify() const { return "iCPostfixExpression";}
#endif//DEBUG
};