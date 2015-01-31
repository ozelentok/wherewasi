#include <string>

class Exception {
private:
	std::string _message;
public:
	Exception(const char * message);
	Exception(const std::string & message);
	Exception(const Exception & other);
	virtual ~Exception() = 0;
	std::string what() const;
};

class ParseException : public Exception
{
public:
	ParseException(const char * message);
	ParseException(const std::string & message);
	ParseException(const ParseException & other);
	virtual ~ParseException() = default;
};

class InvalidArgumentException : public Exception
{
public:
	InvalidArgumentException(const char * message);
	InvalidArgumentException(const std::string & message);
	InvalidArgumentException(const InvalidArgumentException & other);
	virtual ~InvalidArgumentException() = default;
};

class EnvironmentException : public Exception
{
public:
	EnvironmentException(const char * message);
	EnvironmentException(const std::string & message);
	EnvironmentException(const EnvironmentException & other);
	virtual ~EnvironmentException() = default;
};

class IOException: public Exception
{
public:
	IOException(const char * message);
	IOException(const std::string & message);
	IOException(const IOException & other);
	virtual ~IOException() = default;
};

