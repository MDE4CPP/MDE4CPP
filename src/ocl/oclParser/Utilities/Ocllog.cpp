#include "Ocllog.h"

using namespace Utilities;

const std::string OclLog::SEVERITIES[] = {
    "INFO",
    "WARNING",
    "ERROR"
};

OclLog::OclLog(OclSeverity severity, const std::string& msg) :
    m_severity(severity), m_msg(msg) { }

const std::string& OclLog::getMsg()
{
    m_msg = SEVERITIES[m_severity] + " : " + m_msg;
    return m_msg;
}
