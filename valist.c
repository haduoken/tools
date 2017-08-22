/* va_arg example */
#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

int FindMax (int n, ...)
{
  int i,val,largest;
  va_list vl;       //初始化va_list将来会代表所有的变参
  va_start(vl,n); //相当于valist的初始化工作，参数 n 为上面函数的最后一个参数，用于指明变参的开始位置
  largest=va_arg(vl,int); //依次获取变参中的下一个元素，int是指它的类型
  for (i=1;i<n;i++)
  {
    val=va_arg(vl,int);
    largest=(largest>val)?largest:val;
  }
  va_end(vl); //返回之前的关闭
  return largest;
}
int main ()
{
  int m;
  m= FindMax (7,702,422,631,834,892,104,772);
  printf ("The largest value is: %d\n",m);
  return 0;
}

/* 另外一个使用的例子，感觉和上面的差不多
#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */
void PrintFloats (int n, ...)
{
  int i;
  double val;
  printf ("Printing floats:");
  va_list vl;
  va_start(vl,n);
  for (i=0;i<n;i++)
  {
    val=va_arg(vl,double);
    printf (" [%.2f]",val);
  }
  va_end(vl);
  printf ("\n");
}

int main ()
{
  PrintFloats (3,3.14159,2.71828,1.41421);
  return 0;
}  */
 /*为了直接包装vsprintf函数使用的一个例子。随便看看吧
  #include "stdafx.h"
void func(char *format,...)
{
	char buffer[256];
	va_list valist;
	va_start(valist, format);
	vsprintf(buffer, format, valist);
	printf(buffer);
	va_end(valist);
}
int main()
{
	func("%d is the % s",4,"sb");
	return 0;
}
 */
