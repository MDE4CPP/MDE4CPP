# Build MDE4CPP from Scratch (generate + compile all)

## Requirement: Eclipse with Acceleo

A **full** build (`generateAll` + `compileAll`) needs:

- **Eclipse** (Modeling or similar) with **Acceleo** plugins installed.
- The path to that Eclipse must be set as **`MDE4CPP_ECLIPSE_HOME`** (e.g. `D:\DEV\test2\MDE4CPP\eclipse` or `D:\DEV\test2\MDE4CPP\application\eclipse`).
- Under that path, Gradle expects an Eclipse **`plugins`** folder containing jars such as `com.google.guava_*.jar`, `org.eclipse.uml2.uml_*.jar`, etc.

Without this, the **generator** project (`generator/ecore4CPP`) fails at configuration with:

`MDE4CPP_ECLIPSE_HOME/plugins/com.google.guava_*.jar is not found`

and no code generation or full compile is possible.

## Steps when Eclipse is available

1. **One-time: publish Gradle plugins**
   ```bat
   cd D:\DEV\test2\MDE4CPP\gradlePlugins
   gradlew publishMDE4CPPPluginsToMavenLocal
   cd ..
   ```

2. **Set environment (use cmd, not PowerShell)**  
   Edit `setenv.bat` so that:
   - `MDE4CPP_HOME` is set (or run from `D:\DEV\test2\MDE4CPP` so `%cd%` is correct).
   - `MDE4CPP_ECLIPSE_HOME` points to your Eclipse install (with Acceleo).
   - `CPP_IDE_EXECUTABLE` points to an existing .exe (e.g. `C:\Windows\System32\cmd.exe` if you don’t use the C++ IDE).

   Then run:
   ```bat
   cd D:\DEV\test2\MDE4CPP
   setenv.bat
   ```

3. **Full build**
   ```bat
   application\tools\gradlew.bat buildAll
   ```

   This runs `generateAll` then `compileAll` (and OCL). It can take a long time.

## If you don’t have Eclipse

- You **cannot** run a full from-scratch generate + compile.
- You can still **compile only the PluginAPI** if its CMake build tree already exists and dependencies (Ecore, PluginFramework, etc.) are built:
  ```bat
  cd D:\DEV\test2\MDE4CPP\src\common\MDE4CPP_PluginAPI\src\.cmake\Release
  cmake --build . --target pluginAPI
  ```
- Copy the new `pluginAPI.exe` into `application\bin` if needed.

## Summary

| Goal                    | Eclipse required? | Command / note                          |
|-------------------------|-------------------|-----------------------------------------|
| Full build (gen + comp) | Yes               | `setenv.bat` then `gradlew buildAll`    |
| Compile PluginAPI only | No (if deps built)| CMake build in PluginAPI `.cmake\Release` |
