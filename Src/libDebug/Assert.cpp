#include "GameDB/Debug/Assert.hpp"

#include "GameDB/Container/StringStream.hpp"
#include "GameDB/Log/Log.hpp"

namespace GDB
{
    void Assert::OnAssertionFailed(const AssertionInfo& assertionInfo)
    {
        StringStream stringstream;
        stringstream << "Assertion failed! " << assertionInfo.message << "\n" << assertionInfo.expression;
        Log::Global()->LogMessage("Main",
                                  LogType::Critical, assertionInfo.filePath, assertionInfo.fileLine,
                                  assertionInfo.function, stringstream.str()
        );
    }
}
