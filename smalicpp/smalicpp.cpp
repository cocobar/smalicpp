// smalicpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "smalicpp.h"
#include "JavaClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  更改错误代码以符合您的需要
			_tprintf(_T("错误:  MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  在此处为应用程序的行为编写代码。
			CJavaClass cJavaClass;
			//cJavaClass.AnalyzeClassSmali(CString(_T("F:\\out\\XTCBinding\\smali\\com\\xtc\\binding\\MainActivity.smali")));
			cJavaClass.AnalyzeClassSmali(CString(_T("E:\\Launcher\\HelloJavaCpp\\app\\build\\outputs\\apk\\debug\\app-debug\\smali\\com\\eebbk\\hellojavacpp\\MainActivity.smali")));

			cJavaClass.OutputCppFile();
			cJavaClass.OutputHeadFile();
			cJavaClass.OutputDependOnHeadFile();

			printf("结束，按回车退出\n");
			getchar();
		}
	}
	else
	{
		// TODO:  更改错误代码以符合您的需要
		_tprintf(_T("错误:  GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	// 测试提交
	// git push -u origin master

	return nRetCode;
}
