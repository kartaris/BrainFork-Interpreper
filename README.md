# BrainFork-Interpreter
BrainFork Interpreter with 16bit words

**Пример запуска**:

    $brainfork_interpreter {script_path} {optimize}
    
**Параметры запуска**:

1. **{script_path}** - путь к скрипту
2. **{optimize}** - 1 для включения оптимизаций, 0 для выключения

## Оптимизации
1.	Операторы >/< объединены в одну операцию **SHIFT** с направлением("-1" - сдвиг влево, "+1" - сдвиг вправо). Цепочки 
данных операций сворачиваются в одну операцию путем "сложения направлений". Если в итоге получаем 0 - операция просто 
исключается из списка операций;
2.	Операторы +/- объединены в одну операцию **INC** с приращением("-1" - уменьшаем значение, "+1" - увеличиваем). 
Цепочки данных операций также сворачиваются в одну операцию путем сложения приращений. 
Если в итоге получаем 0 - операция просто исключается из списка операций;
3.	Выделена группа операций [+]/[-] под названием **ZERO**. В данном случае цепочку из данных операций просто 
превращаем в одну операцию **ZERO**;
4.  Алгоритм суммирования 
    [- SHIFT(k) + SHIFT(-k)] 
выделен в операцию **ADD**;
5.  Алгоритм перемещения значения текущей ячейки 
    [SHIFT(k) ZERO SHIFT(-k) ADD(k)] 
выделен в операцию **MOVE**;
6.  Алгоритм копирования значения текущей ячейки 
    [SHIFT(k) ZERO SHIFT(t) ZERO SHIFT(-k-t) [ -SHIFT(k) + SHIFT(t) + SHIFT(-k-t) ] SHIFT(k+t) MOVE(-k-t)]
выделен в операцию **COPY**;
7.  Алгоритм умножения
    [- SHIFT(k) INC(b) SHIFT(-k)]
выделен в операцию **MULT**.  


## TODO
1.  Реализовать оператор "Y"
2.  Анализ синтаксиса
3. ...
