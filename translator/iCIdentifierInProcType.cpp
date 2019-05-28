#include "iCIdentifierInProcType.h"
#include "CodeGenContext.h"
#include "iCScope.h"

//todo: what is going on? undefined reference to vtable for iCIdentifierInProcType
/*void iCIdentifierInProcType::gen_code(CodeGenContext& context)
{
	std::cout << "iCIdentifierInProcType.gen_code called, name" << name << std::endl;
	context.set_location(line_num, filename);

	if (NULL != scope && !scope->name.empty())
	{
		context.to_code_fmt("%s_", scope->name.c_str());
	}
	context.to_code_fmt(name.c_str());
}*/
