# Лабораторная работа 2

## Задача

  Реализовать пользовательский тип для целого беззнакового числа
фиксированной длины **uint2022_t**. Размер получившегося типа не должен превышать 2200 байт.

  Для вышеуказанного типа требуется реализовать следующий набор функций и операторов

     1. Конвертация из типа uint32_t
     2. Конвертация из строки
     3. Сложение
     4. Вычитание
     5. Умножение
     6. Вывод числа в консоль


## Инструкция по выполнению

Вам дан шаблон проекта, состоящие из трех директорий:
- **bin**
- **lib**
- **tests**

Менять стуктуру проекта, добавлять, новый файлы запрещается.

Требуется:
  1. Реализовать тип **uint2022_t**, описав его в заголовочном файле **lib/number.h** (!Обратите внимание что такая структура там уже есть, требуется дополнить ее описание)
  2. Реализовать вышеуказанные функции и операторы, написав реализацию в **lib/number.cpp**

### Тесты

Проект содержит базовый набор тестов, который позволит убедится, что реализация функций выполненная без явных ошибок.
Для запуска тестов в командной строке можно выполнить след операцию:

***cmake --build . --target number_tests && ctest -V***  или воспользоваться средствами вашей IDE

Пока все тесты не будут проходить, показывать лабораторную - нельзя

### Если этого не хватило

В директории **bin** находится консольное приложение, которые вы также можете использовать по вашему усмотрение, что бы проверить свой код.
Для запуска выполнить след команду:

***cmake --build . --target lab1 && bin/lab1*** или воспользоваться IDE


## Примечание
 - Переполнение - Undefined Behavior

## Дополнительно
 - cmake
 - GoogleTest
