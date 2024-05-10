#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "qsort.h"

void print_menu();

int main() {
    queue q;
    data_type t;
    Create(&q);

    queue q2;
    data_type y;
    Create(&q2);

    print_menu();
    int number;
    scanf("%d", &number);

    while (1){
        switch (number) {
            case 0:
                Destroy(&q);
                puts("Программа завершена!");
                exit(0);

            case 1:
                printf("Печатаю список...\n");
                Print(&q);

                break;
            case 2:
                printf("Введите элемент для вставки (ключ - значение): \n");
                scanf("%d - %d", &t.key, &t.value);
                Push(&q, t);
                printf("Элемент успешно добавлен.\n");

                break;
            case 3:
                if (!Empty(&q)) {
                    printf("Элемент <%d - %d> удалён.\n", Top(&q).key, Top(&q).value);
                    Pop(&q);
                } else {
                    puts("Очередь пуста!");
                }

                break;
            case 4:
                printf("Идет подсчет длины...\n");
                printf("Длина = %d", Size(&q));
                printf("\n");

                break;
            case 5:
                printf("Сортирую очередь...\n");
                q = Qsort(&q);
                break;

            default:
                printf("Введены неверные данные, попробуйте ввести снова!\n");
        }

        print_menu();
        scanf("%d", &number);
    }

    return 0;
}

void print_menu(){
    printf("Введите 0, чтобы завершить программу.\n");
    printf("Введите 1, чтобы напечатать очередь.\n");
    printf("Введите 2, чтобы вставить новый элемент в очередь.\n");
    printf("Введите 3, чтобы удалить элемент из очереди.\n");
    printf("Введите 4, чтобы подсчитать длину очереди.\n");
    printf("Введите 5, чтобы отсортировать очередь.\n");
}
