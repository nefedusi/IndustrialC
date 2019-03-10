#pragma once

#include "iCNode.h"

class iCProcType : public iCDeclaration
{
public:
    std::string name;
    iCProcType(const std::string& name, const ParserContext& context);
    virtual void gen_code(CodeGenContext& context);
};