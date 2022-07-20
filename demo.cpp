#include<boost/property_tree/ptree.hpp>  
#include<boost/property_tree/json_parser.hpp>  
#include <boost/property_tree/ini_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/thread/thread.hpp>
#include <boost/filesystem.hpp>  
#include <boost/circular_buffer.hpp> 
#include <boost/bind.hpp>
#include<Windows.h>
#include<iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <map>
#include <assert.h>
//#include <time.h>
using namespace std;
using namespace  boost::property_tree; //名字空间

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)

#if 0


int aaa = 0;

class qq :public quanjulei
{
public:


private:

};



int test01() {
	ptree pt;
	try
	{
		read_json("D:/c++demo/ConsoleApplication1/XMLFile1.json", pt);
		cout << "stu.name:" << pt.get<string>("stu.name") << endl;
		cout << "stu.age:" << pt.get<int>("stu.age") << endl;//25
		cout << "stu.age:" << pt.get<float>("score") << endl;//99.99
		auto child = pt.get_child("lesson");

		//遍历json数组，拿到数组中的元素。方法1。
		BOOST_FOREACH(boost::property_tree::ptree::value_type &v, child)
		{
			cout << v.second.data() << endl;
			Sleep(1000);
		}

		//遍历json数组，拿到数组中的元素。方法2。---推荐
		for (auto it = child.begin(); it != child.end(); it++)
		{
			cout << it->second.data() << endl;
			// it->first.data()是空的
		}

		/*遍历json数组，拿到数组中的对象的值。
		BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt_item)
		{
			pt_item3 = v.second;
			pCJQ->MQ_info[i].Host = pt_item3.get<string>("Host");
		}
			*/

	}
	catch (const std::exception& err1)
	{
		cout << " 出现异常" << err1.what() << endl;
		return 0;
	}
	return 0;
}


