#pragma once

#include "iCNode.h"
class CodeGenContext;

//=================================================================================================
//Integer constant
//=================================================================================================
class iCLogicConst : public iCExpression
{
public:
	bool val;
	iCLogicConst(bool val, const ParserContext& context);
	virtual void gen_code(CodeGenContext& context);

#ifdef DEBUG
	virtual const std::string& identify() const { return "iCLogicConst";}
#endif//DEBUG
};
