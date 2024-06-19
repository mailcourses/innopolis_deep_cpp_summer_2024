#include <iostream>
#include <cstring>

class BaseLog
{
public:
    virtual void log()
    {
        std::cout << "BaseLog::log" << std::endl;
    }

    static std::string name()
    {
        return std::string{"base_logger"};
    }
protected:
    int counter = 0;
};

class ConsoleLog : public BaseLog
{
public:
    void log()
    {
        std::cout << "ConsoleLog::log" << std::endl;
    }
};

class PrinterLog : public BaseLog
{
public:
    void log()
    {
        std::cout << "PrinterLog::log" << std::endl;
    }

    void clear() const
    {
        //counter++;
    }
};


class FileLog : public BaseLog
{
public:
    void log(int)
    {
        std::cout << "FileLog::log(int)" << std::endl;
    }

    void log() override
    {
        std::cout << "FileLog::log" << std::endl;
    }
};

void write_to_log(BaseLog* log)
{
    log->log();
}

void clear_logger(const PrinterLog& new_logger)
{
    new_logger.clear();
}

int main(int argc, char** argv)
{
    BaseLog* log = nullptr;
    std::cout << "Log name" << BaseLog::name() << std::endl;
    if (strcmp(argv[1], "console") == 0) {
        log = new ConsoleLog();
    }
    else if (strcmp(argv[1], "printer") == 0) {
        log = new PrinterLog();
    }
    write_to_log(log);

    PrinterLog new_logger;
    new_logger.clear();
    clear_logger(new_logger);
}
