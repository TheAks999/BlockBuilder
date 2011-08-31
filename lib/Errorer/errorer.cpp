#include "errorer.h"

void Errorer::PushError(std::string Component, std::string Message, int Code, ErrorSeverity Severity)
{
	if (single::isInit())
	{
		single::get()->m_errors.push_back(ErrorRep(Component,Message,Code,Severity));
	}
}

void Errorer::PopError()
{
	if (single::isInit())
	{
		single::get()->m_errors.erase( single::get()->m_errors.begin() );
	}
}


Errorer::ErrorRep Errorer::Top()
{
	if (single::isInit())
		return *(single::get()->m_errors.begin());

	return ErrorRep("","",0,ERR_NONE);
}

std::vector<Errorer::ErrorRep> Errorer::DumpLog()
{
	if (single::isInit())
		return single::get()->m_errors;

	return std::vector<ErrorRep>();
}

void Errorer::Clear()
{
	if (single::isInit())
		single::get()->m_errors.clear();
}

bool Errorer::HasError()
{
	if (single::isInit())
	return (single::get()->m_errors.size() != 0);
	return false;
}

unsigned int Errorer::NumErrors()
{
	if (single::isInit())
		return single::get()->m_errors.size();

	return 0;
}

void Errorer::FlushErrorsToStream(std::ostream * output)
{
	if (!single::isInit())
	{
		*output << ErrorRep("","",0,ERR_NONE);
		return;
	}

	if (single::get()->m_errors.size() == 0)
	{
		*output << ErrorRep("","",0,ERR_NONE);
		return ;
	}

	while (single::get()->m_errors.size())
	{
		//print
		*output << single::get()->m_errors[0] << '\n';
		//erase
		single::get()->m_errors.erase(single::get()->m_errors.begin());
	}
}
