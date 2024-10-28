#include <stdio.h>
#include <stdlib.h>

// [1.1] ประกาศตัวแปร global 3 ตัว
int global_var1 = 10;
int global_var2 = 20;
int global_var3 = 30;

// ประกาศโปรโตไทป์ของฟังก์ชัน
void function1(int level);
void function2(int level);
void function3(int level);

int main() {
    // [1.2] พิมพ์ที่อยู่และค่าของตัวแปร global
    printf("Address of global_var1: %p, Value: %d\n", (void*)&global_var1, global_var1);
    printf("Address of global_var2: %p, Value: %d\n", (void*)&global_var2, global_var2);
    printf("Address of global_var3: %p, Value: %d\n", (void*)&global_var3, global_var3);
    printf("\n");

    // [2.1] ทำการ malloc 3 ครั้งใน main
    int *heap_var1 = (int*)malloc(sizeof(int));
    int *heap_var2 = (int*)malloc(sizeof(int));
    int *heap_var3 = (int*)malloc(sizeof(int));

    // [2.2] จากนั้นตรวจสอบว่า allocate สำเร็จไหม

    if (heap_var1 == NULL || heap_var2 == NULL || heap_var3 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // [2.3] ทำการ assign ค่า ให้แต่ละตัว
    *heap_var1 = 100;
    *heap_var2 = 200;
    *heap_var3 = 300;

    // [2.4] output ออกมา
    printf("Address of heap_var1: %p, Value: %d\n", (void*)heap_var1, *heap_var1);
    printf("Address of heap_var2: %p, Value: %d\n", (void*)heap_var2, *heap_var2);
    printf("Address of heap_var3: %p, Value: %d\n", (void*)heap_var3, *heap_var3);
    printf("\n");

    // [2.5] free memory
    free(heap_var1);
    free(heap_var2);
    free(heap_var3);

    // [3.4] เรียกใช้ function ใน main
    function1(1);

    return 0;
}       

// [3.1] function1 พิมพ์ที่อยู่ local variable ของมัน และเรียก function2 และเพิ่ม level บอกระดับ
void function1(int level) {
    int local_var1 = level;
    printf("Function1: Level %d\n", level);
    printf("Address of local_var1 in function1: %p\n", (void*)&local_var1);
    function2(level + 1);
}

// [3.2] function2 พิมพ์ที่อยู่ local variable ของมัน และ เรียก function3 และเพิ่ม level บอกระดับ 
void function2(int level) {
    int local_var2 = level;
    printf("Function2: Level %d\n", level);
    printf("Address of local_var2 in function2: %p\n", (void*)&local_var2);
    function3(level + 1);
}

// [3.3] function3 แค่พิมพ์ที่อยู่ local variable ของมัน
void function3(int level) {
    int local_var3 = level;
    printf("Function3: Level %d\n", level);
    printf("Address of local_var3 in function3: %p\n", (void*)&local_var3);
    printf("\n");
}
