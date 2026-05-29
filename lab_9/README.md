# Лабораторная работа №9
![alt text](skrin/image.png)

Используем git status, чтобы узнать, на какой ветке находимся.

![alt text](skrin/image-1.png)

Вывод git log.

![alt text](skrin/image-2.png)

Создадим файл sorted.c и выведим статус. Git предупреждает нас о том, что ветка main содержит 1 коммит, который еще не отправлен на удаленный сервер origin, а также что файл sorted.c е отслеживается.

![alt text](skrin/image-3.png)

Добавили файл в облость stage.

![alt text](skrin/image-4.png)

Закоммитил файл sorted.c и вывел statu

![alt text](skrin/image-5.png)

Добавил информацию в файл sorted.c, Git сообщает о том, что изменения еще не добавлены в staging area.

![alt text](skrin/image-6.png)

Добавил информацию в stage, на пока что не закоммитил.

![alt text](skrin/image-7.png)

Доболнил информацию в файле sorted.c, после чего закоммитил и вывел журнал.

![alt text](skrin/image-8.png)
![alt text](skrin/image-9.png)

Перенес файл в область stage, закоммитил и запушил на удаленный реп.

Работа с ветками.

![alt text](skrin/image-10.png)

Создал ветку mybranch и проверил на какой ветке нахожусь.

![alt text](skrin/image-11.png)
![alt text](skrin/image-12.png)
![alt text](skrin/image-14.png)

После переключения на другую ветку команда git status показывает, в какой ветке мы находимся. Когда мы вернулись в ветку main и использовали команду git log --oneline –graph, в журнале не было коммитов из mybranch.

![alt text](skrin/image-15.png)

Наш файл file2.txt пропал.

![alt text](skrin/image-16.png)

Оценка 4.

![alt text](skrin/image-17.png)

Git giff показывает, что изменилось в файле sorted.c

![alt text](skrin/image-18.png)

git diff --staged пустой

![alt text](skrin/image-19.png)
![alt text](skrin/image-20.png)
![alt text](skrin/image-21.png)
![alt text](skrin/image-22.png)
![alt text](skrin/image-23.png)

Добавил строку "printf("hello git\n");" в файл sorted.c, но изменения не добавлены в stage, также Git предлагает использовать git restore sorted.c для отмены изменений в рабочей директории.

![alt text](skrin/image-24.png)
![alt text](skrin/image-25.png)

После команды git restore sorted.c файл Sort.c выглядит так (т. е. наша строка printf(“hello git\n”) исчезла):

![alt text](skrin/image-26.png)

![alt text](skrin/image-27.png)

Git status советует нам отправить ветку в удаленный репозиторий.

![alt text](skrin/image-28.png)

Часть 2

![alt text](skrin/image-29.png)
![alt text](skrin/image-30.png)
![alt text](skrin/image-31.png)

Git status показывает, что мы находимся в ветке feature/uppercase.

![alt text](skrin/image-32.png)
![Я](skrin/image-33.png)
![alt text](skrin/image-34.png)

Когда мы перейдем в основную ветку, cat выведет hello, а после объединения веток — HELLO.

![alt text](skrin/image-35.png)

Git Показывает, что изменилось в ветке feature/uppercase относительно того момента, когда она отделилась от mybranch, но только для файла greeting.txt.

![alt text](skrin/image-36.png)
![alt text](skrin/image-37.png)
![alt text](skrin/image-38.png)

Оценка 5

![alt text](skrin/image-39.png)
![alt text](skrin/image-40.png)
![alt text](skrin/image-41.png)
![alt text](skrin/image-42.png)

Из журналы мы можем узнать, что находимся в ветке main на коммите 78b5af3
main опережает origin/main
mybranch опережает origin/mybranch
Ветки main и branch1 расходятся после коммита bcc9bd1

![alt text](skrin/image-44.png)
![alt text](skrin/image-45.png)
![alt text](skrin/image-46.png)
![alt text](skrin/image-47.png)
![alt text](skrin/image-48.png)

Починим Merge конфликты для сортировки MergeSort на python.

![alt text](skrin/image-49.png)
![alt text](skrin/image-50.png)
![alt text](skrin/image-51.png)
![alt text](skrin/image-52.png)
![alt text](skrin/image-53.png)
![alt text](skrin/image-54.png)
![alt text](skrin/image-55.png)
![alt text](skrin/image-56.png)