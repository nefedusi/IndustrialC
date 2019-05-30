#pragma once

#include "iCIdentifier.h"
#include "CodeGenContext.h"
#include "iCScope.h"

class iCIdentifierInProcType : public iCIdentifier
{
public:
	iCIdentifierInProcType(const std::string& name, const iCScope* scope, const ParserContext& context)
		: iCIdentifier(name, scope, context),
		  iCNode(context) {}
	//virtual ~iCIdentifierInProcType() {}
	void gen_code(CodeGenContext& context);
	/*{
		std::cout << "iCIdentifierInProcType.gen_code called, name=" << name << std::endl;
		//todo: remove?
		context.set_location(line_num, filename);

		//todo: return if no proctype_instantiation, don't generate code
		if (NULL != context.proctype_instantiation)
		{
			std::cout << "iCIdentifierInProcType.gen_code proctype name=" << context.proctype_instantiation->name << std::endl;
			context.to_code_fmt("%s_", context.proctype_instantiation->name.c_str());
		}
		context.to_code_fmt(name.c_str());
	}*/
};
