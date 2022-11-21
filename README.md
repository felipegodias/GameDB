<p align="center">
    <a href="https://github.com/felipegodias/GameDB.Client/graphs/contributors">
        <img src="https://img.shields.io/github/contributors/felipegodias/GameDB.Client.svg"/>
    </a>
    <a href="https://github.com/felipegodias/GameDB.Client/network/members">
        <img src="https://img.shields.io/github/forks/felipegodias/GameDB.Client.svg"/>
    </a>
    <a href="https://github.com/felipegodias/GameDB.Client/stargazers">
        <img src="https://img.shields.io/github/stars/felipegodias/GameDB.Client.svg"/>
    </a>
    <a href="https://github.com/felipegodias/GameDB.Client/issues">
        <img src="https://img.shields.io/github/issues/felipegodias/GameDB.Client.svg"/>
    </a>
    <a href="https://github.com/felipegodias/GameDB.Client/blob/master/LICENSE">
        <img src="https://img.shields.io/github/license/felipegodias/GameDB.Client.svg"/>
    </a>
    <a href="https://www.linkedin.com/in/felipegodias">
        <img src="https://img.shields.io/badge/-LinkedIn-black.svg?logo=linkedin&colorB=1182c3"/>
    </a>
</p>

<p align="center">
    <a href="https://www.codacy.com/gh/felipegodias/GameDB.Client/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=felipegodias/GameDB.Client&amp;utm_campaign=Badge_Grade">
    <img src="https://app.codacy.com/project/badge/Grade/c96c6820f01241c794a95c7430a6fef0"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/felipegodias/GameDB.Client/actions/workflows/windows_msvc_build.yml">
        <img src="https://github.com/felipegodias/GameDB.Client/actions/workflows/windows_msvc_build.yml/badge.svg"/>
    </a>
    <a href="https://github.com/felipegodias/GameDB.Client/actions/workflows/windows_clang_build.yml">
        <img src="https://github.com/felipegodias/GameDB.Client/actions/workflows/windows_clang_build.yml/badge.svg"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/felipegodias/GameDB.Client/actions/workflows/linux_gcc_build.yml">
        <img src="https://github.com/felipegodias/GameDB.Client/actions/workflows/linux_gcc_build.yml/badge.svg"/>
    </a>
    <a href="https://github.com/felipegodias/GameDB.Client/actions/workflows/linux_clang_build.yml">
        <img src="https://github.com/felipegodias/GameDB.Client/actions/workflows/linux_clang_build.yml/badge.svg"/>
    </a>
</p>

<p align="center">
    <a href="https://github.com/felipegodias/GameDB.Client/actions/workflows/mac_clang_build.yml">
        <img src="https://github.com/felipegodias/GameDB.Client/actions/workflows/mac_clang_build.yml/badge.svg"/>
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

### Configure Presets

-   Windows
    -   windows-msvc-x64
    -   windows-clang-x64

-   Linux
    -   linux-gcc-x64
    -   linux-clang-x64

-   MacOS
    -   mac-apple-clang-x64

### Build Presets

-   Windows
    -   windows-msvc-x64-debug
    -   windows-msvc-x64-profile
    -   windows-msvc-x64-release
    -   windows-clang-x64-debug
    -   windows-clang-x64-profile
    -   windows-clang-x64-release

-   Linux
    -   linux-gcc-x64-debug
    -   linux-gcc-x64-profile
    -   linux-gcc-x64-release
    -   linux-clang-x64-debug
    -   linux-clang-x64-profile
    -   linux-clang-x64-release

-   MacOS
    -   mac-apple-clang-x64-debug",
    -   mac-apple-clang-x64-profile",
    -   mac-apple-clang-x64-release",

```bash
cmake --preset windows-msvc-x64
cmake --build --preset windows-msvc-x64-debug
```

<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE` for more information.

<!-- CONTACT -->

## Contact

Felipe Dias - [@felipegodias](https://twitter.com/felipegodias) - felipe.g.o.dias@outlook.com

Project Link: <https://github.com/felipegodias/GameDB.Client>