# Структура проекта

Короткое описание структуры репозитория LTL и местоположения ключевых файлов.

```
LTL/
├─ light-template-library/
│  ├─ light-template-library.cpp   # пример использования
│  └─ ltl/                         # заголовочные файлы библиотеки
│     ├─ vector.h
│     ├─ string.h
│     └─ ...
├─ html/                           # сгенерированная Doxygen документация
├─ latex/                          # LaTeX-версия документации
├─ docs/                           # эта документация
│  ├─ BUILD.md
│  └─ STRUCTURE.md
├─ index.html                       # редирект на html/index.html
└─ LICENSE                          # MIT License
```

Файлы `html/` и `latex/` получены из Doxygen и содержат подробную автогенерированную документацию по заголовкам `ltl/`.
