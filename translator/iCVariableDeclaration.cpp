#include "iCVariableDeclaration.h"
#include "iCVariable.h"
#include "CodeGenContext.h"
#include "iCScope.h"

//=================================================================================================
//Code generator
//=================================================================================================
void iCVariableDeclaration::gen_code( CodeGenContext& context )
{
	for(iCVariablesList::iterator i=vars.begin(); i!=vars.end(); i++)
	{
		std::shared_ptr<iCVariable> var = *i;
		if(nullptr != var)
			var->gen_code(context);
	}
}

//=================================================================================================
//
//=================================================================================================
iCVariableDeclaration::iCVariableDeclaration(const ParserContext& context)
	: iCNode(context)
{

}
