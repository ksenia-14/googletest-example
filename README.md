# GoogleTest
Подключение и пример использования GoogleTest для тестирования нескольких модулей.
## Необходимые инструменты
* C/C++ Compiler
* CMake

## Структура проекта
```
googletest_example
├── build
├── modules
│   ├── CMakeLists.txt
│   └── module_a
│   │   ├── test_fun_a.c
│   │   └── test_fun_a.h
│   └── module_b
│   │   ├── test_fun_b.c
│   │   └── test_fun_b.h
├── tests
│   ├── test_a.cc
│   └── test_b.cc
├── MakeLists.txt
├── main_test.cc
```

## Подключение Google test
### Подключение библиотеки
```
# root CMakeLists.txt

cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
```
В приведенном примере — `03597a01ee50ed33e9dfd640b249b4be3799d395` - хеш фиксации Git используемой версии GoogleTest (рекомендуется обновлять до последней версии).

### Включение тестов
Дополним файл CMakeLists.txt
```
# root CMakeLists.txt

...

enable_testing()

add_subdirectory(modules)

add_executable(
  main_test
  main_test.cc
  tests/test_a.cc
  tests/test_b.cc
)

target_link_libraries(
  main_test
  PUBLIC
  modules
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main_test)
```

## Build and run
<pre>
<b>googletest_example>cmake -S . -B build -G "MinGW Makefiles" -Wno-dev </b>
-- The C compiler identification is GNU 13.2.0
-- The CXX compiler identification is GNU 13.2.0
...
-- Build files have been written to: ...\googletest_example/build

<b>googletest_example>cmake --build build</b>
[  6%] Building C object modules/CMakeFiles/modules.dir/module_a/test_fun_a.c.obj
...
[100%] Built target gmock_main

<b>googletest_example>cd build && ctest</b>
Test project C:/Users/User/Desktop/Projects/googletest_example/build
    Start 1: TestGroupNameB.Subtest_1
1/4 Test #1: TestGroupNameB.Subtest_1 .........***Failed    0.02 sec
    Start 2: TestGroupNameB.Subtest_2
2/4 Test #2: TestGroupNameB.Subtest_2 .........***Failed    0.03 sec
    Start 3: TestGroupNameA.Subtest_1
3/4 Test #3: TestGroupNameA.Subtest_1 .........   Passed    0.02 sec
    Start 4: TestGroupNameA.Subtest_2
4/4 Test #4: TestGroupNameA.Subtest_2 .........   Passed    0.02 sec

50% tests passed, 2 tests failed out of 4

Total Test time (real) =   0.11 sec

The following tests FAILED:
          1 - TestGroupNameB.Subtest_1 (Failed)
          2 - TestGroupNameB.Subtest_2 (Failed)
Errors while running CTest
Output from these tests are in: C:/Users/User/Desktop/Projects/googletest_example/build/Testing/Temporary/LastTest.log
Use "--rerun-failed --output-on-failure" to re-run the failed cases verbosely.
</pre>

## Возможные ошибки
- Ошибка
```
CMake Error at C:/Espressif/tools/cmake/3.24.0/share/cmake-3.24/Modules/GoogleTestAddTests.cmake:112 (message): 
Error running test executable. Path: 'D:/Projects/test/_build/example/example.exe' 
Result: Exit code 0xc0000139
```
- Решение: 
поднять вверх пути в Path
```
C:\msys64
C:\msys64\ucrt64\bin
C:\Program Files\CMake\bin
```


## Источники
1. Настройка рабочей среды. Установка библиотеки GoogleTest - https://cpp-python-nsu.inp.nsk.su/textbook/sec2/ch7
2. Пошаговый пример сборки и подключения к GMock из проекта CMake с нуля. Локальная установка GoogleTest - https://exchangetuts.com/cmake-is-unable-to-find-packages-of-gmock-1640607244111525
3. Quickstart: Building with CMake - https://google.github.io/googletest/quickstart-cmake.html
4. Пример проекта. Integrating Google Test Into CMake Projects - https://matgomes.com/integrate-google-test-into-cmake/

