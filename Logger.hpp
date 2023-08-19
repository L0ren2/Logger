#ifndef LOGGER_HPP_
#define LOGGER_HPP_
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <unordered_map>

class Trace
{
public:
    Trace(const std::string& trace_name)
	: m_name { trace_name }, m_env_var_traces { "TRACES" }
    {}
    bool is_active()
    {
	const char* env { getenv(m_env_var_traces.c_str()) };
	if (!env)
	    return false;
	return (std::string {env}.find(m_name) != std::string::npos);
    }
    std::string to_string() const
    {
	return m_name;
    }
private:
    std::string m_name;
    std::string m_env_var_traces;
};

enum class LVL
{
    ERROR = 1, WARN = 2, DEBUG = 3, INFO = 4
};

const std::unordered_map<LVL, std::string> level_map {
    {LVL::ERROR, "ERROR"},
    {LVL::WARN,  "WARN"},
    {LVL::DEBUG, "DEBUG"},
    {LVL::INFO,  "INFO"}
};

class Logger
{
public:
    Logger(const std::string& trace)
	: m_trace {trace}, m_dev_null {nullptr}
    {
    }
    Logger(const Trace& t)
	: m_trace {t}, m_dev_null {nullptr}
    {
    }
    ~Logger() = default;

    std::ostream& operator<<(const LVL log_level)
    {
	auto level_iterator = level_map.find(log_level);
	if (m_trace.is_active() && level_iterator != level_map.end())
	{
	    std::stringstream ss{};
	    ss << m_trace.to_string() << "\t" << level_iterator->second << ": \t";
	    if (log_level > LVL::WARN)
	    {
		std::cout << ss.str();
		return std::cout;
	    }
	    else
	    {
		std::cerr << ss.str();
		return std::cerr;
	    }
	}
	return m_dev_null;
    }
private:
    Trace m_trace;
    std::ostream m_dev_null;
};
#endif
