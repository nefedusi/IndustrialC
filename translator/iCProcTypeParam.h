#pragma once

#include "iCIdentifier.h"
#include "CodeGenContext.h"
#include "iCScope.h"

class iCProcTypeParam : public iCIdentifier
{
public:
	std::string value = "";
	iCProcTypeParam(const std::string& name, const iCScope* scope, const ParserContext& context)
		: iCIdentifier(name, scope, context),
		iCNode(context) {}
	//virtual ~iCProcTypeParam() {}
	void gen_code(CodeGenContext& context);
};
