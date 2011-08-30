#include "errorer.h"

void Errorer::PushError(std::string Component, std::string Message, int Code, ErrorSeverity Severity)
{
	if (single::isInit())
	{
		Errorer::get()->m_errors.push_back(ErrorRep(Component,Message,Code,Severity));
	}
}

void PopError()
{
	if (single::isInit())
	{
		Errorer::get()->m_errors.push_back(ErrorRep(Component,Message,Code,Severity));
	}
}

ErrorRep & Top() const;
ErrorRep Top();

std::vector<ErrorRep> & DumpLog() const;

void Clear();

bool HasError();

unsigned int NumErrors();

void FlushErrorsToStream(ostream * output);
