Write-Host "::: Configure Windows MSVC x64 :::"
cmake --preset windows-msvc-x64

Write-Host "::: Configure Windows Clang x64 :::"
cmake --preset windows-clang-x64

Write-Host "::: Build Windows MSVC x64 :::"
cmake --build --preset windows-msvc-x64-debug
cmake --build --preset windows-msvc-x64-profile
cmake --build --preset windows-msvc-x64-release

Write-Host "::: Build Windows Clang x64 :::"
cmake --build --preset windows-clang-x64-debug
cmake --build --preset windows-clang-x64-profile
cmake --build --preset windows-clang-x64-release