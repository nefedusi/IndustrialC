#pragma once

#include "iCNode.h"
#include "iCVariable.h"
#include "iCIdentifier.h"

class iCProcType : public iCDeclaration //todo: iCNode instead?
{
	iCStateList states;
	iCVariablesList var_list; //list of defined variables
	iCIdentifierList ident_list;
public:
	std::string name;
	iCProcType(const std::string& name, const ParserContext& context);
	void add_states(const iCStateList& states);
	void add_variable(std::shared_ptr<iCVariable> var)
	{
		std::cout << "iCProcType: entered add_variable "<<var->name<<std::endl;
		var_list.push_back(var);
	}
	void add_identifier(iCIdentifier* identifier)
	{
		std::cout << "iCProcType: entered add_identifier "<< identifier->name << std::endl;
		ident_list.push_back(identifier);
	}

	//const iCStateList& copy_states() const;
	const iCStateList& get_states() const { printf("iCProctype get_states called\n"); return states; }
	const iCVariablesList& get_variables() const { printf("iCProctype get_variables called\n"); return var_list; }
    virtual void gen_code(CodeGenContext& context); //todo: remove gen_code
};
