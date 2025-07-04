# Старый проект: Полиморфные векторы без шаблонов (C)

**Год создания:** 2023\
**Статус:** Архивный / Учебный

## Описание

Проект реализует полиморфную векторную алгебру без использования шаблонов, как это принято в C++. Вместо этого используется подход на C с функциями обратного вызова и `void*`, позволяющий абстрагироваться от конкретного типа данных. Программа позволяет выполнять операции над векторами с элементами произвольного типа, если для них задано поведение в виде кольца (`RingInfo`).

## Цели проекта

- Исследование подходов к реализации обобщённого программирования в C
- Имитация полиморфизма без использования шаблонов (через `void*` и таблицы функций)
- Реализация алгебраических операций над векторами
- Создание CLI-интерфейса и базовой системы тестирования

## Реализованные возможности

- Интерфейс кольца (`RingInfo`, `ring.h`):
  - Структура с указателями на функции сложения, умножения, вычитания, копирования и сравнения
  - Значения "нуль" и "единица" как `void*`
  - Встроенные реализации для типов `int` и `double`

- Структура `vector` (`vector.h`, `vector.c`):
  - Хранит координаты вектора (`void**`), количество элементов, информацию о типе (`RingInfo`), имя вектора
  - Операции: создание, удаление, сумма, скалярное произведение

- CLI-меню (`Menu()`):
  - Создание новых векторов с заданием типа (целые или вещественные)
  - Просмотр хранилища и удаление векторов
  - Выполнение операций: сумма, скалярное произведение

- Система тестирования (`Asserts()`):
  - Проверка корректности работы операций над векторами
  - Проверка совместимости типов и размерностей

## Особенности реализации

- Отказ от шаблонов в пользу ручной эмуляции обобщённости
- Применение `void*` и приведения типов внутри операций
- Кольца реализованы как наборы функций, соответствующих арифметике типов
- Векторы сохраняются в глобальном массиве `Storage[16]` с именами для выбора пользователем

## Пример запуска

```c
printf("1)Открыть меню\n2)Запустить тесты\n");
int x;
scanf_s("%d", &x);
switch (x) {
  case 1: Menu(); break;
  case 2: Asserts(); break;
}
```

Проект был создан с целью изучения низкоуровневой реализации полиморфизма и обобщённого кода на языке C, без применения C++-шаблонов и стандартной библиотеки STL.

