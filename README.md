# EEZ Studio LVGL + Sqlite3

使用 Conan 管理包文件，添加了 Sqlite3, 交叉编译配置 `profiles/t113`

## 下载依赖

```bash
conan install . --build missing -pr:b=default -pr:h=./profiles/t113
```

## 编译

```bash
cd build
source Release/generators/conanbuild.sh
cmake .. -DCMAKE_TOOLCHAIN_FILE=Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## 查看编译结果

```bash
file ../bin/test
```
```bash
bin/test: ELF 32-bit LSB pie executable, ARM, EABI5 version 1 (GNU/Linux), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, for GNU/Linux 6.6.0, not stripped
```