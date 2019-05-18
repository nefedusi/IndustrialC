#pragma once
#include "iCIdentifier.h"
class iCIdentifierInProcType : public iCIdentifier
{
public:
	iCIdentifierInProcType(const std::string& name, const iCScope* scope, const ParserContext& context)
		: iCIdentifier(name, scope, context) {}
	virtual ~iCIdentifierInProcType();
	virtual void gen_code(CodeGenContext& context);
};

