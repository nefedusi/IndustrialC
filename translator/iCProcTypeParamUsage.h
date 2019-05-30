#pragma once

#include "iCIdentifier.h"
#include "CodeGenContext.h"
#include "iCScope.h"
#include "iCProcTypeParam.h"

class iCProcTypeParamUsage : public iCIdentifier
{
public:
	iCProcTypeParam* param; //doesn't own
	iCProcTypeParamUsage(const std::string& name, iCProcTypeParam* param,
		const iCScope* scope, const ParserContext& context)
		: iCIdentifier(name, scope, context),
		iCNode(context)
	{
		this->param = param;
	}
	//virtual ~iCProcTypeParamUsage() {}
	void gen_code(CodeGenContext& context);
};


