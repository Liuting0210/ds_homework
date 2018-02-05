#include<stdio.h>
#include"sqlist.h"


void main()
{
    sqlist list;
	int q;
	init_sqlist(&list);//初始化测试
	for(int i=0;i<10;i++)
	{
		 insert(&list,i,i*10);
	}
	insert(&list,5,45);//插入元素测试
	//show(&list);//打印顺序表元素测试
	printf("%d\n",search(&list,50));//查找元素测试
	delete_pos(&list,3);//删除指定位置元素测试
	//show(&list);
	delete_value(&list,70);//删除元素
	//show(&list);
	printf("%d\n",get_length(&list));//获得顺序表长度测试
	get_elem(&list,5,&q);//获得元素测试
	printf("%d\n",q);
	is_empty(&list);//判断是否为空
	clear_sqlist(&list);//清零顺序表
	destroy_sqlist(&list);//销毁顺序表

/*
	//删除A中出现在B中的元素
	sqlist listA,listB;
	init_sqlist(&listA);
	init_sqlist(&listB);
	for(int i=0;i<10;i++)
	{
		insert(&listA,i,2*(i+1));
		insert(&listB,i,3*(i+1));
	}
	for(int i=0;i<listB.len;i++)
	{
		if(search(&listA,listB.elem[i])!=-1)
		{
			delete_value(&listA,listB.elem[i]);//删除A中出现在B中的元素
		}
	}
	show(&listA);
	show(&listB);


	//顺序表C中元素非递减排列
   sqlist listA,listB,listC;
   init_sqlist(&listA);
   init_sqlist(&listB);
   init_sqlist(&listC);
   for(int i=0;i<10;i++)
   {
	   insert(&listA,i,2*(i+1));
	   insert(&listB,i,3*(i+1));
   }
   for(int i=0;i<listA.len;i++)
   {
	   insert(&listC,i,listA.elem[i]);
   }
   for(int i=listA.len;i<listA.len+listB.len;i++)
   {
	   insert(&listC,i,listB.elem[i-listA.len]);
   }
   show(&listC);
   for(int i=0;i<listC.len;i++)
   {
	   for(int j=i+1;j<listC.len;j++)
	   {
		   if(listC.elem[i]>listC.elem[j])
		   {
			   int temp;
			   temp=listC.elem[i];
			   listC.elem[i]=listC.elem[j];
			   listC.elem[j]=temp;
		   }
	   }
   }
 show(&listC);*/
	

}