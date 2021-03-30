#ifndef OCLLOG_H
#define OCLLOG_H

#include <string>

namespace Utilities {

enum OclSeverity {
    INFO = 0,
    WARNING = 1,
    ERROR = 2
};

class OclLog
{
public:
    OclLog(OclSeverity severity, const std::string& msg);

    /* SETTERS */
    /* GETTERS */
    const std::string& getMsg();

private:
    static const std::string SEVERITIES[];

    OclSeverity m_severity;
    std::string m_msg;
};
}
#endif // OCLLOG_H
