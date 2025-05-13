# Лабораторная работа 3

## Зависимости

Компилятор, совместимый со стандартом C++11; CMake

```bash
pacman -Syu gcc cmake
```

## Компиляция

```bash
mkdir -p build
cd build
cmake ..
make
```

## Тестирование

```bash
cd build
ctest
```

## Пользовательский интерфейс

```bash
cd build
userInterface
```

![МИФИ](./contrib/mephi.png)
