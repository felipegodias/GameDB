# Project Overview

## Dependency Graph

```mermaid
graph TD;
    subgraph Third Party
        argparse;
        fmt;
        glew;
        glfw3;
        imgui;
    end

    GameDB --> fmt;
    GameDB.Editor --> GameDB;
    GameDB.Editor -.-> glew;
    GameDB.Editor -.-> glfw3;
    GameDB.Editor -.-> imgui;

    GameDB.Editor.Standalone{{GameDB.Editor.Standalone}}
    GameDB.Editor.Standalone -.-> GameDB.Editor;
    GameDB.Editor.Standalone -.-> argparse;
```

### Legend

```mermaid
flowchart LR
    A{{Executable A}}
    B[Library B]
    C[Library C]
    A --->|public|B
    A -..->|private|C
```

## GameDB

## GameDB.Editor

## GameDB.Editor.Standalone

## Third Party

-   argparse <https://github.com/p-ranav/argparse>
-   fmt <https://github.com/fmtlib/fmt>
-   glew <https://github.com/nigels-com/glew>
-   glfw3 <https://github.com/glfw/glfw>
-   imgui <https://github.com/ocornut/imgui>
