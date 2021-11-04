# MFC-CourseDesign
大一上学期的C++课程设计，运用MFC实现可视化

# MFC入门：职工工作量统计系统（C++课设）


这是一个简单的C++课设，但是黑框框不好看，所以选择了MFC可视化编程，先贴一个题目。

```cpp
// 题目：职工工作量统计系统设计
// 1、问题描述
// 职工包括姓名、职工号、性别、年龄、所在部门、联系方式等信息。 工作量包括职工号、完成的产品数量等信息。 该设计系统能够对职工的工作量进行统计，并排出名次。注意，一个职工的工作量是可以多次输入的。
// 2、功能要求
// （1）添加功能：程序能够添加职工的记录和工作量，可提供选择界面供用户选择所要添加的类别， 要求职工的编号要唯一，如果添加了重复职工号的职工记录时，则提示数据添加重复并取消添加。
// （2）查询功能：可根据职工号、姓名等信息对已添加的职工记录进行查询。还可以按职工号对工 作量进行查询。如果未找到，给出相应的提示信息，如果找到，则显示相应的记录信息。 
// （3）显示功能：可显示当前系统中所有职工记录和工作量统计信息，每条记录占据一行。 
// （4）编辑功能：可根据查询结果对相应的记录进行修改，修改时注意编号的唯一性。 
// （5）删除功能：主要实现对已添加的人员记录进行删除和工作量进行删除。如果当前系统中没有 相应的人员记录，则提示“记录为空！”并返回操作；否则，输入要删除的人员的编号，根据所输入的 信息删除该人员记录，如果没有找到该人员信息，则提示相应的记录不存在。 
// （6）统计功能：对职工可按工作量进行统计，并排名次。 
// （7）保存功能：可将当前系统中各类人员记录存入文件中，存入方式任意。 
// （8）读取功能：可将保存在文件中的人员信息读入到当前系统中，供用户进行使用。
```
我的大致思路比较简单，就是用一个链表作为主体，各项功能通过对节点的操作实现。
首先，要准备VS+MFC的编译环境，在Visual Studio Installer中下载。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105104906590.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)创建一个新的MFC工程。![创建一个新的MFC工程](https://img-blog.csdnimg.cn/20210105105157958.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
在应用程序类型中选择基于对话框。![在应用程序类型中选择基于对话框](https://img-blog.csdnimg.cn/20210105105449982.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
资源视图->Dialog->添加资源。
![资源视图->Dialog->添加资源](https://img-blog.csdnimg.cn/20210105105852544.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
这样就新建了一个Dialog对话框。
![这样就新建了一个Dialog对话框](https://img-blog.csdnimg.cn/20210105110211988.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)单击对话框，可以设计对话框文字，双击对话框，可以设置对话框的类名，MFC工程会自动生成相应的头文件和可执行文件，命名时候要注意，对话框的名字就是他的ID，后面我们使用他时候就找他。
![对话框命名](https://img-blog.csdnimg.cn/20210105110659295.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)这里介绍三个比较常见的工具，Button->按钮，可以理解成超链接，连接各个窗口，Edit Control->编辑文本框，可以写入数据，传入程序，Static Text->静态文本框，用作提示。

![工具箱](https://img-blog.csdnimg.cn/20210105181508177.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)可以在右边属性里面更改文本框的ID，在其他窗口里面通过ID获取他的内容。
![修改ID](https://img-blog.csdnimg.cn/20210105181719486.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
双击按钮，可以添加对应的类。
![按钮类](https://img-blog.csdnimg.cn/20210105181859978.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
例如这里的登录窗口。![登录窗口](https://img-blog.csdnimg.cn/20210105182218735.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)双击登录键进去写对应的代码，注释如图。

```cpp
void CMFCApplication3Dlg::OnBnClickedButtonLgn()
void CMFCApplication3Dlg::OnBnClickedButtonLgn()
{
	// TODO: 在此添加控件通知处理程序代码
	CString nam, spwd;
	GetDlgItemText(IDC_EDIT_UNAME, nam);//通过文本框ID获取账号
	GetDlgItemText(IDC_EDIT_PWD, spwd);//通过文本框ID获取密码
	if (!nam.CompareNoCase(_T("yh")) && !spwd.CompareNoCase(_T("202012182")))//调用相应的函数忽略大小写比较
	{
		SystemDlg dlg;//dlg是弹窗的类名，需要包含
		dlg.DoModal();//使用DoModal函数弹出新窗口
	}
	else
	{
		MessageBox(_T("用户名或密码不正确"), _T("登录失败"));//调用小弹窗函数进行提示
	}
}

```

现在登录进来我们就逐一的实现相应的功能即可，先定义一个数据类，用来存储数据并开创建一个头节点。

```cpp
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Date
{
public:
	string name;           //职工姓名
	string ID;			   //职工ID
	int age; 			   //年龄
	string Department;	   //所在部门
	string Contact; 	   //联系方式
	int WorkHour;          //工作量 	
	Date* next; 	       //链表指针
};
Date* head;
```


这里会出现重复定义头节点的情况，而我们只需要一个应用于全局的头节点，所以要在属性里面加上一行命令用来忽略二次定义。
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021010518345694.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
下面是核心代码的解释：
1.文件保存，运用输入输出流进行文件保存，包含头文件<fstream>后定义一个ofstream的对象save，调用open函数以ios::out方式打开文件，如果文件不存在将会创建一个数据库的txt文件来保存信息，因为采用ios::out的方式，每次保存信息会覆盖之前的信息，避免了重复保存。保存方式是定义一个工作指针p，接收应用于全局的头指针head，遍历一遍链表通过重载运算符<<依次保存。保存成功后，调用close函数关闭文件，调用MFC的一个MessageBox函数进行一个保存成功的弹窗提示。

```cpp
void SystemDlg::OnBnClickedButton8()
{
	ofstream save;
	save.open("date.txt", ios::out);
	for (Date* p = head; p != NULL; p = p->next)
	{
		save << p->name << " "
			<< p->ID << " "
			<< p->age << " "
			<< p->Department << " "
			<< p->Contact << " "
			<< p->WorkHour << endl;
	}
	save.close();
	MessageBox(_T("保存成功!"), _T("提示"));
	// TODO: 在此添加控件通知处理程序代码
}
```
2.文件读取，运用输入输出流进行文件保存，包含头文件<fstream>后定义一个ifstream的对象read，调用open函数打开文件，调用is_open函数判断文件是否为空，如果文件不存在或者文件为空，将会调用MessageBox函数进行一个文件为空的弹窗提示；如果文件存在，则会通过while循环进行链表创建，其中定义一个工作指针node并为其开辟内存空间，通过read对象运用重载运算符>>初始化node的信息，然后判断node是头节点还是普通节点，循环创建，当node循环到文件末尾或者node里面的age为非正常值时候跳出循环。读入成功后，将会调用MessageBox函数进行一个读入成功的弹窗提示。创建链表的代码会再下一部分核心代码详细解释。

```cpp
void SystemDlg::OnBnClickedButton9()
{
	ifstream read;
	read.open("date.txt", ios::in);
	if (!read.is_open())
	{
		MessageBox(_T("文件为空!"), _T("提示"));
	}
	else
	{
		while (!read.eof())
		{
			Date* node;
			node = new Date;
			read >> node->name >> node->ID >> node->age >> node->Department
				 >> node->Contact >> node->WorkHour;
			if (node->age <= 0)break;
			if (head == NULL)
			{
				head = node;
				head->next = NULL;
			}
			else
			{
				Date* tail;
				tail = head;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				node->next = NULL;
				tail->next = node;
			}
		}
		MessageBox(_T("读入成功!"), _T("提示"));
	}
	read.close();
	// TODO: 在此添加控件通知处理程序代码
}
```
3.添加信息，定义CString类型的数个变量与Date里面的数据对应，调用GetDlgItemText函数用于接收输入框内的文本类型的数值（其中变量是输入框的ID和接收变量的变量名），再调用CW2A函数进行强制类型转换，将CString类型的变量通过GetString函数转换成string类型存入工作指针node，调用GetDlgItemInt函数将输入框中的数据类型的变量转换为int型存入工作指针node。当node指针已被成功定义，在添加信息之前创建一个工作指针进行链表遍历，对新添加信息和原有信息的ID进行比较，如果重复将会调用MessageBox函数进行一个请勿重复添加的添加失败的提示。如果没有重复，则会进入创建链表的函数，先判断node是否为头节点，如果是则插入头节点，然后使next置空形成尾节点；如果是普通节点，则开一个尾指针tail，通过尾指针的特性next为空循环查找尾节点，找到后使node的next置空形成新的尾节点，再将tail的指针指向新的尾节点。通过flag的值判断是否创建成功，创建成功后将会调用MessageBox函数进行一个添加成功的弹窗提示。

```cpp
void Add::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString NAME;              //职工姓名
	CString MID;			   //职工号
	CString AGE; 			   //年龄
	CString DEPARTMENT;	       //所在部门
	CString CONTACT; 	       //联系方式
	CString WORKHOUR;
	Date* node;
	node = new Date;
	GetDlgItemText(IDC_EDIT_name,NAME );
	GetDlgItemText(IDC_EDIT_ID, MID);
	GetDlgItemText(IDC_EDIT_Department,DEPARTMENT);
	GetDlgItemText(IDC_EDIT_Contact, CONTACT);
	string str1(CW2A(NAME.GetString()));
	string str2(CW2A(MID.GetString()));
	string str3(CW2A(AGE.GetString()));
	string str4(CW2A(DEPARTMENT.GetString()));
	string str5(CW2A(CONTACT.GetString()));
	node->name = str1;
	node->ID =str2;
	node->age = GetDlgItemInt(IDC_EDIT_Age);
	node->Department = str4;
	node->Contact = str5;
	node->WorkHour = GetDlgItemInt(IDC_EDIT_WorkHour);
	int flag = 0;
	for (Date* p = head; p != NULL; p = p->next)
	{
		if (node->ID == p->ID)
		{
			MessageBox(_T("请勿重复添加"), _T("添加失败"));
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		if (head == NULL)
		{
			head = node;
			head->next = NULL;
		}
		else
		{
			Date* tail;
			tail = head;
			while (tail->next != NULL)           //寻找尾节点
			{
				tail = tail->next;
			}
			node->next = NULL;				  //设置尾节点
			tail->next = node;				  //插入节点
		}
		MessageBox(_T("输入成功"), _T("提示"));
	}
	CDialogEx::OnOK();
}

```
4.删除信息，同样的思路获取输入框中的值，循环查找要删除的节点，依次判断节点类型，分头节点，普通节点，尾节点三类删除，通过flag的值判断是否删除成功，后调用MessageBox函数进行一个添加成功的弹窗提示。

```cpp
void Delete::OnBnClickedOk()
{
	Date* p1, * p2;
	p1 = head;
	p2 = p1->next;
	CString x;
	GetDlgItemText(IDC_EDIT_DEID, x);
	string wantid(CW2A(x.GetString()));
	int flag = 0;
	while (true)
	{
		if (p1->ID==wantid)break;
		p1 = p1->next;
		if (p1 == NULL)break;
	}
	if (p1 == head && p1->ID == wantid)
	{
		head = head->next;
		delete p1;
		flag++;
	}
	else if (p1 == NULL)
	{
		flag = 0;
	}
	else if (p1->next == NULL)
	{
		while (p2->next != p1)
		{
			p2 = p2->next;
		}
		p2->next = NULL;
		delete p1;
		flag++;
	}
	else
	{
		while (p2->next != p1)
		{
			p2 = p2->next;
		}
		p2->next = p1->next;
		delete p1;
		flag++;
	}
	if (flag == 0)
	{
		MessageBox(_T("删除失败，查无此人!"), _T("提示"));
	}
	else
	{
		MessageBox(_T("删除成功!"), _T("提示"));
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
```
5.排序算法，运用选择排序的思想，对链表进行选择排序，其中不改变链表的指向，只交换其数据，实现从小到大排序（因为后期显示运用MFC的链表函数会逆序输出，所以这里排序用了从小到大）。

```cpp
void SystemDlg::OnBnClickedButton3()
{
	Date* p = head;
	int flag = 0;
	for (; p->next != NULL; p = p->next)
	{
		Date* max = p;
		for (Date* j = p->next; j != NULL; j = j->next)
		{
			if (j->WorkHour < max->WorkHour)max = j;
		}
		swap(p->name, max->name);
		swap(p->ID, max->ID);
		swap(p->age, max->age);
		swap(p->Department, max->Department);
		swap(p->Contact, max->Contact);
		swap(p->WorkHour, max->WorkHour);
	}
	xianshi dlg5;
	dlg5.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
```
6.查询显示方式，设置一个指向父窗口的指针，用MFC内函数GetDlgItemtExt函数获取父窗口内输入框的值并将其转换成string类型，遍历链表进行比较，找到后运用之前设置过的列表，先用OnInitDialog对其进行初始化，然后调用InsertColumn函数进行输出，四个参数分别为列数，名称，行数，宽度。这里还是运用到了CString和string的相互转换。

```cpp
BOOL xianshi::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list2.InsertColumn(0, _T("姓名"), 0, 100);
	m_list2.InsertColumn(1, _T("职工号"), 0, 100);
	m_list2.InsertColumn(2, _T("年龄"), 0, 100);
	m_list2.InsertColumn(3, _T("部门"), 0, 100);
	m_list2.InsertColumn(4, _T("联系方式"), 0, 100);
	m_list2.InsertColumn(5, _T("工作量"), 0, 100);
	CString xm, zgh, bm, lxfs;
	CString gzl, nl;
	for (Date* node = head; node != NULL; node = node->next)
	{
		int i = 0;
		xm = node->name.c_str();
		zgh = node->ID.c_str();
		bm = node->Department.c_str();
		lxfs = node->Contact.c_str();
		gzl.Format(_T("%d"), node->WorkHour);
		nl.Format(_T("%d"), node->age);
		m_list2.InsertItem(i, xm);
		m_list2.SetItemText(i, 1, zgh);
		m_list2.SetItemText(i, 2, nl);
		m_list2.SetItemText(i, 3, bm);
		m_list2.SetItemText(i, 4, lxfs);
		m_list2.SetItemText(i, 5, gzl);
		i++;
	}
	return true;
}
```
下面是运行结果截图。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105184845947.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105184913443.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105184921342.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105184926262.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105184940386.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185014638.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185020738.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185030583.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185039616.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185046607.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/202101051850535.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185059801.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185106497.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021010518511571.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185125516.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185132529.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185140806.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210105185241442.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzUwMjE2Mjcw,size_16,color_FFFFFF,t_70)简单的入门小技巧，如有不当请指教。











