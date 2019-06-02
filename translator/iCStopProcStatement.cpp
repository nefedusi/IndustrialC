#include "iCStopProcStatement.h"
#include "CodeGenContext.h"
#include "ParserContext.h"
#include "iCProgram.h"

//=================================================================================================
//
//=================================================================================================
void iCStopProcStatement::second_pass()
{
	//if it's not stopping self process from proctype then check that process has been defined
	if(!proc_name.empty() && !program->proc_defined(proc_name) && !program->proctype_instance_defined(proc_name))
	{
		err_msg("undefined process %s", proc_name.c_str());
	}
}

//=================================================================================================
//Code generator
//=================================================================================================
void iCStopProcStatement::gen_code(CodeGenContext& context)
{
	context.set_location(line_num, filename);
	context.indent();
	if (stop_self_in_proctype) //if it's stopping self process from proctype when process instance name is unknown
	{
		context.to_code_fmt("%s(%s);", C_STOPPROC_MACRO, context.proctype_instantiation->name.c_str());
	}
	else
	{
		context.to_code_fmt("%s(%s);", C_STOPPROC_MACRO, proc_name.c_str());
	}
	/*if(in_isr)
		context.to_code_fmt("//in ISR");*/
	context.to_code_fmt("\n");
}

//=================================================================================================
//for common case
//=================================================================================================
iCStopProcStatement::iCStopProcStatement( const std::string& proc_name, const ParserContext& context )
	:	proc_name(proc_name),
		program(context.get_program()),
		iCNode(context),
		in_isr(context.in_isr())//,
		//proc(NULL)
{
	line_num = context.line();
}

//for stopping self in proctype when instance name is unknown
iCStopProcStatement::iCStopProcStatement(const ParserContext& context)
	: program(context.get_program()),
	iCNode(context),
	in_isr(context.in_isr())
{
	stop_self_in_proctype = true;
	line_num = context.line();
}
