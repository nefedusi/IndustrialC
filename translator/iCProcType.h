#pragma once

#include "iCNode.h"
#include "iCVariable.h"

class iCProcType : public iCDeclaration //todo: iCNode instead?
{
	iCStateList states;
	iCVariablesList var_list; //list of defined variables
public:
	std::string name;
	iCProcType(const std::string& name, const ParserContext& context);
	void add_states(const iCStateList& states);
	void add_variable(iCVariable* var)
	{
		std::cout << "iCProcType: entered add_variable " << var->name << std::endl;
		var_list.push_back(var);
	}
	//const iCStateList& copy_states() const;
	const iCStateList& get_states() const { printf("iCProctype get_states called\n"); return states; }
	virtual void gen_code(CodeGenContext& context); //todo: remove gen_code
};
