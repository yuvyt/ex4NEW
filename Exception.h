#ifndef	Exceptions_H_
#define Exceptions_H_
#include <string>
const std::string FILE_NOT_FOUND = "Deck File Error: File not found";
const std::string FILE_FORMAT_ERROR = "Deck File Error: File format error in line ";
const std::string FILE_INVALID_SIZE = "Deck File Error: Deck size is invalid";

class DeckFileNotFound : public std::exception
{
public:
    const char* what()const  noexcept
    {
        return FILE_NOT_FOUND.c_str();
    }
};

class DeckFileFormatError : public std::exception
{
public:
    DeckFileFormatError(int line)
    {
        m_string = FILE_FORMAT_ERROR + std::to_string(line);
    }
    const char* what()const  noexcept
    {
        return m_string.c_str();
    }
private:
    std::string m_string;
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char* what()const  noexcept
    {
        return FILE_INVALID_SIZE.c_str();
    }
};
class InvalidTeamSize : public std::exception
{
};
class InvalidClassName : public std::exception
{
};
class InvalidPlayerName : public std::exception
{
};
class InvalidBuyChoice : public std::exception
{
};
#endif
   