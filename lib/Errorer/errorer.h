#ifndef ERRORER_H
#define ERRORER_H
#include "../singleton.h"
#include <string>
#include <vector>
#include <iostream>

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

class Errorer : public Singleton <Errorer>
{
	typedef Singleton <Errorer> single;
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
		ErrorRep():Code(0),Severity(ERR_NONE){}
		ErrorRep(std::string component, std::string message, int code, ErrorSeverity severity):
			Component(component),Message(message),Code(code),Severity(severity){}

		friend std::ostream & operator<<(std::ostream & o, const ErrorRep & e )
		{
			o << e.Component << " ";
			switch (e.Severity)
			{
				case ERR_NONE:
				o << "No Error";
				return o;
				case ERR_TRIV:
				o << "Trivial";
				break;
				case ERR_MINOR:
				o << "Minor";
				break;
				case ERR_MAJOR:
				o << "Major";
				break;
				case ERR_CRIT:
				o << "Critical";
			}
			 o << " Error Code(" << e.Code << "): " << e.Message;
			 return o;
		}
	};


	static void PushError(std::string Component, std::string Message, int Code, ErrorSeverity Severity);
	static void PopError();
	static ErrorRep Top();

	static std::vector<ErrorRep> DumpLog();

	static void Clear();

	static bool HasError();

	static unsigned int NumErrors();

	static void FlushErrorsToStream(std::ostream * output);

	static std::string LogFilename(){ if (single::isInit()){return single::get()->m_logfile;}
									else{return "NoFile";} }
	static void LogFilename(const std::string & filename){ if (single::isInit()) single::get()->m_logfile = filename; }

	private:

    static void SendToLog(const ErrorRep & error);

	std::vector<ErrorRep> m_errors;
	std::string m_logfile;

};



#endif
