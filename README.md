<p align="center">
    <a href="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/windows_msvc_build.yml">
        <img src="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/windows_msvc_build.yml/badge.svg"/>
    </a>
    <a href="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/windows_clang_build.yml">
        <img src="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/windows_clang_build.yml/badge.svg"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/linux_gcc_build.yml">
        <img src="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/linux_gcc_build.yml/badge.svg"/>
    </a>
    <a href="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/linux_clang_build.yml">
        <img src="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/linux_clang_build.yml/badge.svg"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/mac_clang_build.yml">
        <img src="https://github.com/Pluto-Games/GameDB.Client/actions/workflows/mac_clang_build.yml/badge.svg"/>
    </a>
</p>

<div align="center">
    <h1 align="center">GameDB</h1>
</div>

## Requirements

All third party libraries will be installed automatically via <a href="https://github.com/microsoft/vcpkg">vcpkg</a>.

### Supported Toolchains

| Compiler      | Generator | Standard Library | C++ Standard | Test Environment   |
| :------------ | :-------- | :--------------- | :----------- | :----------------- |
| GCC >= 7.0    | Ninja     | libstdc++        | C++17        | Ubuntu 20.04       |
| Clang >= 6.0  | Ninja     | libc++           | C++17        | Xcode 13.4.1       |
| MSVC >= 19.14 | Ninja     | Microsoft STL    | C++17        | Visual Studio 2022 |

## How to Build

```bash
# --recurse-submodules is needed due to vcpkg dependency!
git clone --recurse-submodules git@github.com:Pluto-Games/GameDB.Client.git
```

Use one of the following presets along with CMake.

### Presets

-   Windows
    -   windows-msvc-debug
    -   windows-msvc-release
    -   windows-clang-debug
    -   windows-clang-release

-   Linux
    -   linux-gcc-debug
    -   linux-gcc-release
    -   linux-clang-debug
    -   linux-clang-release

-   MacOS
    -   mac-clang-debug
    -   mac-clang-release

```bash
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug --target install
```
