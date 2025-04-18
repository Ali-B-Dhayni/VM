/*
*error.hpp, error header file, contains the declaration
*of the Error class.
*The global Error class, referenced by every System Module,
*Implements all error types encountered by any module.
*
* By Ali B. Dhayni
*/
#pragma once

#define SYS_SUCCESS 1;
#define SYS_FAILURE 0;

enum 
ErrType
{
	ERR_NONE,
	ERR_MEMORY_ALLOCATION_FAILURE,
	ERR_MEMROY_REFERENCING_FAILURE,
	ERR_UNDEFINED_ACTION,
};

class
Error
{
private:
	ErrType err_type;
	std::string err_message;

public:
	Error(ErrType _err_type, std::string _err_message)
	{
		this->err_type = _err_type;
		this->err_message = _err_message;
	}
	Error(void)
	{
		this->err_type = ERR_NONE;
		this->err_message = "Success";
	}
};
