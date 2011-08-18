#include "loaderbase.h"


std::string LoaderBase::ErrorDesc()
{
	return m_errorStrings[0];
}

unsigned int LoaderBase::ErrorCode()
{
	return m_errorCodes[0];
}

void LoaderBase::nextError()
{
	if (m_errorStrings.size() > 1)
	{
		m_errorStrings.pop_back();
		m_errorCodes.pop_back();
	}
}

void LoaderBase::clearErrors()
{
	while (m_errorStrings.size() > 1)
	{
		m_errorStrings.pop_back();
		m_errorCodes.pop_back();
	}

}

void LoaderBase::flushErrorsTo(std::iostream *stream)
{
	while (m_errorStrings.size() > 1)
	{
		(*stream) << "Error(" << m_errorCodes.back() << "): " << m_errorStrings.back() << '\n';

		m_errorStrings.pop_back();
		m_errorCodes.pop_back();
	}
}

void LoaderBase::pushError(const unsigned int & errCode, const std::string & errString)
{
	m_errorCodes.push_back(errCode);
	m_errorStrings.push_back(errString);
}
