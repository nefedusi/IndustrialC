#include "iCProcTypeParam.h"

void iCProcTypeParam::gen_code(CodeGenContext& context)
{
	std::cout << "iCProcTypeParam.gen_code proctype=" << context.proctype_instantiation->name << 
		", value="<< value << std::endl;
	context.to_code_fmt(value.c_str());
}
