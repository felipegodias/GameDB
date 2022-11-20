#include "GameDB/Debug/Assert.hpp"

#include <sstream>

#include "GameDB/Debug/Log.hpp"


namespace GDB
{
    void Assert::OnAssertionFailed(const AssertionInfo& assertionInfo)
    {
        const std::optional<Logger*> logger = Log::Global()->GetLogger("Main");
        if (!logger.has_value())
        {
            return;
        }

        std::stringstream stringstream;
        stringstream << "Assertion failed! " << assertionInfo.Message << "\n" << assertionInfo.Expression;

        logger.value()->LogMessage({
            LogType::Critical, assertionInfo.FilePath, assertionInfo.FileLine, assertionInfo.Function,
            stringstream.str()
        });
    }
}
