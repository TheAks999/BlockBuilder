#include "errorer.h"
#include <fstream>

/*************************
 * @brief PushError
 * Put an error onto the error queue to be displayed
 * @param Component The component the error is coming from
 * @param Message The error message to be displayed
 * @param Code The numerical code to be listed with this error
 * @param Severity The Severity of the error
 ************************/

void Errorer::PushError(std::string Component, std::string Message, int Code, ErrorSeverity Severity)
{
	#ifdef DEBUG
		std::cout << ErrorRep(Component,Message,Code,Severity) << '\n';
	#endif

	if (single::isInit())
	{
		ErrorRep rep = ErrorRep(Component,Message,Code,Severity);
		single::get()->m_errors.push_back(rep);
		SendToLog(rep);
	}
}

/*************************
 * @brief PopError
 * Remove the top error from the Queue
 ************************/

void Errorer::PopError()
{
	if (single::isInit())
	{
		single::get()->m_errors.erase( single::get()->m_errors.begin() );
	}
}

/*************************
 * @brief SendToLog
 * Append an error to the log file
 * @param error The error that will be placed in the log file
 ************************/

void Errorer::SendToLog(const Errorer::ErrorRep & error)
{
	if (!single::isInit())
		return;

	std::ofstream output;

	output.open(single::get()->m_logfile.c_str(),std::ios_base::out|std::ios_base::app);

	if (!output.is_open())
		return;

	output << error;

	output.close();
}

/*************************
 * @brief Top
 * The top of the error queue
 * @return a copy of the ErrorRep that is on the top of the queue
 ************************/

Errorer::ErrorRep Errorer::Top()
{
	if (single::isInit())
	{
		if (single::get()->m_errors.size())
			return *(single::get()->m_errors.begin());
	}
	return ErrorRep("","",0,ERR_NONE);
}

/*************************
 * @brief DumpLog
 * Dump the error log into a readable structure
 * @return a copy of the ErrorRep vector
 ************************/

std::vector<Errorer::ErrorRep> Errorer::DumpLog()
{
	if (single::isInit())
		return single::get()->m_errors;

	return std::vector<ErrorRep>();
}

/*************************
 * @brief Clear
 * Clear all of the errors from the queue
 ************************/

void Errorer::Clear()
{
	if (single::isInit())
		single::get()->m_errors.clear();
}

/*************************
 * @brief HasError
 * access to if the errorer has an
 * @return true if an error exists on the queue
 ************************/

bool Errorer::HasError()
{
	if (single::isInit())
	return (single::get()->m_errors.size() != 0);
	return false;
}


/*************************
 * @brief NumErrors
 * The number of errors on the queue
 * @return the number of errors on the queue
 ************************/

unsigned int Errorer::NumErrors()
{
	if (single::isInit())
		return single::get()->m_errors.size();

	return 0;
}


/*************************
 * @brief FlushToStream
 * take all of the errors and place them into the stream specified
 * @param output The stream the errors should be output to
 ************************/

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
