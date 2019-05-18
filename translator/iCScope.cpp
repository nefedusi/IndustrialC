#include "iCScope.h"
#include "iCVariableDeclaration.h"
#include <sstream>

unsigned long iCScope::current_id;

//=================================================================================================
//
//=================================================================================================
iCScope::~iCScope()
{
	std::cout << "iCScope: entered destructor, name=" << name << std::endl;
	if(NULL == prev_scope)
		delete_scope_tree(this);
	std::cout << "iCScope: destructor ended, name=" << name << std::endl;
}

//=================================================================================================
//
//=================================================================================================
void iCScope::delete_scope_tree(iCScope* root_scope)
{
	for(std::vector<iCScope*>::iterator i=root_scope->issues.begin();i!=root_scope->issues.end();i++)
	{
		delete_scope_tree(*i);
		delete *i;
	}
}

//=================================================================================================
//
//=================================================================================================
iCScope::iCScope( const std::string& name ) : prev_scope(NULL), id(current_id++)
{
	this->name = name + "_" + static_cast<std::ostringstream*>( &(std::ostringstream() << std::hex << id) )->str();
}