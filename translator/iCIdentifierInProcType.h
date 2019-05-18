#pragma once
#include "iCIdentifier.h"

class iCIdentifierInProcType : public iCIdentifier
{
public:
	iCIdentifierInProcType(const std::string& instance_name, const iCScope* scope, const ParserContext& context)
		: iCIdentifier(instance_name, scope, context),
		  iCNode(context) {}
	//virtual ~iCIdentifierInProcType() {}
	virtual void gen_code(CodeGenContext& context)
	{
		std::cout << "iCIdentifierInProcType.gen_code called" << std::endl;
	}
};
