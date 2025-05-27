# Лабораторная работа №7

## Ход работы

### 1. Установка и подготовка среды
Работа выполнялась в среде Fedora 14.0. Установлены следующие инструменты:
  
  ● clang — компилятор языка C/C++;
  
  ● llvm — инструменты анализа и оптимизации кода;
  
  ● opt — инструмент для работы с LLVM IR и применения оптимизаций;
  
  ● Graphviz — инструмент для визуализации кода.
  
Команда установки: ```sudo dnf install clang llvm```
  
![image_2025-05-14_12-18-53](https://github.com/user-attachments/assets/92a2aaa1-bcf0-427f-b19c-c89379ed6108)

![image](https://github.com/user-attachments/assets/fd2a4876-5c04-4426-ad64-9434b93f254d)

### 2. Исходный код
``` C
#include <stdio.h>
int main(void) {
  printf("Hello, LLVM!\n");
  return 0;
}
```
Сохранена в файл hello.c

![image](https://github.com/user-attachments/assets/86a8feb6-b977-4173-8ce2-057a56be896f)

### 3. Получение AST
Команда: ```clang -Xclang -ast-dump -fsyntax-only hello.c```
   
![image](https://github.com/user-attachments/assets/3b1c13b6-7a13-41ea-be65-53f9eaf1c254)

### 4. Генерация LLVM IR
Команда: ```clang -S -emit-llvm hello.c -o hello.ll```

![image](https://github.com/user-attachments/assets/c554f9ef-b14f-46f5-bb83-21e7738c6f31)

### 5. Оптимизация IR
Команда: ```opt -O2 hello.ll -S -o hello_opt.ll```

![image](https://github.com/user-attachments/assets/3c84552e-276e-480f-8c21-b9c359666c20)

Команда: ```diff -u hello.ll hello_opt.ll```
  
Сравнение двух файлов:

![image](https://github.com/user-attachments/assets/59f57d8a-c917-40d6-9838-be51a83f79aa)

Стоит отметить, что после оптимизации произошли следующие изменения:

  ● Переменные типа alloca были удалены;
  
  ● Код переведён в SSA-форму;
  
  ● Оптимизация улучшила читаемость и упростила поток управления.

### 6. Граф потока управления программы
Команда для генерации оптимизированного LLVM IR: ```opt -passes=dot-cfg -disable-output hello_opt.bc```

![image](https://github.com/user-attachments/assets/ac20eb93-d9c7-45e4-9579-d77e931a3bf5)

Команда для генерации .dot-файлов CFG для функций: ```dot -Tpng cfg.main.dot -o cfg_main.png```

![image](https://github.com/user-attachments/assets/26e81a1f-c704-4a95-a626-a3612df11e09)

## Команды терминала
```bash
sudo dnf install clang llvm
clang -Xclang -ast-dump -fsyntax-only hello.c
clang -S -emit-llvm hello.c -o hello.ll
opt -O2 hello.ll -S -o hello_opt.ll
diff -u hello.ll hello_opt.ll
```

## Скриншоты работы
![image_2025-05-14_12-18-53](https://github.com/user-attachments/assets/878fd8df-5c83-4d9b-ba02-b1b7b3eaf723)

![image](https://github.com/user-attachments/assets/2eadaa81-e871-4755-a906-88e88c861054)

![image](https://github.com/user-attachments/assets/a9ba7ad0-1953-4434-9c4b-16daf58ad8e3)

![image](https://github.com/user-attachments/assets/6d54772b-b1c3-42de-b979-e01878ee77ac)

![image](https://github.com/user-attachments/assets/b58f740d-9bf9-4f10-8690-9cdba7f76c92)

![image](https://github.com/user-attachments/assets/a57b2a09-71d8-440f-9076-6b6cb1779ba2)

![image](https://github.com/user-attachments/assets/db718cc0-306a-4b03-bb19-7725113b52de)

![image](https://github.com/user-attachments/assets/a82b6cfd-0380-4b99-bbc7-fcd2f52b18f9)

![image](https://github.com/user-attachments/assets/98ae4cc6-7ec8-4bcc-b7d7-d95451277c5c)

![image](https://github.com/user-attachments/assets/81901c24-19ff-484f-a30c-b72962bc3243)

![image](https://github.com/user-attachments/assets/1053b3ee-ee5a-4b92-8c09-ce3ac8a3247c)

![image](https://github.com/user-attachments/assets/58805fe9-75f6-4786-828f-9a6a315dd8ab)

![image](https://github.com/user-attachments/assets/2632be1f-d203-4908-b795-7d28c68a3d6f)

![image](https://github.com/user-attachments/assets/f86a5226-a726-4810-8a68-39b9c917ba00)

![image](https://github.com/user-attachments/assets/59352041-f58f-420a-b353-e8277b5f86ee)

![image](https://github.com/user-attachments/assets/23a76d3b-1e02-4e8f-b8cf-00a659ce1661)

![image](https://github.com/user-attachments/assets/092d9abd-fb3a-4d66-a237-e69078151721)

![image](https://github.com/user-attachments/assets/8c7f747a-6adf-4a77-846c-eb87d90e5136)

![image](https://github.com/user-attachments/assets/f327eee1-aa64-4ff8-a2e2-593180bd8a37)

![image](https://github.com/user-attachments/assets/57cfde4f-5e63-47ee-ba31-12caabe52d9d)

![image](https://github.com/user-attachments/assets/b624bef8-2719-4d16-a6a7-5167a821a31c)

## Промежуточные выводы по каждому заданию
1. **Установка Clang/LLVM на Fedora**  
   **Вывод:** Установлены все необходимые пакеты (`clang`, `llvm`, `llvm-tools-extra`, `lld`, `lldb`, `graphviz`), команды `clang`, `opt`, `llvm-dis` и `dot` доступны в PATH.

2. **Создание простого C-файла**  
   **Вывод:** Файл `hello.c` с корректным примером «Hello, LLVM!» создан; синтаксис проверен без ошибок.

3. **Генерация AST**  
   **Вывод:** AST успешно выгружено в `hello_ast.txt`. Структура дерева соответствует исходному коду (узел `FunctionDecl main`, внутри — `CallExpr printf` и др.).

4. **Генерация LLVM IR**  
   - **Текстовый IR (`hello.ll`):**  
     **Вывод:** Читаемая текстовая версия IR содержит определение функции `@main` и глобальные данные.  
   - **Биткод (`hello.bc`):**  
     **Вывод:** Файл `hello.bc` распознаётся командой `file` как «LLVM IR bitcode».

5. **Оптимизация IR с помощью `opt -O2`**  
   **Вывод:** Оптимизированный биткод `hello_opt.bc` и текстовый IR `hello_opt.ll` созданы. В `hello_opt.ll` удалены неиспользуемые блоки и константы, код упрощён.

6. **Построение графа потока управления (CFG)**  
   **Вывод:** Сгенерирован файл `cfg.main.dot` и успешно преобразован в изображение `cfg_main.png`. Граф отображает основные базовые блоки и переходы внутри `main`.

## Выводы
● С помощью Clang можно получить полную структуру AST и IR, а также CGF;

● LLVM предоставляет гибкие инструменты анализа и оптимизации;

● Промежуточное представление кода удобно для написания компиляторных трансформаций.


## Дополнительное задание Вариант 3

![изображение](https://github.com/user-attachments/assets/bb1f1f0f-710f-4e2b-b6d1-c17e9dc0112b)


IR без оптимизаций (`-O0`):

```clang -S -emit-llvm -O0 variant3.cpp -o variant3:_O0.ll```

![изображение](https://github.com/user-attachments/assets/adbd0b5c-619a-4d78-bc19-177b66a6c259)


Фрагмент IR с оптимизацией:

![изображение](https://github.com/user-attachments/assets/5acbd306-6aed-4afa-a4cb-0fd3a38bc9b3)



**Вывод:** Оптимизация не меняет структуру: используется всё та же тройка чисел, так как вычисление выполняется во время выполнения.
