#ifndef ERRORER_H
#define ERRORER_H
#include "../singleton.h"

#ifdef MULTITHREAD
#include "../Mutex/Mutex.h"
#endif

enum ErrorSeverity
{
	ERR_NONE,
	ERR_TRIV,
	ERR_MINOR,
	ERR_MAJOR,
	ERR_CRIT
};

class Errorer : public singleton <Errorer>
{
	typedef singleton <Errorer> single;
	public:
	struct ErrorRep
	{
		std::string Component, Message;
		int Code;
		ErrorSeverity Severity;
		friend bool operator<(const ErrorRep & r1, const ErrorRep & r2){ return (r1.Severity < r2.Severity); }
		friend bool operator<=(const ErrorRep & r1, const ErrorRep & r2){ return (r1.Severity <= r2.Severity); }
		friend bool operator>(const ErrorRep & r1, const ErrorRep & r2){ return (r1.Severity > r2.Severity); }
		friend bool operator>=(const ErrorRep & r1, const ErrorRep & r2){ return (r1.Severity >= r2.Severity); }

	};


	static void PushError(std::string Component, std::string Message, int Code, ErrorSeverity Severity);
	static void PopError();
	static ErrorRep & Top() const;
	static ErrorRep Top();

	static std::vector<ErrorRep> & DumpLog() const;

	static void Clear();

	static bool HasError();

	static unsigned int NumErrors();

	static void FlushErrorsToStream(ostream * output);

	private:

	std::vector<ErrorRep> m_errors;

};



#endif
