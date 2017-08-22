struct student{
    char var1;
    int  var2;
    long long var3;
    char var4;
    char arr[11];
};
/*  在自然对齐中：
    数据对齐的标准为 ————————自身大小
    于是var1起始地址为1，var2为4，var3为8，var4为16，arr为17
    结构体的对齐则为——————其大小为最大元素（不是数组而是那个long long）
    于是结构体本身为28，为了对齐变成了32
*/


#program pack(1)    //值可以为1,2,4,8,16
#program pack()     //取消自定义的对齐方式
/*
以上两种方式可以改变默认对齐，指定完之后
数据的对齐方式会在原先标准下，与pack指定值之中取那个 “小”值
结构体的对齐方式在原先标准下，与pack指定值之中取那个 “小”值
*/

struct student1{
    char var1;
    int  var2;
    long long var3;
    char var4;
    char arr[11];
}__attribute__((aligned(2))) stuexample1;
struct student2{
    char var1;
    int  var2;
    long long var3;
    char var4;
    char arr[11];
}__attribute__((packed)) stuexample2;
/*
  以上两种方式作用于单个结构体，指定对齐数，或者使用packed来指定对齐1
*/

