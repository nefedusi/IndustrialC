#include "iCIdentifierInProcType.h"
#include "CodeGenContext.h"

void iCIdentifierInProcType::gen_code(CodeGenContext& context)
{
	std::cout << "iCIdentifierInProcType.gen_code called, name=" << name << std::endl;
	context.set_location(line_num, filename); //todo: remove?

	//todo: return if no proctype_instantiation, don't generate code
	if (NULL != context.proctype_instantiation)
	{
		std::cout << "iCIdentifierInProcType.gen_code proctype name=" << context.proctype_instantiation->name << std::endl;
		context.to_code_fmt("%s_", context.proctype_instantiation->name.c_str());
	}
	context.to_code_fmt(name.c_str());
}
