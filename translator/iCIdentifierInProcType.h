#pragma once

#include "iCIdentifier.h"
#include "CodeGenContext.h"
#include "iCScope.h"

class iCIdentifierInProcType : public iCIdentifier
{
public:
	iCIdentifierInProcType(const std::string& instance_name, const iCScope* scope, const ParserContext& context)
		: iCIdentifier(instance_name, scope, context),
		  iCNode(context) {}
	//virtual ~iCIdentifierInProcType() {}
	virtual void gen_code(CodeGenContext& context)
	{
		std::cout << "iCIdentifierInProcType.gen_code called, name=" << name << std::endl;
		context.set_location(line_num, filename);

		if (NULL != context.proctype_instantiation)
		{
			std::cout << "iCIdentifierInProcType.gen_code proctype name=" << context.proctype_instantiation->name << std::endl;
			context.to_code_fmt("%s_", context.proctype_instantiation->name.c_str());
		}
		context.to_code_fmt(name.c_str());
	}
};
