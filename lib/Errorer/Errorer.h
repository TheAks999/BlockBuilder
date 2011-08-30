#ifndef ERRORER_H
#define ERRORER_H
#include "../singleton.h"

#ifdef MULTITHREAD
#include "../Mutex/Mutex.h"
#endif

enum ErrorSeverity
{
	ERR_TRIV,
	ERR_MINOR,
	ERR_MAJOR,
	ERR_CRIT
};

class Errorer : public singleton <Errorer>
{
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


	void PushError(std::string Component, std::string Message, int Code, ErrorSeverity Severity);
	void PopError();
	ErrorRep & Top() const;
	ErrorRep Top();

	std::vector<ErrorRep> & DumpLog() const;

	void Clear();

	bool HasError();

	unsigned int NumErrors();

	void FlushErrorsToFile(std::string filename = "errors.log")

	private:



};



#endif
