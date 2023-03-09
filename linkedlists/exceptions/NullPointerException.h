#include <iostream>

#ifndef NULL_PTR_EXCEPTION
#define NULL_PTR_EXCEPTION

class NullPointerException : public std::exception
{
private:
    std::string message;

public:
    NullPointerException();
    NullPointerException(std::string msg);
    std::string what();
};

NullPointerException::NullPointerException() {
    this->message = "\n\n--------------------------------\ntrying to call methode on a null pointer\n--------------------------------\n";
}

NullPointerException::NullPointerException(std::string msg) : message(msg) {}

std::string NullPointerException::what()
{
    return message;
}

#endif