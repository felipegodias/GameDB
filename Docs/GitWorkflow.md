# Git Workflow

```mermaid
%%{init: { 'gitGraph': {'mainBranchName': 'master'}} }%%
    gitGraph
        commit
        branch a0.1/master
        branch a0.1/task/GDB-1
        commit
        commit
        checkout a0.1/master
        merge a0.1/task/GDB-1
        branch a0.1/task/GDB-2
        commit
        commit
        checkout a0.1/master
        branch a0.1/task/GDB-3
        commit
        commit
        commit
        checkout a0.1/master
        merge a0.1/task/GDB-2
        checkout a0.1/task/GDB-3
        merge a0.1/master
        commit
        checkout a0.1/master
        merge a0.1/task/GDB-3 tag:"v0.1.0"
        checkout master
        merge a0.1/master
        branch a0.2/master
        branch a0.2/task/GDB-4
        commit
        checkout a0.2/master
        merge a0.2/task/GDB-4
        checkout a0.1/master
        branch a0.1/task/GDB-5
        commit
        checkout a0.1/master
        merge a0.1/task/GDB-5 tag:"v0.1.1"
        checkout master
        merge a0.1/master
        checkout a0.2/master
        merge a0.1/master
        branch a0.2/task/GDB-6
        commit
        checkout a0.2/master
        merge a0.2/task/GDB-6 tag:"v0.2.0"
        checkout master
        merge a0.2/master
```
