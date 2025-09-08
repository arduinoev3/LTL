# Сборка проекта

Этот файл описывает, как быстро собрать и протестировать пример из репозитория LTL.

## Требования

- Компилятор C++ (g++ или clang++).
- make не обязателен — сборка выполняется через командную строку компилятора.

## Быстрая сборка

Скомпилируйте пример из `light-template-library`:

```bash
g++ -std=c++11 -Ilight-template-library light-template-library/light-template-library.cpp -o ltl_example
./ltl_example
```

Если желаете собрать с отладочной информацией и предупреждениями:

```bash
g++ -std=c++11 -g -Wall -Wextra -Ilight-template-library light-template-library/light-template-library.cpp -o ltl_example
```

## Интеграция в проект

1. Подключите путь к заголовкам: `-I/path/to/light-template-library`.
2. Так как большая часть реализована в заголовках, не требуется отдельная сборка библиотеки.
