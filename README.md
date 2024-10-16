# Задача №2.

#### Выполнил: Васюк Денис Русланович

## Сборка и запуск:
- cd build
- cmake .
- make


В папке bin в корне репозитория появится исполняемый файл Searcher. 
Он имеет CLI и при запуске печатает формат ввода.
Таже в папке bin будет лежать исполняемый файл Tests, запускающий тесты. Он требует установленного в систему gtest.

### Техническое описание продукта:
- Как основная структура хранения и поиска строк использован самописный бор. В каждой вершине хранится максимальная частота слов поддерева и достаточная информация для быстрого спуска к лексикографически минимальной строке с этим числом вхождений.
- В боре также хранится текущий фиксированный запросом префикс (строка и вершина), чтобы не спускаться заново при каждом дописывании, как и просили в условии. Хранить также информацию о результате последнего запрса было сочтено бессмысленным, т.к. дописывать буквы обычно нужно, чтобы получить более точный, не совпадающий с данным, результат.
- Было решено считать словами последовательности, состоящие из латинских букв, цифр, символов '-' и '_'. Остальные символы считаются мусором и отбрасываются. Сделано это ради возможности адекватно работать с текстами без преобразований со стороны пользователя.
- Тестами покрыты простые случаи запросов к поисковику и функции преобразования слов в соответствии с описанным выше решением.
- Время выполнения каждого запроса линейно от суммы размеров входной и выходной строки. Это несложно увидеть по коду: find_best() линеен от ответа. add(), process() и update() (последние 2 - не считая описанного ранее вызова find_best()) линейны от входа.
