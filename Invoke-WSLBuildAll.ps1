Write-Host "::: Configure Linux GCC x64 :::"
wsl cmake --preset linux-gcc-x64

Write-Host "::: Configure Linux Clang x64 :::"
wsl cmake --preset linux-clang-x64

Write-Host "::: Build Linux GCC x64 :::"
wsl cmake --build --preset linux-gcc-x64-debug
wsl cmake --build --preset linux-gcc-x64-profile
wsl cmake --build --preset linux-gcc-x64-release

Write-Host "::: Build Linux Clang x64 :::"
wsl cmake --build --preset linux-clang-x64-debug
wsl cmake --build --preset linux-clang-x64-profile
wsl cmake --build --preset linux-clang-x64-release