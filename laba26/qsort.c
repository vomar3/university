//
// Created by lasto on 09.05.2024.
//

#include "queue.h"

queue Concatenation(queue *first, queue *second)
{
    queue f = *first, s = *second;
    while (!Empty(&s))
    {
        Push(&f, Top(&s));
        Pop(&s);
    }
    return f;
}

queue Qsort(queue *q){
    if (Empty(q))
        return *q;
    if (Size(q) == 1)
        return *q;
    int num = Top(q).key;

    queue left, right;
    Create(&left);
    Create(&right);

    while(!Empty(q)){
        if (Top(q).key <= num){
            Push(&left, Top(q));
        }else{
            Push(&right, Top(q));
        }
        Pop(q);
    }

    if(Empty(&right)){
        Push(&right, Top(&left));
        Pop(&left);
    }

    left = Qsort(&left);
    right = Qsort(&right);

    return Concatenation(&left, &right);
}