void  test02() {//测试map容器后面跟的第一个标号，是容器的标号，还是数组的标号。
	map<int, int> a[3];//每个数组的元素是map
	try
	{
		a[0][0] = 00;//数组  map！！
		a[1][1] = 11;
		a[1][0] = 10;
		a[0][1] = 01;
		a[1][3] = 13;
		a[1][2] = 12;
		//a[3][1] = 31; 报错
		for (size_t i = 0; i < 3; i++)
		{
			for (map<int, int>::const_iterator it = a[i].begin(); it != a[i].end(); it++)
			{
				cout << "key=" << (*it).first << ", value=" << (*it).second << endl;

			}
		}

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}


void test03() {
	ptree pt;
	try
	{
		//方法一 
		ini_parser::read_ini("../IniFile.ini", pt);
		cout << pt.get<int>("direct message.direct num") << endl;
		cout << pt.get<int>("direct message.direct1-MeterId") << endl;
		cout << pt.get<int>("direct message.direct2-MeterId") << endl;

		// 方法二
		basic_ptree<string, string> btItem = pt.get_child("direct message");//
		cout << btItem.get<int>("direct num") << endl;
		cout << btItem.get<int>("direct1-MeterId") << endl;
		cout << btItem.get<int>("direct2-MeterId") << endl;

		//写数据
		pt.put<int>("direct message.direct3-MeterId", 100);//这个时候，可以看作暂且写入到缓存区，还没有写到文件中。
		cout << pt.get<int>("direct message.direct3-MeterId") << endl;//从缓存区读出数据
		ini_parser::write_ini("../IniFile.ini", pt);//写入文件
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void test04() {
	typedef map<int, string> InsData;
	typedef map<int, InsData> ChnData;

	ChnData::iterator pIns;
	InsData::iterator pPoints;

	ChnData chn_one;
	InsData ins_map;

	pIns = chn_one.begin();


	ins_map = pIns->second;


}

void test05() {
	FILE* yc = fopen("D:\\c++demo\\ConsoleApplication1\\Debug\\XMLFile1.json", "r");
	if (yc)
	{
		printf("ok");
	}
	else
	{
		printf("no");
		perror("fopen");
	}
}

void test06()
{
	enum POKER { HONGTAO, HEITAO = 30, MEIHUA = 40, FANGKUAI }; //HEITAO=30这不是赋值

	//poker_color 的取值为HONGTAO, HEITAO, MEIHUA, FANGKUAI中某一个
	enum POKER poker_color = HEITAO;

	printf("poker_color = %d\n", poker_color);//30
	printf("HONGTAO = %d\n", HONGTAO);//0
	printf("HEITAO = %d\n", HEITAO);//30
	printf("MEIHUA = %d\n", MEIHUA);//40
	printf("FANGKUAI = %d\n", FANGKUAI);//41

}

int test07() {


	// 局部变量声明
	char grade = 'B';

	switch (grade)
	{
	case 'A':
		cout << "很棒！" << endl;
		break;
	case 'B':
	case 'C':
		cout << "做得好" << endl;
		break;
	case 'D':
		cout << "您通过了" << endl;
		break;
	case 'F':
		cout << "最好再试一下" << endl;
		break;
	default:
		cout << "无效的成绩" << endl;
	}
	cout << "您的成绩是 " << grade << endl;

	return 0;

}

void test08() {

	time_t curtime;
	curtime = time(0);

	SYSTEMTIME st;
	GetLocalTime(&st);
	printf("%d_%03d.dat", (int)curtime, st.wMilliseconds);//
	//(int)curtime 离1970的秒数  st.wMilliseconds当前系统的毫秒
	printf("%d_%d.dat", (int)curtime, st.wMinute);//当前系统的分钟的
}

//成员函数，内部调用其他成员函数
void test09() {

	class MyClass
	{
	public:

		int class_fun() {
			return 1;
		}

		int calss_fun1() {
			return class_fun();
		}
	private:

	};

	MyClass my;
	printf("%d", my.calss_fun1());
}

void test10() {
	//设置一个父类
	class Base
	{
	public:
		int a;
	private:
		int b;
	protected:
		int c;
	};

	//设置一个子类
	class Son :public Base
	{
	public:
		//父类中的public数据  在子类中 也是public
		//父类中的private数据 在子类中 是不可见的
		//父类中的protected数据 在子类中 是protected的

		//子类的内部
		void showSon()
		{
			a = 100;//父类中的public数据
			//b = 200;//父类中的private数据，不能直接访问
			c = 300;//父类中的protected数据，在子类 内部是可以访问的
		}
	};


	Base oba;
	oba.a = 0;

	Son ob;
	ob.a = 100;
	cout << "zi类中的public数据a = " << ob.a << endl;//100

	cout << "父类中的public数据a = " << oba.a << endl;//0 
 // ！！子类虽然拥有了父类的变量，但是父子类的数据，是分来的。

	//ob.b = 200;//在子类外 访问不了
	//ob.c = 200;//在子类外 访问不了



}

void  test11() {

	class Base
	{
	public:
		int a = 10;

		void print()
		{
			cout << "Base: a=" << a << endl;//Base: a=10
		}
	};

	class Derive : public Base
	{
	public:
		int a = 20;
		void print()
		{
			cout << "DERIVE: a=" << a << endl;//DERIVE: a = 20
			cout << "DERIVE TO Base: a=" << Base::a << endl; //使用域名限定
			//DERIVE TO Base: a=10
		}
	};


	Base bc;
	Derive dc;

	bc.print();
	dc.print();
	cout << dc.Base::a << endl;//使用域名限定
	//10
	system("PAUSE");
}

void test12() {
	//有返回值虚函数


	class A
	{
	public:
		int a;
		A(int aaa = 1) { a = aaa; }
		virtual int print()
		{
			return a;
		}
	};

	class B : public A
	{
	public:
		int a;
		B(int bb = 2) { a = bb; }
	};

	class C : public A
	{
	public:
		int a;
		C(int cc = 3) { a = cc; }
		virtual int print()
		{
			return a;
		}
	};

	class D : public A
	{

		int sk;
	public:
		int dd = 0;




		int Init() {
			dd = print();//这个时候访问的是A类中的数据，因为我没重写这个函数
			cout << dd << endl;//1
			return dd;
		}

	};


	A ap;
	cout << ap.print() << endl;//1

	B bp;
	cout << bp.print() << endl; //输出结果仍然为1

	C cp;
	cp.print(); //输出3
	cout << cp.print() << endl;
	cout << "..............." << endl;
	D dp;
	cout << dp.a << endl;//1
	cout << dp.dd << endl;//0
	cout << dp.Init() << endl;//1;
	//！！如果Init函数没有返回值的话，比如返回值类型为void，那么cout是不会打印的。
	//！！在c++中，如果返回值是非void，那么一定要写return的，否则报错，而c中只是报警


	system("PAUSE");

	return;

}


void test13() {
	class A
	{
	public:
		struct a//成员
		{
			int Num;//成员的成员
		};

		/*a test;
		test.Num = 1;//错误提示：此声明没有存储类或类型说明符
	*/
	};//不


	class B
	{
	public:
		struct a//成员
		{
			int Num;//成员的成员
		};



		void  fun() {
			a test;
			test.Num = 1;//错误提示：此声明没有存储类或类型说明符
		}
	};//不
}
void test14() {

	unsigned char a = 0;
	unsigned char b = 0;

	unsigned char FC1_CMD[] = { 0X01,0X03,0X00,0X00,0X00,0X0B, };
	unsigned char FC2_CMD[] = { 1,3,0,0,0,11,a,b };
	cout << FC1_CMD << endl;
	cout << FC2_CMD << endl;
	printf("%#x\n", FC1_CMD[5]);
	printf("%#x\n", FC2_CMD[6]);
}


void test15() {
	class A
	{
	public:
		int a = 0;
		void fun1() {
			cout << ++a << endl;
		}

	};

	class B : public A
	{
	};

	class C : public A
	{
	public:

	};


	B b;
	b.fun1();

	C c;
	c.fun1();
}

//c++的类不允许其他类访问局部变量，
void test16() {

	//int a = 0;//不允许引用封闭函数的局部变量!!
	//翻译过来就是c++的类不允许其他类访问局部变量，
	//！但是，访问全局变量是可以的。 而且数据在两个子类中是有关联的。
	class A
	{
	public:

		void fun1() {
			cout << ++aaa << endl;
		}

	};

	class B : public A
	{
		int a = 100;
	};

	class C : public A
	{
	public:
		void fun2() {
			//printf("%u",a);
		}
	};


	B b;
	b.fun1();

	C c;
	c.fun1();
}

void test17() {

	extern AA aa;


	B b;
	b.setA(3);
	cout << aa.getA() << endl;
	return;

}


//测试boost线程函数，和bind函数
void test18() {
	//测试boost线程函数，和bind函数
	class HelloWorld
	{
	public:
		void hello()
		{
			//std::cout << str << std::endl;
		}
	};


	HelloWorld obj;
	boost::thread thrd(boost::bind(&HelloWorld::hello, &obj));//第三个参数是传参,c传给线程函数的形参
	thrd.join();
	return;

}

//??指针也能返回
float* type26(unsigned char* value)
{//??指针也能返回
	unsigned char tmp_buf[4] = { 0x01,0x02,0x03,0x04 };
	float v_f = 1;//局部变量的值 能返回？
	float* v_fp = &v_f;
	//memcpy(&v_f, tmp_buf, 4);

	//printf("%f,%f,%f,%f,\n", v_f, v_f, v_f, v_f);
	//printf("\n");
	printf("%f\n", v_f);


	return v_fp;
	//return 0;
}

//ASCII_To_Hex
uint8_t ASCII_To_Hex(uint8_t number)
{

	if (number >= '0' && number <= '9')
		return (number - 0x30);

	else if (number >= 'a' && number <= 'f')
		return ((number - 'a') + 10);

	else if (number >= 'A' && number <= 'F')
		return ((number - 'A') + 10);

	return (0);
}


void test19() {

	char string[20] = "FA15BF36987F";
	//uint8_t MAC_Buffer[6] = {0};//FA 15 BF 36 98 7F
	//char  MAC_Buffer[6] = {0};//FFFFFFFFA 15 FFFFFFBF 36 FFFFFF98 7F ??为什么char不行
	//这个问题的特征：一旦数据前面有f， 那么就会导致前面都是fffff，解决办法，就是用 uint8_t
	unsigned char  MAC_Buffer[6] = { 0 };//FA 15 BF 36 98 7F
	uint8_t i;
	uint8_t ch1;
	uint8_t ch2;
	char *p = NULL;
	p = string;
	for (i = 0; i < 6; i++)
	{
		ch1 = *p++;
		ch2 = *p++;
		ch1 = ASCII_To_Hex(ch1);
		ch2 = ASCII_To_Hex(ch2);
		MAC_Buffer[i] = (ch1 << 0x04) | ch2;
		printf("%02X ", MAC_Buffer[i]);//FA 15 BF 36 98 7F
		cout << strlen((const char *)MAC_Buffer) << endl;
		/*
		FA 1
		15 2
		BF 3
		36 4
		98 5
		7F 28????
		*/
		//类型显式转换 const char*  也可以
		//printf("%02X ", (const char*)MAC_Buffer[i]);//FA 15 BF 36 98 7F

	}
	cout << "sizeof" << sizeof(MAC_Buffer) << endl << "strlen" << strlen((const char *)MAC_Buffer) << endl;// sizeof6 strlen28  ???

}

void test20() {

	uint8_t write_msg[100] = { 0x01,0x02,0x03,0x04 };

	cout << "sizeof" << sizeof(write_msg) << endl << "strlen" << strlen((const char *)write_msg) << endl;

}

unsigned char CdtCrc(unsigned char *buff, int len)
{
	int q = 0, r = 0;
	int crc = 0;
	int i;
	while (q < len)
	{
		if (buff[q] & (0x80 >> r))
			crc |= 0x01;
		if (crc >= 0x100)
			crc ^= 0x107;
		crc <<= 1;
		r++;
		if (r == 8)
		{
			r = 0;
			q++;
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (crc >= 0x100)
			crc ^= 0x107;
		crc <<= 1;
	}
	crc >>= 1;
	crc = (~crc);
	return (unsigned char)crc;
}


unsigned short CheckCRC(unsigned char *pData, unsigned int siLen)
{
	if (NULL == pData || siLen <= 0)
	{
		return 0;
	}

	unsigned short u16CRC = 0xFFFF;
	for (int i = 0; i < siLen; i++)
	{
		u16CRC ^= (unsigned short)(pData[i]);
		for (int j = 0; j <= 7; j++)
		{
			if (u16CRC & 0x0001)
			{
				u16CRC = (u16CRC >> 1) ^ 0xA001;
			}
			else
			{
				u16CRC = u16CRC >> 1;
			}
		}
	}

	unsigned short siRet = 0;
	siRet = (u16CRC & 0x00FF) << 8;
	siRet |= u16CRC >> 8;

	return siRet;
}

//测试不同的crc校验
void test21() {
	try
	{


		unsigned short crc_msg;

		unsigned char buf[11] = { 0xcc,0x10,0x00,0x01,0x00,0x01,0x04,0x00,0x03,0x00,0x00 };
		cout << CdtCrc((unsigned char*)"cc10000100010400030000", 11) << endl;
		printf("%010x\n", CdtCrc((unsigned char*)"cc10000100010400030000", 11));
		printf("%010x\n", CdtCrc(buf, 11));
		printf("%010x\n", CheckCRC(buf, 11));//00000005ff
		crc_msg = CheckCRC(buf, 11);
		buf[9] = (unsigned char)(crc_msg >> 8 & 0xff);// 如果不右移的话，从 short 转到 char 那么导致float变量高位丢失！
		printf("%010x\n", buf[9]);

		buf[10] = (unsigned char)(crc_msg & 0xff);
		printf("%010x\n", buf[10]);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

}

//测试时间函数
void  test22() {
	char num[20] = { 0 };

	time_t now;
	struct tm* ltime;
	char time_cmd[13] = { 0xCC,0x10 };
	now = time(NULL);
	ltime = localtime(&now);

	cout << ltime->tm_mon + 1 << endl;
	cout << ltime->tm_year + 1900 - 2000 << endl;
	cout << ltime->tm_sec << endl;
	time_cmd[0] = ltime->tm_sec;
	printf("%d\n", time_cmd[0]);
	itoa(time_cmd[0], num, 10);//把10进制的数，转成10进制的数，不过是字符的形式。
	//!!做笔记
	unsigned char  MAC_Buffer[6] = { 0 };
	uint8_t i;
	uint8_t ch1;
	uint8_t ch2;
	char *p = NULL;
	p = num;//这个地方只能传字符串
	for (i = 0; i < 1; i++)
	{
		ch1 = *p++;
		ch2 = *p++;
		ch1 = ASCII_To_Hex(ch1);
		ch2 = ASCII_To_Hex(ch2);
		MAC_Buffer[i] = (ch1 << 0x04) | ch2;
		printf("%02X ", MAC_Buffer[i]);
		cout << "strlen" << strlen((const char *)MAC_Buffer) << endl;

	}



	return;

}

//测试时间函数2
void test22_1() {

	time_t curtime = 0;
	time(&curtime);
	cout << curtime << endl;
	cout << (curtime + 8 * 3600) % 86400 << endl;
	cout << curtime / 60 << endl;
	cout << curtime / 86400 / 365 << endl;



}

//把10进制的数，转成16进制的数，不过是字符的形式。
void test23() {

	int n = 123;
	char num[20] = { 0 };
	scanf("%d", &n);
	itoa(n, num, 16);//把10进制的数，转成16进制的数，不过是字符的形式。
	printf("%s\n", num);


	unsigned char  MAC_Buffer[6] = { 0 };//FA 15 BF 36 98 7F
	uint8_t i;
	uint8_t ch1;
	uint8_t ch2;
	char *p = NULL;
	p = num;
	for (i = 0; i < 1; i++)
	{
		ch1 = *p++;
		ch2 = *p++;
		ch1 = ASCII_To_Hex(ch1);
		ch2 = ASCII_To_Hex(ch2);
		MAC_Buffer[i] = (ch1 << 0x04) | ch2;
		printf("%02X ", MAC_Buffer[i]);//FA 15 BF 36 98 7F
		cout << strlen((const char *)MAC_Buffer) << endl;

	}
}




//测试  能不在
void test24() {

	unsigned char a = 12;
	printf("%d\n%d\n", a / 10, a % 10);
}

//strcat() 函数 把两个char数组元素接上  --只能接字符串
void test25() {

	char str1[50] = { 0xcc };
	char str2[30] = { 0xff };
	float str3[10];

	strcat_s(str1, str2);
	cout << str1 << endl;
	printf("%x", (float)str1[0]);
	//((recv_buf[i]) / 10) * 1536 + (recv_buf[i]) % 10;
	//记笔记：我不管你是这个数据是由什么数据区填充的，只要存在数组里，就是10进制的数据（默认是int类型），想看成其他进制的，就用格式符来打印就行
}

void test26_1(char *a, int b) {
	printf("%c\n %d\n %x\n", *a, b, a);
}
//测试，把函数的形参直接赋值到形参中
//测试结果可以的
void test26(char *a, int b) {

	test26_1(a, b);

}

/*测试用memcpy 把4个char数据(一个char类型的数组，有4个元素)合成 一个float类型的数据
测试结果：不行 memset，strcpy，没有这么用的，想要组合的话，就得是移位！！
*/
void test27(uint8_t* value) {

	for (size_t i = 0; i < 4; i++)
	{
		printf("%x", value[i]);
	}
	cout << endl;
	float v_f;//
	memcpy(&v_f, value, 4);//？？ 这个就是把四个usigned char 合成 float
	//我为什么测不出来？

	printf("%x\n", v_f);
	printf("%d\n", v_f);



}

/*
测试： unsigned char 左移8位， 不丢失数据
测试结果：
*/
void test28() {


}


void anlal_buf(unsigned char*** dest) {
	printf("%p\n", **dest);
	unsigned char a[100] = { 1,2,3 };
	memcpy(**dest, a, 3);

	//**dest = a;//**dest是数组指针，数组指针是“指针常量”，他不能被赋值

	const int aa = 0;
	int const bb = 0;
}

void read_all_data(unsigned char** dest) {
	printf("%p\n", *dest);
	anlal_buf(&dest);
}

/*
测试：多级指针的传递
测试结果：
*/
void test29() {
	unsigned char dest[100] = { 0 };
	unsigned char *p = dest;
	//unsigned char *p = dest;//看看这个指针到时是unsigned char * 还是 "unsignedchar (*)[100]
	unsigned char **pp = &p;//不能通过&&拿到二级指针，因为编译器中&&是与运算，而不是取两次的地址，

	printf("%p\n", p);


	read_all_data(&p);//必须得穿指针的指针，要不然传指针的变量，还是不能用函数 内部去改外部的值
	//值传递是不行的。
	printf("test29 %d ", dest[0]);
	printf("test29 %d ", dest[1]);
	printf("test29 %d ", dest[2]);

	printf("test29 %d ", p[0]);
	printf("test29 %d ", p[1]);
	printf("test29 %d ", p[2]);
	;

	cout << dest[0] << dest[1] << dest[2] << endl;
	//dest = &a;
	// 不能将 "char (*)[128]" 类型的值分配到 "const char *" 类型的实体

}



void test32(unsigned char** dest) {
	unsigned char a[100] = { 1,2,3 };
	memcpy(*dest, a, 3);
}

void test31(unsigned char* a) {
	test32(&a);
}


/*
测试：多级指针传递---单个变量
测试结果：可以在函数内部修改外部的值。
*/
void test30() {

	unsigned char dest[100] = { 0 };

	test31(&dest[0]);
	//read_all_data(&dest[0]);//必须得穿指针的指针，要不然传指针的变量，还是不能用函数 内部去改外部的值
	printf("%d\n", dest[0]);
	printf("%d\n", dest[1]);
	printf("%d\n", dest[2]);


}

/*
测试：if中有赋值的情况
结果：按照预想的来了
*/
void test31() {
	int a = 100;

	if ((a = 101) > 102)
	{
		cout << "a" << endl;
	}
	else
	{
		cout << "b" << endl;
	}

}

/*
测试：if中有赋值的情况下----a是有符号和无符号的情况下，和0的对比
结果：按照预想的来了
*/
void test32() {
	//unsigned int a = 100;//打印结果是b
	// int a = 100;//打印结果是a

	//char a = 100;//打印结果是a
	unsigned char a = 100;//打印结果是b

	//long a = 100;//打印结果是a
	//unsigned long a = 100;//打印结果是b

	//short a = 100;//打印结果是a
	//unsigned short a = 100;//打印结果是b

	if ((a = -1) < 0)//应该不会判断成功
	{
		cout << "a" << endl;
	}
	else
	{
		cout << "b" << endl;
	}
	unsigned char b = -1;
	printf("%u", b);//255!!
}

/*
测试：有符号int -1 赋值给有符号char 打印255，而不是128的问题
*/
void test33() {
	int a = -1;
	char b = a;
	printf("b= %d\n", b);//-1
	printf("b= %04x\n", b);

	char c = -1;
	printf("c= %04x\n", c);
	printf("c= %d\n", c);

	if ((b = a) < 0)
	{
		printf("b= %d\n", b);//-1
		printf("b= %04x\n", b);
	}

}


class class34
{
public:
	int comm_num = 0;		//某个表计下通讯帧总次数	不包括遥控
	int comm_err_num = 0;

private:

};

class34 a;


void  test34() {

	int comm_num = 0;		//某个表计下通讯帧总次数	不包括遥控
	int comm_err_num = 0;	//某个表计下错误通讯帧次数  不包括遥控


	comm_num++;

	cout << a.comm_num << endl;


}

//测试：memcpy的源不能是常量，有时候能，具体取决于系统
void  test35() {

	uint8_t temp_buf_shigu[128] = { 1 };
	cout << temp_buf_shigu[0] << endl;

	uint8_t temp_buf_shigu1[128] = { 0 };
	try
	{
		//memcpy(temp_buf_shigu, temp_buf_shigu1, 128);//！！！手动给保护恢复0---采集完事故之后，那么下一轮
		memset(temp_buf_shigu, 2, 128);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	printf("%d", temp_buf_shigu[0]);

}
//测试：sprintf
void  test36() {

	char temp_buf_shigu[128] = { 0 };
	try
	{

		sprintf(temp_buf_shigu, "%s", "aa_aaa");

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}


	printf("%s", temp_buf_shigu);


}

//测试：boost::filesystem:   修复了只能删除5的bug   这个地方有点乱  具体参考jzag中的文件吧
void  test37() {
	std::string path = "D:/c++demo/ConsoleApplication1/ConsoleApplication1/sdata";
	char szTmpPath[1024] = { 0 };
	int num = 0;



	boost::filesystem::directory_iterator endw;
	boost::filesystem::directory_iterator posw(path);
	boost::filesystem::directory_iterator posw1(path);
	//统计个数
	for (posw1; posw1 != endw; ++posw1)
	{
		if ((posw1->path().filename() == ".") || (posw1->path().filename() == ".."))
		{
			continue;
		}
		num++;

	}



	printf("文件的个数为！：%d\n", num);
	if (num >= 1)//先改成超过100
	{
		for (posw; posw != endw; ++posw)
		{
			if ((posw->path().filename() == ".") || (posw->path().filename() == ".."))
			{
				continue;
			}
			memset(szTmpPath, 0, sizeof(szTmpPath));

			cout << posw->path().filename() << endl;//拿到完整的文件名字
			printf("filename:%s\n", posw->path().filename().c_str());//打印 5
			printf("filename:%s\n", posw->path().filename().c_str() + 1);//打印 _
			printf("filename:%s\n", posw->path().filename().c_str() + 2);//打印 1

		//	sprintf(szTmpPath, "%s", (char*)(posw->path().filename().c_str()));//没有.string()；只能复制一个“5”！！
			//估计是和const boost::filesystem::path类型有关系；但是win下又可以用，估计也和编译器有关系

			sprintf(szTmpPath, "%s", (char*)(posw->path().filename().string().c_str()));//！！完全复制了文件名
			//memcpy(szTmpPath, (const char *)(posw->path().filename().string().c_str()), 1024);
			printf("szTmpPath:%s\n", szTmpPath);

			string new_path = posw->path().filename().string();
			printf("new_path:%s\n", new_path.c_str());//打印 完整
			cout << new_path << endl;//打印完整


			//删除【5】【6】【7】类型文件
			if ((szTmpPath[0] == '5') || (szTmpPath[0] == '6') || (szTmpPath[0] == '7'))
			{
				int ret = boost::filesystem::remove(path + "/" + szTmpPath);
				string cmd = "over1W remove " + path + "/" + szTmpPath + "\n";
				printf(cmd.c_str());
			}
		}
	}
}

//测试boost下的另外一种文件遍历

void test38() {
	char szTmpPath[1024] = { 0 };
	int num = 0;
	std::string targetPath = "D:/c++demo/ConsoleApplication1/ConsoleApplication1/sdata";

	boost::filesystem::path myPath(targetPath);
	boost::filesystem::directory_iterator endIter;
	for (boost::filesystem::directory_iterator iter(myPath); iter != endIter; iter++) {
		if (boost::filesystem::is_directory(*iter)) {
			cout << "is dir" << endl;
			cout << iter->path().string() << endl;
		}
		else {
			cout << "is a file" << endl;
			cout << iter->path().string() << endl;
			num++;

		}
	}

	printf("文件的个数为！：%d\n", num);


}


void test39() {

	char recv_buf[1] = { 0x80 };
	for (size_t i = 0; i < 8; i++)
	{
		printf("%d位：%# ", i, recv_buf[0] & 0x1000 >> i);//注意算数右移。
	}
}

//测试c++下 对"成员变量"的引用 不能引用
void test40() {



}


struct date_time
{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
};
//测试c++下 获取任意时间的时间戳
time_t getUnixTimeStampOfBeiJing(date_time& dt)
{
	auto isLeap = [](int _year)->bool { return (_year % 4 == 0) && (_year % 100 != 0) || (_year % 400 == 0); };
	int days = 0;
	for (int i = 1970; i < dt.year; ++i)
	{
		days += isLeap(i) ? 366 : 365;
	}
	for (int i = 1; i <= dt.mon; ++i)
	{
		if (dt.mon == 1)break;
		if (i == dt.mon)break;
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days += 30;
			break;
		case 2:
			days += isLeap(dt.year) ? 29 : 28;
			break;
		}
	}
	days += (dt.day - 1);
	return days * 24 * 60 * 60 + dt.hour * 60 * 60 + dt.min * 60 + dt.sec - 8 * 60 * 60;
}
void test41() {

	struct date_time soe_time;
	soe_time.year = 2021;
}

//C++ 将指定的标准时间转换成时间戳
int standard_to_stamp(const char *str_time)
{
	struct tm stm;
	int iY, iM, iD, iH, iMin, iS;

	memset(&stm, 0, sizeof(stm));
	iY = atoi(str_time);
	iM = atoi(str_time + 5);
	iD = atoi(str_time + 8);
	iH = atoi(str_time + 11);
	iMin = atoi(str_time + 14);
	iS = atoi(str_time + 17);

	stm.tm_year = iY - 1900;//2021-1900=121  //21+100
	stm.tm_mon = iM - 1;
	stm.tm_mday = iD;
	stm.tm_hour = iH;
	stm.tm_min = iMin;
	stm.tm_sec = iS;

	printf("%d-%0d-%0d %0d:%0d:%0d\n", iY, iM, iD, iH, iMin, iS);   //标准时间格式例如：2016:08:02 12:12:30
	return (int)mktime(&stm);
}

void test42()
{
	int stampTime = standard_to_stamp("2021:06:01 12:12:30");
	cout << stampTime << endl;

	return;
}


int standard_to_stamp1(char year, char month, char  day, char  hour, char  min, char  sec)
{
	struct tm stm;

	stm.tm_year = year + 100;
	stm.tm_mon = month - 1;
	stm.tm_mday = day;
	stm.tm_hour = hour;
	stm.tm_min = min;
	stm.tm_sec = sec;

	printf("%d-%0d-%0d %0d:%0d:%0d\n", year, month, day, hour, min, sec);   //标准时间格式例如：2016:08:02 12:12:30
	return (int)mktime(&stm);
}

void test43()
{
	//int stampTime = standard_to_stamp1("2021:06:01 12:12:30");
	int stampTime = standard_to_stamp1(21, 6, 1, 12, 12, 30);
	cout << stampTime << endl;

	return;
}

//测试：静态成员变量 跨文件是可以的
void test44()
{
	fun_2();

	cout << SHIKAI::shikai << endl;
	return;
}



/*
c++中使用sleep函数需要导入第三方库，"标准库"中没有该函数实现。

我们导入window.h使用Sleep()方法，注意：第一个S要大写，括号中的表示的整数倍的毫

正式因为标准库中没有引进 为了适应跨平台开发，所以需要BOOST这样的库，来实现同一份代码的跨平台开发

***
在C++ 11出现之前，C++没有提供睡眠函数，它提供了std::thread::sleep_for()。所以Boost提供了自己的代码，使你的代码独立于平台。

C函数sleep(),usleep()和Sleep()是平台特定的而不是C++标准库的一部分
*/

bool SliceEqual(unsigned char test_1[], unsigned char test_2[], int test_1_len, int test_2_len1)
{

	if (test_1_len != test_2_len1)
	{
		return false;
	}

	bool arraysEqual = true; // 标志变量
	int count = 0;
	//确定元素是否包含相同的数据
	while (arraysEqual && count < test_1_len)
	{

		printf("%u,  %u\n", test_1[count], test_2[count]);

		if (test_1[count] != test_2[count])
			arraysEqual = false;
		count++;
	}
	if (arraysEqual)
		return true;
	else
		return false;
}
//时间测试函数 测试时间差
void test45() {
	time_t time1 = 0;
	time_t time2 = 0;
	int time3 = 0;;
	time_t t1;


	time(&time1);//离1970的秒数 
	Sleep(2 * 1000);
	time(&time2);//离1970的秒数 

	time3 = time2 - time1;
	cout << "时间差" << time3 << endl;//打印结果 2

}

//测试SliceEqual函数
void test46() {
	//测试帧，U格式
	unsigned char test_frame[125] = { 1,2,0,4,5,6 };//后面的数  是随机的
	//测试帧应答，U格式
	unsigned char answ_frame[] = { 1,2,3,4,5,6 };

	int a = sizeof(test_frame);//125 拿到定长数组定长
	cout << a << endl;
	int b = sizeof(answ_frame);//6 拿到不定长数组的元素个数  
	cout << b << endl;
	int c = strlen((const char *)test_frame);//7 strlen 拿到定长数组的元素个数  strlen遇见元素为0就结束了   假设12045 测出来得到个数只有2
	cout << c << endl;
	int d = strlen((const char *)answ_frame);//23  应该是开辟内存的原因 不定长数组开辟内存是动态的是预留的(经过测试  这个大小不确定)
	cout << d << endl;

	//字符0的ascii是48 0和\0是一个
	char buf2[] = "hehe\nhe";
	cout << sizeof("hehe\0he") << endl;

	test_frame[2] = 10;
	if (SliceEqual(test_frame, answ_frame, strlen((const char *)test_frame), sizeof(answ_frame)))
	{
		cout << "The arrays are equal.\n";

	}
	else
	{
		cout << "The arrays are not equal.\n";
	}
}




//__DATE__ 的格式是 Mmm dd yyyy, 这个函数能把它转换成yyyymmdd, 如 "May 13 2010" 转成 "20100513"
const char * GetCompiledDate_yyyymmdd()
{
	static char _buf[9] = { 0 };
	if (_buf[0] == 0)
	{
		static const char * _month[] =
		{
			"Jan",
			"Feb",
			"Mar",
			"Apr",
			"May",
			"Jun",
			"Jul",
			"Aug",
			"Sep",
			"Oct",
			"Nov",
			"Dec",
		};
		const char * _date = __DATE__;
		memcpy(_buf, _date + 7, 4);
		memcpy(_buf + 6, _date + 4, 2);
		int month = 0;
		for (int i = 0; i < 12; i++)
		{
			if (memcmp(_month[i], _date, 3) == 0)
			{
				month = i + 1;
				break;
			}
		}
		_buf[4] = month / 10 % 10 + '0';
		_buf[5] = month % 10 + '0';
	}
	return _buf;
}


//拿到编译器的时间 和 c++版本
void test47() {


	printf("c++版本 %ld\n", __cplusplus);//199711
	/*
	C ++ 98：__cplusplus是199711L
	C ++ 11：__cplusplus是201103L
	C ++ 14：__cplusplus是201402L
	C ++ 17：__cplusplus是201703L
	*/

	printf("编译日期 %s\n", (char *)__DATE__);//ISO C99
	printf("编译日期 %s\n", GetCompiledDate_yyyymmdd());
	printf("编译日期 %s\n", __TIME__);// ISO C + +14
	printf("编译日期 %s\n", __TIMESTAMP__);//这个是VS预定义

	cout << __DATE__;
}



void test48() {

	static int loop = 1;//静态变量 只能被定义一次  所以再次循环到这的时候，就是赋值了；
	loop++;
	cout << loop;// 234567
}


void test49() {

	char* Cmd_buf = (char*)malloc(128);
	int i = 1;
	char* Cmd_buf1 = (char*)malloc(128);
	//Cmd_buf1 = "CMD Message.CMD" + itoa(i, Cmd_buf, 10);



	sprintf(Cmd_buf1, "CMD Message.CMD%s", itoa(1, Cmd_buf, 10));
	printf("%s\n", Cmd_buf1);

	sprintf(Cmd_buf1, "CMD Message.CMD%d", 1);
	printf("%s\n", Cmd_buf1);
	free(Cmd_buf);
	free(Cmd_buf1);

}

//测试移位
void test50() {
	uint64_t tigid = 0;
	uint64_t a = 0x1b6c;
	tigid = a << 8;//00
	printf("%llX\n%llu\n", tigid, tigid);

	tigid = a << 16;//00 00 
	printf("%llX\n%llu\n", tigid, tigid);

	tigid = a << 24;//00 00 00 
	printf("%llX\n%llu\n", tigid, tigid);

	tigid = a << 32;//00 00 00 00
	printf("%llX\n%llu\n", tigid, tigid);

	tigid = a << 40;
	printf("%llX\n%llu\n", tigid, tigid);

	tigid = a << 40;
	printf("%llX\n%llu\n", tigid, tigid);



}


/*

*/
int test51()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;

	printf("a=%d,b=%d,c=%d\n", a, b, c);
	return 0;
}
//getline测试
void test52()
{
	string line;
	cout << "please cin a line:";
	getline(cin, line, '#');
	cout << endl << "The line you give is:" << line;
}

//fprintf测试
void test53()
{

	char s[10];

	sprintf((char*)s, "%d%d%c", 10, 10, '2'); // s[0] = 0x31 0x30  s[1] = 0x31 0x30  s[2] = 0x32


	int a = 100;
	sprintf((char*)s, "%d%d%c", a, a, '2'); // s[0] = 0x31 0x30  s[1] = 0x31 0x30  s[2] = 0x32



	return;
}

//局部变量测试  s
void test54()
{
	//虽然a  test 在main函数中  但是 test中是读不到a这个变量的； 
	//无论是 静态还是普通函数

	//a = 10;

}


//测试 strcpy

void test55() {
	char text[3] = { 0 };
	cout << sizeof(text) << endl;
	char cmd[10] = { 0 };
	int a = 100;
	text[0] = 1;
	text[1] = 1;
	text[2] = 1;
	cmd[0] = text[0];
	cmd[0 + 1] = text[1];
	cmd[0 + 2] = text[2];
	//strcpy(cmd, text);
	/*
	上例说过strcpy()函数是多C风格的字符串进行拷贝，即遇‘\0’而停止拷贝，而本例中str1不是C风格的字符串，而是一个char数组，不是以'\0'结束的，
	所以strcpy()函数会一直进行拷贝直到遇到第一个'\0'才结束拷贝，所以string越界是必然的，因为我们不知道什么时候遇到'\0'。

	*/
}

void test56() {
	char text[4] = { 0 };//从3 到 4  ok  
	cout << sizeof(text) << endl;
	char cmd[10] = { 0 };
	int a = 100;
	text[0] = 1;
	text[1] = 1;
	text[2] = 1;
	strcpy(cmd, text);//
}

/* 测试long long  */
void test57()
{
	long long num1 = 123456789;//两者是通用的
	long long num2 = 123456789ll;
	long long num3 = 1;

	cout << num1 << "" << num2;

	assert(num3 > 1);//断言 一旦不符合条件 就退出Assertion failed: num3>1, file d:\c++demo\consoleapplication1\consoleapplication1\consoleapplication1.cpp, line 1609


}

void  test58()
{
	vector<int> t{ 1,2,3,4,5,6 };
	int a[11] = { 1,2,3,4,5,6,7,8 };

	for (int& value : a)//修改只能用引用的方式
	{
		value++;
	}

	for (int value : a)//他会遍历11次   但是a只会在第一次的时候引用了一次  如果是普通的for循环 则会每次循环之后都会判断是否越界
	{
		cout << value << " ";
	}


	cout << endl;

	int * p = new int{ 520 };

}

void test59()
{
	class  T2
	{
	public:
		int x;
		int y;
		T2(int, int) : x(10), y(20) {}
	};;
	T2 a{ 10,200 };
	//T2/
	cout << "a.x: " << a.x << ", a.y: " << a.y << endl;

}

// 自定义删除器函数，释放int型内存
void deleteIntPtr(int* p)
{
	delete p;
	cout << "int 型内存被释放了...";
}

/*智能指针*/
void test60()
{
	using func_ptr = void(*)(int*);
	unique_ptr<int, func_ptr> ptr1(new int(10), [](int*p) {delete p; });
	// unique_ptr<int, func_ptr> ptr1(new int(10), [](int*p) {delete p; });unique_ptr<int, function<void(int*)>> ptr1(new int(10), [&](int*p) {delete p; });



	//也就是说  他完全可以 当成普通的变量  get()方法 不仅p可以调用 *p也可以调用
	return;
}
/*测试 vector二维初始化 */
void test61() {

	vector <vector<string>> tb_ChoseMeterFile = vector <vector<string>>(10, vector<string>(10));

	tb_ChoseMeterFile.erase(tb_ChoseMeterFile.begin());//
}

/**/
void test62()
{
	const char* a = new (char);//cd fd fd   内存中 只有一个cd 也就是只有一个字节可以被用的内置 fd0xfd，其含义是：为堆分配内存前后, 微软C++ debugging 堆用该值标记"no man's land"哨兵位
	strcpy_s((char *)a, 2, "12");//strcpy_s

	delete a;
}


std::once_flag a1;

void test64()
{
	std::call_once(a1, []() { std::cout << "调用test64\n"; });
}
void test63()
{
	std::call_once(a1, test64);
	cout << "调用test63" << endl;
}

void test65(int a, int b)
{
	boost::optional<int> opt = 0;
	if (opt)
	{
		cout << "1 ----- " << *opt;
	}
	else
	{
		cout << "0";
	}
}



void test66()
{
	float a = 1;
	float b = 0;


	cout << a / b;
}

class Point
{
public:
	Point(int a, int b) {
		cout << "有参构造函数被调用了1" << endl;
		this->x = a;
		this->y = b;
	}
	Point(const Point& a1) {
		cout << "拷贝构造函数被调用了2" << endl;
		this->x = a1.x;
		this->y = a1.y;
	}

	~Point() {
		cout << "析构函数被调用了3" << endl;
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}

	Point Protset(int a) {
		this->x = a;
		return *this;
		//执行 return *this; 会产生一个匿名对象，作为返回值
		//强调：如果返回值是引用，则不会产生匿名对象
	}

	Point Protset2(int a) {
		Point temp(a, a);
		return temp;
		//执行 return temp;会先产生一个匿名对象,执行拷贝构造函数，作为返回值,
		//然后释放临时对象temp
	}

	//总结：函数返回值为一个对象（非引用）的时候会产生一个匿名对象，匿名对象根据主函数的操作决定生命周期

	Point& Protset3(int a) {
		Point temp(a, a);
		return temp;
		//执行 return temp;不会产生匿名对象，而是会将temp的地址先赋值到引用中，
		//在释放temp的内存，此时Point&得到是一个脏数据
	}

	void PrintfA()const {
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}


private:
	int x;
	int y;
};


void ProtectA() {
	//生成一个匿名对象，因为用来初始化另一个同类型的对象，这个匿名对象会直接转换成新的对象，
	//减少资源消耗
	Point p1 = Point(1, 1);
	/*Point p2(2, 2);
	p2 = p1.Protset(3);
	p2.PrintfA();*/
	//观察发现p2打印出正确数据,因此得出结论p1.Protset(3);返回来一个匿名对象，
	//但是这个匿名对象执行完"="之后，才会被释放
	Point p4(5, 5);
	p4 = p1.Protset2(4);
	p4.PrintfA();
}





/*测试迭代器因容器改变 导致迭代器失效问题*/
void test68()
{
	vector<int> va = { 1,2,3 ,4,5 };
	int b = 1;


#if 1
	for (auto a = va.begin(); a != va.end(); a++)
	{
		cout << " 文件列表 " << *a << endl;
		b++;
		if (b == 3)
		{
			for (size_t i = 0; i < 10; i++)
			{
				va.push_back(6);
			}
		}
	}
#endif // 0


#if 0
	for (size_t i = 0; i < va.size(); i++)
	{
		cout << " 文件列表 " << va[i] << endl;
		b++;
		if (b == 3)
		{
			for (size_t i = 0; i < 10; i++)
			{
				va.push_back(6);
			}
		}
	}
#endif // 1


}

/*测试迭代器因容器改变 导致迭代器失效问题*/
void vectorTest()
{
	vector<int> container;
	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	vector<int>::iterator iter;
	for (iter = container.begin(); iter != container.end(); iter++)//循环2
	{
		container.erase(iter);
	}



	for (iter = container.begin(); iter != container.end(); iter++)
	{
		cout << *iter << endl;
	}
}

//测试if中赋值 先执行赋值语句 然后在判断a
void test68()
{
	int a;
	scanf("%d", &a);
	if (!(a = 0)) {
		printf("if---%d\n", a);
	}
	else {
		printf("else---%d\n", a);
	}
	return;
}


/*类模板使用方式*/
template<typename T>
class TEST
{
public:
	TEST() = default;
	~TEST() = default;
	TEST(const TEST<int>& other)
	{
		a = other.a;
	}
	T a = 0;
};
void test70()
{
	TEST<float> t1;
	t1.a = 1.1;
	cout << t1.a << endl;

	TEST<float> t2 = t1;
	cout << t2.a << endl;

}

/*函数中定义类*/
void test71()
{
	class asdfasdf
	{
	public:
		int a;
		void set() {
			a = 2;
		}
	};

	asdfasdf a;
	a.a = 1;
}




/*测试类的相互引用*/
class test72C
{
public:
	int c;
private:

};

class test72B;
class test72A
{
public:
	int a;
	test72C* c;
	test72C c1;
	//test72C& c2;

	test72B *b;
	//test72B b1;
	void asdf();
	//test72B a11;//因为不知道test72B具体类型 只知道他是个类，所以定义非指针、非引用变量失败。
	//test72B* a1;//定义指针变量 成功！

	void df()
	{
		c->c;
		c1.c;
		b->b;
	}
};



class test72B
{
public:
	int b;
	test72A b1;

	test72B() {
		b1.a;
	}
	void tets() {
		b1.a;
	}
};

void test72A::asdf()
{
	c->c;
	c1.c;
	b->b;
}



/*测试 引用的时候  是否调用构造函数*/

class test72B
{
public:
	test72B()
	{
		cout << "test72B构造函数" << endl;
	}

	test72B(const test72B& other)
	{
		this->b = other.b;
		cout << "test72B拷贝构造" << endl;
	}
	~test72B()
	{
		cout << "test72B析构函数" << endl;
	}
	int b;
	
};


void test72()
{

	test72B b;
	test72B& b1 = b;

}

/*一个类的对象，作为一个类的成员变量---所引发的思考*/


class test73A
{
public:
	test73A()
	{
		cout << "test73A构造函数" << endl;
	}
	test73A(int a) :a(a)
	{
		cout << "test73A有参构造" << endl;
	}
	test73A(const test73A& other)
	{
		this->a = other.a;
		cout << "test73A拷贝构造" << endl;
	}
	~test73A()
	{
		cout << "test73A析构函数" << endl;
	}
	int a;

};
class test73B
{
public:
	test73B()
	{
		cout << "test73B构造函数" << endl;
	}
	test73B(int b) :b(b)
	{
		cout << "test73B有参构造" << endl;
	}
	test73B(const test73A& other)
	{
		this->b = other.a;
		cout << "test73B拷贝构造" << endl;
	}
	~test73B()
	{
		cout << "test73B析构函数" << endl;
	}
	test73A A;
	int b;

};


void test73() 
{
	test73A a;
	test73B b(a);
}



class test74A
{
public:
	test74A() :a(100)
	{
	}
	int a;

	virtual void testa()
	{
		cout << "a" << endl;
	}
};
class test74B:public test74A
{
public:
	test74B() :b(0), test74A()
	{
	
	}
	int b;
	
};



void test73()
{
	test74A* a;
	test74B b;
	a = &b;
	a->testa();

}
/*测试memcpy赋值，导致的字符倒叙问题*/
void test74()
{
	short v_uint32[4] = {0};
	char buf[4] = { 0x00,0x01,0x02,0x03 };
	memcpy(&v_uint32, buf, 4);
}

#endif // 0

void test75()
{
	boost::circular_buffer<unsigned char> cb(4);
	cb.push_back(1);
	cb.push_back(2);
	cb.push_back(3);
	cb.push_back(4);

	boost::format fmt("%d ");
	string str;
	for (size_t i = 0; i < cb.size(); i++)
	{
		cout << fmt %cb[i]<<endl;
		str += (fmt % cb[i]).str();
	}
	cout << str << endl;
}
int main() {

	test75();
	return 0;
}
 