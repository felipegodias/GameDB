#include "GameDB/Debug/Assert.hpp"

#include <fmt/format.h>

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

        const std::string message = fmt::format("Assertion failed! {0}\n{1}", assertionInfo.Message,
                                                assertionInfo.Expression);
        logger.value()->LogMessage({
            LogType::Critical, assertionInfo.FilePath, assertionInfo.FileLine, assertionInfo.Function,
            message
        });
    }
}
