#include "GameDB/Debug/Assert.hpp"

#include <sstream>

#include "GameDB/Debug/Log.hpp"


namespace GDB
{
    void Assert::OnAssertionFailed(const AssertionInfo& assertionInfo)
    {
        std::stringstream stringstream;
        stringstream << "Assertion failed! " << assertionInfo.message << "\n" << assertionInfo.expression;
        Log::Global()->LogMessage("Main",
                                  LogType::Critical, assertionInfo.filePath, assertionInfo.fileLine,
                                  assertionInfo.function, stringstream.str()
        );
    }
}
