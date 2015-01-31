#include "Exception.hpp"

Exception::Exception(const char * message)
	:_message(message)
{}

Exception::Exception(const std::string & message)
	:_message(message)
{}

Exception::Exception(const Exception & other)
	:_message(other._message)
{}

Exception::~Exception()
{}

std::string Exception::what() const
{
	return _message;
}

ParseException::ParseException(const char * message)
	:Exception(message)
{}
ParseException::ParseException(const std::string & message)
	:Exception(message)
{}
ParseException::ParseException(const ParseException & other)
	:Exception(other)
{}

InvalidArgumentException::InvalidArgumentException(const char * message)
	:Exception(message)
{}
InvalidArgumentException::InvalidArgumentException(const std::string & message)
	:Exception(message)
{}
InvalidArgumentException::InvalidArgumentException(const InvalidArgumentException & other)
	:Exception(other)
{}

EnvironmentException::EnvironmentException(const char * message)
	:Exception(message)
{}
EnvironmentException::EnvironmentException(const std::string & message)
	:Exception(message)
{}
EnvironmentException::EnvironmentException(const EnvironmentException & other)
	:Exception(other)
{}

IOException::IOException(const char * message)
	:Exception(message)
{}
IOException::IOException(const std::string & message)
	:Exception(message)
{}
IOException::IOException(const IOException & other)
	:Exception(other)
{}
